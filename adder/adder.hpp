#pragma once
#include <array>
#include <string>

namespace {
	const int NUMBER_BASES = 3;
	const int NUMBER_VALUE = 2;
}

struct BaseNumber final {
public:
	BaseNumber(std::string number_a, int base_a, std::string number_b, int base_b, int base_c);

	std::array<int, NUMBER_BASES> getBases() const noexcept;
	std::array<std::string, NUMBER_VALUE> getNumbers() const noexcept;

private:
	// Проверяет, чтобы number содержало только буквы и цифры
	bool isValidNumber(const std::string& number) const noexcept;

	std::array<int, NUMBER_BASES> bases;
	std::array<std::string, NUMBER_VALUE> numbers;
};

class Adder final {
public:
	Adder() = delete;

	static std::string add(const BaseNumber& base_number) noexcept;

private:
	// Конвертирует число number, записанное в системе base, в десятичную систему
	static int convertToDecimal(const std::string& number, int base) noexcept;

	// Конвертирует число number в систему base
	static std::string convertToString(int number, int base) noexcept;
};