#pragma once
#include <iostream>
#include <vector>

constexpr unsigned short queens = 8;

class chessboard final
{
	unsigned short rows_ [queens] = {};

public:
	explicit chessboard(const std::vector<unsigned short>& vec)
	{
		for (unsigned short i = 0; i < queens; i++)
			rows_[i] = vec[i];
	}

	auto is_valid() const -> bool
	{
		for (unsigned short i = 0; i < queens; i++)
			for (unsigned short j= 0; j < queens; j++)
			{
				if (i == j)
					continue;

				if (abs(i - j) == abs(rows_[i] - rows_[j]))
					return false;
			}
		return true;
	}

	auto operator[](const short& index) -> unsigned short&
	{
		return rows_[index];
	}

	friend
	auto operator<<(std::ostream& os, const chessboard& board) -> const std::ostream&
	{
		for (const auto& pos : board.rows_)
		{
			std::string row;
			for (short j = 0; j < queens; j++)
				row += pos == j ? "1" : "0";
			std::cout << row << "\n";
		}
		std::cout << "\n";

		return os;
	}
};
