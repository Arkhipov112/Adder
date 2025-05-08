#pragma once
#include <string>

#include "../numberbase/numberbase.hpp"

class Adder final {
public:
	Adder() = delete;

	static std::string add(const NumberBase& base_number) noexcept;

private:
	// Конвертирует число number, записанное в системе base, в десятичную систему
	static int convertToDecimal(const std::string& number, int base) noexcept;

	// Конвертирует число number в систему base
	static std::string convertToString(int number, int base) noexcept;
};