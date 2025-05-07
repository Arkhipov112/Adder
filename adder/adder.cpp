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
	if ((base_number.base_c < BASE_MIN) || (base_number.base_c > BASE_MAX)) {
		throw (std::invalid_argument("Base takes a value from 2 to 36"));
	}

	std::string result;

	int decimal_number_a = convertToDecimal(base_number.number_a, base_number.base_a);
	int decimal_number_b = convertToDecimal(base_number.number_b, base_number.base_b);

	result = convertToString(decimal_number_a + decimal_number_b, base_number.base_c);

	return result;
}

int Adder::convertToDecimal(const std::string& number, int base) {
	if ((base < BASE_MIN) || (base > BASE_MAX)) {
		throw (std::invalid_argument("Base takes a value from 2 to 36"));
	}

	size_t length = number.length();

	for (size_t i = 0; i < length; ++i) {
		if ((number[i] < '0' || number[i] > '9') && (number[i] < 'a' || number[i] > 'z') && (number[i] < 'A' || number[i] > 'Z')) {
			throw (std::invalid_argument("The Number must contain the characters (from 0 to 9) and (from a to z) and (from A to Z)"));
		}
	}

	int result = 0;

	for (size_t i = 0; i < length; ++i) {
		char digit = static_cast<char>(number[(length - 1) - i]);
		int value = std::isdigit(digit) ? (digit - '0') : (std::toupper(digit) - 'A' + 10);
		result += value * static_cast<int>(std::pow(base, i));
	}

	return result;
}

std::string Adder::convertToString(int number, int base) {
	if ((base < BASE_MIN) || (base > BASE_MAX)) {
		throw (std::invalid_argument("Base takes a value from 2 to 36"));
	}

	if (number < 0) {
		throw (std::invalid_argument("Number cannot be negative"));
	}

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