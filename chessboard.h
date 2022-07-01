#pragma once
#include <iostream>

constexpr short queens = 8;

using chessboard = class chessboard final
{
	short rows_ [queens] = {};

public:
	chessboard()
	{
		for (auto& pos : rows_) pos = -1;
	}

	auto contains(const short& pos) -> bool
	{
		for (const auto& row : rows_)  // NOLINT(readability-use-anyofallof)
			if (row == pos) return true;
		return false;
	}

	auto no_conflicts() -> bool
	{
		
		return true;
	}

	auto is_valid() -> bool
	{
		return no_conflicts() && !contains(-1);
	}

	auto add_queen(const short& pos) -> bool
	{
		if (contains(pos) || !contains(-1))
			return false;

		short row = -1;
		for (short i = 0; i < queens; i++)
			if (row == rows_[i])
			{
				row = i;
				break;
			}
		if (row < 0)
			return false;

		rows_[row] = pos;

		return no_conflicts();
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
