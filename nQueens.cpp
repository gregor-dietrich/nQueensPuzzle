#include "chessboard.h"
#include <vector>

using namespace std;

auto main() -> int
{
	vector<chessboard> solutions;
	
	unsigned short elements_to_permute [queens] = {};
	for (unsigned short i = 0; i < queens; i++)
		elements_to_permute[i] = i;
	
	unsigned short c [queens] = {0};
	unsigned short i = 0;
	while (i < queens)
	{
		if (c[i] < i)
		{
			if (i % 2 == 0)
			{
				const auto temp = elements_to_permute[0];
				elements_to_permute[0] = elements_to_permute[i];
				elements_to_permute[i] = temp;
			}
			else
			{
				const auto temp = elements_to_permute[c[i]];
				elements_to_permute[c[i]] = elements_to_permute[i];
				elements_to_permute[i] = temp;
			}

			auto solution = chessboard(elements_to_permute);
			if (solution.is_valid())
				solutions.emplace_back(solution);

			c[i]++;
			i = 0;
		}
		else
		{
			c[i] = 0;
			i++;
		}
	}

	for (const auto& solution : solutions)
		cout << solution;
	cout << "Solutions found: " << solutions.size() << "\n";

	return 0;
}