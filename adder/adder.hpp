#pragma once
#include <string>

struct BaseNumber final {
	BaseNumber() noexcept : base_a(0), base_b(0), base_c(0) {}

	int base_a, base_b, base_c;
	std::string number_a, number_b;
};

class Adder final {
public:
	Adder() = delete;

	static std::string add(const BaseNumber& base_number);

private:
	// Конвертирует число number, записанное в системе base, в десятичную систему
	static int convertToDecimal(const std::string& number, int base);

	// Конвертирует число number в систему base
	static std::string convertToString(int number, int base);
};