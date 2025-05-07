#include <algorithm>
#include <cctype>
#include <cmath>
#include <stdexcept>

#include "adder.hpp"

namespace {
	const int BASE_MIN{ 2 };
	const int BASE_MAX{ 36 };
}

std::string Adder::add(const BaseNumber& base_number) {
	if (((base_number.base_a < BASE_MIN) || (base_number.base_a > BASE_MAX)) && ((base_number.base_b < BASE_MIN) || (base_number.base_b > BASE_MAX)) && ((base_number.base_c < BASE_MIN) || (base_number.base_c > BASE_MAX))) {
		throw (std::invalid_argument("Base takes a value from 2 to 36"));
	}

	if (base_number.number_a.empty() || base_number.number_b.empty()) {
		throw (std::invalid_argument("The value is missing"));
	}

	std::string result;

	int decimal_number_a = convertToDecimal(base_number.number_a, base_number.base_a);
	int decimal_number_b = convertToDecimal(base_number.number_b, base_number.base_b);

	result = convertToString(decimal_number_a + decimal_number_b, base_number.base_c);

	return result;
}

int Adder::convertToDecimal(const std::string& number, int base) noexcept {
	int result;
	
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