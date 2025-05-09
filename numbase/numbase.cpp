#include <stdexcept>

#include "numbase.hpp"

namespace {
	const int BASE_MIN = 2;
	const int BASE_MAX = 36;
}

numbase::numbase(std::string num_a, int base_a, std::string num_b, int base_b, int base_c) 
: numpair_a(num_a, base_a), numpair_b(num_b, base_b), target(base_c) {
	if ((base_a < BASE_MIN || base_a > BASE_MAX) && (base_b < BASE_MIN || base_b > BASE_MAX)) {
		throw (std::invalid_argument("Base takes a value from 2 to 36"));
	}

	else if ((!is_valid_num(num_a)) || (!is_valid_num(num_b))) {
		throw (std::invalid_argument("Number can contain only letters and numbers"));
	}
}

numpair numbase::get_numpair_a() const noexcept {
	return numpair_a;
}

numpair numbase::get_numpair_b() const noexcept {
	return numpair_b;
}

int numbase::get_target() const noexcept {
	return target;
}

bool numbase::is_valid_num(const std::string& num) const noexcept {
	for (char c : num) {
		if ((c < '0' || c > '9') && (c < 'a' || c > 'z') && (c < 'A' || c > 'Z')) {
			return false;
		}
	}

	return true;
}