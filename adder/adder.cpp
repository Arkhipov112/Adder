#include <algorithm>
#include <cctype>
#include <cmath>
#include <stdexcept>

#include "adder.hpp"

namespace {
	const int BASE_MIN = 2;
	const int BASE_MAX = 36;
}

// Adder

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

// NumberBase

NumberBase::NumberBase(std::string number_a, int base_a, std::string number_b, int base_b, int base_c) 
: number_1(number_a, base_a), number_2(number_b, base_b), target(base_c) {
	if ((base_a < BASE_MIN || base_a > BASE_MAX) && (base_b < BASE_MIN || base_b > BASE_MAX)) {
		throw (std::invalid_argument("The base takes a value from 2 to 36"));
	}

	else if (!isValidNumber(number_a) || !isValidNumber(number_b)) {
		throw (std::invalid_argument("The value can contain only letters and numbers"));
	}
}

std::pair<std::string, int> NumberBase::getFirstNumber() const noexcept {
	return number_1;
}

std::pair<std::string, int> NumberBase::getSecondNumber() const noexcept {
	return number_2;
}

int NumberBase::getTargetBase() const noexcept {
	return target;
}

bool NumberBase::isValidNumber(const std::string& number) const noexcept {
	for (char i : number) {
		if ((i < '0' || i > '9') && (i < 'a' || i > 'z') && (i < 'A' || i > 'Z')) {
			return false;
		}
	}

	return true;
}