#include <algorithm>
#include <cctype>
#include <cmath>
#include <stdexcept>

#include "adder.hpp"

std::string Adder::add(const NumberBase& base_number) noexcept {
	std::string result;

	int decimal_number_a = convertToDecimal(base_number.getFirstNumber().first, base_number.getFirstNumber().second);
	int decimal_number_b = convertToDecimal(base_number.getSecondNumber().first, base_number.getSecondNumber().second);

	result = convertToString(decimal_number_a + decimal_number_b, base_number.getTargetBase());

	return result;
}

int Adder::convertToDecimal(const std::string& number, int base) noexcept {
	int result = 0;
	
	size_t length = number.length();
	for (size_t i = 0; i < length; ++i) {
		char digit = static_cast<char>(number[(length - 1) - i]);
		int value = std::isdigit(digit) ? (digit - '0') : (std::toupper(digit) - 'A' + 10);
		result += value * static_cast<int>(std::pow(base, i));
	}

	return result;
}

std::string Adder::convertToString(int number, int base) noexcept {
	std::string result;

	while (number > 0) {
		int remains = number % base;

		if (remains < 10) {
			result += remains + '0';
		}

		else {
			result += remains + 'A' - 10;
		}

		number /= base;
	}

	std::reverse(result.begin(), result.end());

	return result;
}