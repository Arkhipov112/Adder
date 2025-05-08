#include <stdexcept>

#include "numberbase.hpp"

namespace {
	const int BASE_MIN = 2;
	const int BASE_MAX = 36;
}

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