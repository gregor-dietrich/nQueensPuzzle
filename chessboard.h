#pragma once
#include <iostream>
#include <cstdint>

// ReSharper disable once CppInconsistentNaming
constexpr uint8_t Q = 8;

class chessboard final
{
	uint8_t rows_ [Q] = {};

public:
	explicit chessboard(const uint8_t source [Q])
	{
		for (uint8_t i = 0; i < Q; i++)
			rows_[i] = source[i];
	}

	auto is_valid() const -> bool
	{
		for (uint8_t i = 0; i < Q - 1; i++)
			for (uint8_t j = 0; j < Q; j++)
				if (i != j && abs(i - j) == abs(rows_[i] - rows_[j]))
					return false;
		return true;
	}

	auto operator[](const uint8_t& index) -> uint8_t&
	{
		return rows_[index];
	}

	friend
	auto operator<<(std::ostream& os, const chessboard& board) -> const std::ostream&
	{
		for (const auto& pos : board.rows_)
		{
			for (uint8_t j = 0; j < Q; j++)
				std::cout << (pos == j ? "1" : "0");
			std::cout << "\n";
		}
		std::cout << "\n";

		return os;
	}
};
