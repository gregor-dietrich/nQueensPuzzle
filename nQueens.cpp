// ReSharper disable CppUnreachableCode
#include "chessboard.h"
#include <vector>

using namespace std;

auto get_solutions() -> std::vector<chessboard>
{
	vector<chessboard> solutions;

	if (Q < 4)
	{
		if (Q == 1)
		{
			uint8_t solution [1] = {0};
			solutions.emplace_back(solution);
		}
		return solutions;
	}
	
	uint8_t elements_to_permute [Q] = {};
	for (uint8_t i = 0; i < Q; i++)
		elements_to_permute[i] = i;
	
	uint8_t c [Q] = {0};
	uint8_t i = 0;
	while (i < Q)
	{
		if (c[i] < i)
		{
			const auto solution = chessboard(elements_to_permute);
			if (solution.is_valid())
				solutions.emplace_back(solution);

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

			c[i]++;
			i = 0;
		}
		else
		{
			c[i] = 0;
			i++;
		}
	}

	return solutions;
}

auto main() -> int
{
	const auto solutions = get_solutions();

	for (const auto& solution : solutions)
		cout << solution;
	cout << "Solutions found: " << solutions.size() << "\n";

	return 0;
}
