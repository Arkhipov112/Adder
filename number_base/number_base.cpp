#include "number_base.hpp"

#include <stdexcept>

number_with_base::number_with_base() : base(0) {}

number_with_base::number_with_base(const std::string& num, int base) : num(num), base(base) {
	if (!is_valid_base()) {
		throw (std::invalid_argument("Base takes a value from 2 to 36"));
	}

	if (!is_valid_num()) {
		throw (std::invalid_argument("Number or base is incorrect"));
	}
}

std::string number_with_base::get_num() const noexcept {
	return num;
}

int number_with_base::get_base() const noexcept {
	return base;
}

bool number_with_base::is_valid_base() const noexcept {
	return !((base < BASE_MIN) || (base > BASE_MAX));
}

bool number_with_base::is_valid_num() const {
	for (char c : num) {
		c = toupper(c);
		int val;

		if (isdigit(c)) { val = c - '0'; }

		else if (isupper(c)) { val = 10 + (c - 'A'); }

		else { return false; }
	
		if (val >= base) {
			return false;
		}
	}

	return true;
}