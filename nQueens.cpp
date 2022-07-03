// ReSharper disable CppUnreachableCode
#include "chessboard.h"

using namespace std;

auto main() -> int
{
	auto solutions = static_cast<chessboard*>(malloc(Q));
	uint64_t solution_count = 0;

	if (Q < 4)
	{
		if (Q == 1)
		{
			uint8_t arr [1] = {0};
			cout << chessboard(arr);
			solution_count++;
		}
		cout << "Solutions found: " << solution_count << "\n";
		return 0;
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
			{
				if (!solutions)
					return -1;
				solutions[solution_count] = solution;
				solution_count++;
				const auto temp = static_cast<chessboard*>(malloc((solution_count + 1) * Q));
				if (!temp)
					return -1;
				memcpy(temp, solutions, solution_count * Q);
				free(solutions);
				solutions = temp;
			}

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

	for (uint64_t index = 0; index < solution_count; index++)
		cout << solutions[index];
	cout << "Solutions found: " << solution_count << "\n";
	
	free(solutions);
	return 0;
}
