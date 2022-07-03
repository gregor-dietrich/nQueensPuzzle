#pragma once
#include <iostream>
#include <cstdint>

using uint8 = uint8_t;
using uint64 = uint64_t;

// ReSharper disable once CppInconsistentNaming
constexpr uint8 Q = 8;

class chessboard final
{
	uint8 rows_ [Q] = {}; // sizeof(chessboard) equals Q

public:
	explicit chessboard(const uint8 source [Q])
	{
		for (uint8 i = 0; i < Q; i++)
			rows_[i] = source[i];
	}

	auto is_valid() const -> bool
	{
		for (uint8 i = 0; i < Q - 1; i++)
			for (uint8 j = 0; j < Q; j++)
				if (i != j && abs(i - j) == abs(rows_[i] - rows_[j]))
					return false; // index/row delta equals value/column delta
		return true;
	}

	auto operator[](const uint8& index) -> uint8&
	{
		return rows_[index];
	}

	friend
	auto operator<<(std::ostream& os, const chessboard& board) -> const std::ostream&
	{
		for (const auto& pos : board.rows_)
		{
			for (uint8 j = 0; j < Q; j++)
				std::cout << (pos == j ? "1" : "0");
			std::cout << "\n";
		}
		std::cout << "\n";

		return os;
	}
};
