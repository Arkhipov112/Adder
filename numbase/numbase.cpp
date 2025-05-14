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

	else if ((!is_valid_num()) || (!is_valid_num())) {
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



addition_param::addition_param(const number_with_base& nb_a, const number_with_base& nb_b, int target) : nb_a(nb_a), nb_b(nb_b), target(target) {
	if (((target < BASE_MIN) || (target > BASE_MAX))) {
		throw (std::invalid_argument("Target takes a value from 2 to 36"));
	}
}

number_with_base addition_param::get_number_with_base_a() const noexcept {
	return nb_a;
}

number_with_base addition_param::get_number_with_base_b() const noexcept {
	return nb_b;
}

int addition_param::get_target() const noexcept {
	return target;
}