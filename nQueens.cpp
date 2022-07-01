#include <cassert>
#include <iostream>
#include <vector>

#include "chessboard.h"

using namespace std;

int main()
{
	vector<short> elements_to_permute;
	vector<vector<short>> generated_permutations = { elements_to_permute };

	for (short i = 0; i < queens; i++)
		elements_to_permute.emplace_back(i);


	short c [queens] = {0};
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

			generated_permutations.emplace_back(elements_to_permute);

			c[i]++;
			i = 0;
		}
		else
		{
			c[i] = 0;
			i++;
		}
	}

	assert(generated_permutations.size() == static_cast<unsigned long long>(tgamma(queens + 1)));


	for (const auto& permutation : generated_permutations)
	{
		for (const auto& n : permutation)
			continue;
	}

	unsigned long long permutation_count = 1;
	auto arr = new int[permutation_count] {};

	while (permutation_count < 7)
	{
		const auto temp = new int [permutation_count + 1];
		memcpy(temp, arr, sizeof *arr);
		delete[] arr;
		arr = temp;
		permutation_count++;
	}


	delete[] arr;

	return 0;
}
