#pragma once
#include <iostream>

// ReSharper disable once CppInconsistentNaming
constexpr unsigned short Q = 8;

class chessboard final
{
	unsigned short rows_ [Q] = {};

public:
	explicit chessboard(const unsigned short source [Q])
	{
		for (unsigned short i = 0; i < Q; i++)
			rows_[i] = source[i];
	}

	auto is_valid() const -> bool
	{
		for (unsigned short i = 0; i < Q - 1; i++)
			for (unsigned short j = 0; j < Q; j++)
				if (i != j && abs(i - j) == abs(rows_[i] - rows_[j]))
					return false;
		return true;
	}

	auto operator[](const unsigned short& index) -> unsigned short&
	{
		return rows_[index];
	}

	friend
	auto operator<<(std::ostream& os, const chessboard& board) -> const std::ostream&
	{
		for (const auto& pos : board.rows_)
		{
			for (unsigned short j = 0; j < Q; j++)
				std::cout << (pos == j ? "1" : "0");
			std::cout << "\n";
		}
		std::cout << "\n";

		return os;
	}
};
