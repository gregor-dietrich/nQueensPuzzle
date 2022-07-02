#pragma once
#include <iostream>
#include <vector>

constexpr unsigned short queens = 8;

using chessboard = class chessboard final
{
	short rows_ [queens] = {};

public:
	chessboard()
	{
		for (auto& pos : rows_) pos = -1;
	}

	explicit chessboard(const std::vector<short>& vec)
	{
		for (unsigned short i = 0; i < queens; i++)
			rows_[i] = vec[i];
	}

	auto contains(const short& pos) const -> bool
	{
		for (const auto& row : rows_)  // NOLINT(readability-use-anyofallof)
			if (row == pos) return true;
		return false;
	}

	auto no_conflicts() const -> bool
	{
		for (unsigned short i = 0; i < queens; i++)
		{
			if (rows_[i] == -1)
				break;

			for (unsigned short j= 0; j < queens; j++)
			{
				if (i == j)
					continue;

				if (abs(i - j) == abs(rows_[i] - rows_[j]))
					return false;
			}
		}

		return true;
	}

	auto is_valid() const -> bool
	{
		return no_conflicts() && !contains(-1);
	}

	auto operator[](const short& index) -> short&
	{
		if (index < 0 && index >= queens * -1)
			return rows_[index + queens];

		if (index < queens && index >= 0)
			return rows_[index];

		throw std::invalid_argument("chessboard index out of bounds!");
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
