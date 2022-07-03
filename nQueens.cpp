// ReSharper disable CppUnreachableCode
#include "chessboard.h"

using namespace std;

auto main() -> int
{
	// allocate memory for an array that can hold exactly one solution
	auto solutions = static_cast<chessboard*>(malloc(Q));
	// last index variable
	uint64 solution_count = 0;

	// handle chessboard size being too small
	if (Q < 4)
	{
		if (Q == 1) // exactly 1 solution
		{
			uint8 arr [1] = {0};
			cout << chessboard(arr);
			solution_count++;
		} // else 0 solutions
		cout << "Solutions found: " << solution_count << "\n";
		return 0;
	}

	// create array containing all valid positions on chessboard
	uint8 elements_to_permute [Q] = {};
	for (uint8 i = 0; i < Q; i++)
		elements_to_permute[i] = i;

	// iterate over all possible permutations of valid positions
	uint8 c [Q] = {0};
	uint8 i = 0;
	while (i < Q)
	{
		if (c[i] < i)
		{
			// create chessboard object from current permutation, then test it
			const auto solution = chessboard(elements_to_permute);
			if (solution.is_valid())
			{
				if (!solutions)
					return -1; // in case malloc failed

				// add solution to solutions array
				solutions[solution_count] = solution;
				// increment last index variable
				solution_count++;

				// allocate memory for an array that can hold exactly one additional solution
				const auto temp = static_cast<chessboard*>(malloc((solution_count + 1) * Q));
				if (!temp)
					return -1; // in case malloc failed

				// copy all solutions from solutions to temp
				memcpy(temp, solutions, solution_count * Q);
				// deallocate memory used by old array
				free(solutions);
				// set solutions to point to new array
				solutions = temp;
			}

			if (i % 2 == 0) // i is even
			{
				// swap first element with ith element
				const auto temp = elements_to_permute[0];
				elements_to_permute[0] = elements_to_permute[i];
				elements_to_permute[i] = temp;
			}
			else // i is odd
			{
				// swap c[i]th element with ith element
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

	// display all valid solutions found and their total amount
	for (uint64 index = 0; index < solution_count; index++)
		cout << solutions[index];
	cout << "Solutions found: " << solution_count << "\n";

	// deallocate memory and exit program
	free(solutions);
	return 0;
}
