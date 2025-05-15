#include "numbase.hpp"

#include <stdexcept>

namespace {
	const int BASE_MIN = 2;
	const int BASE_MAX = 36;
}

number_with_base::number_with_base(const std::string& num, int base) : num(num), base(base) {
	if ((!is_valid_base()) || (!is_valid_base())) {
		throw (std::invalid_argument("Base takes a value from 2 to 36"));
	}

	if ((!is_valid_num()) || (!is_valid_num())) {
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
		int val;

		if (isdigit(c)) { val = c - '0'; }

		else if (isupper(c)) { val = 10 + (c - 'A'); }

		else if (islower(c)) { val = 10 + (c - 'a'); }

		else { return false; }
	
		if (val >= base) {
			return false;
		}
	}

	return true;
}



addition_param::addition_param(const number_with_base& a, const number_with_base& b, int to_base) 
: a(a), b(b), to_base(to_base) {
	if (((to_base < BASE_MIN) || (to_base > BASE_MAX))) {
		throw (std::invalid_argument("Target takes a value from 2 to 36"));
	}
}

number_with_base addition_param::get_number_with_base_a() const noexcept {
	return a;
}

number_with_base addition_param::get_number_with_base_b() const noexcept {
	return b;
}

int addition_param::get_to_base() const noexcept {
	return to_base;
}