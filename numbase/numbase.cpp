#include <stdexcept>

#include "numbase.hpp"

namespace {
	const int BASE_MIN = 2;
	const int BASE_MAX = 36;
}

numbase::numbase(const numpair& np_a, const numpair& np_b, int target) : np_a(np_a), np_b(np_b), target(target) {
	if ((!is_valid_base(np_a)) || (!is_valid_base(np_b)) || ((target < BASE_MIN) || (target > BASE_MAX))) {
		throw (std::invalid_argument("Base takes a value from 2 to 36"));
	}

	else if ((!is_valid_num(np_a)) || (!is_valid_num(np_b))) {
		throw (std::invalid_argument("Number or base is incorrect"));
	}
}

numpair numbase::get_numpair_a() const noexcept {
	return np_a;
}

numpair numbase::get_numpair_b() const noexcept {
	return np_b;
}

int numbase::get_target() const noexcept {
	return target;
}

bool numbase::is_valid_base(const numpair& np) const noexcept {
	if ((np.second < BASE_MIN) || (np.second > BASE_MAX)) {
		return false;
	}

	return true;
}

bool numbase::is_valid_num(const numpair& np) const {
	for (char c : np.first) {
		int val;

		if (isdigit(c)) { val = c - '0'; }

		else if (isupper(c)) { val = 10 + (c - 'A'); }

		else if (islower(c)) { val = 10 + (c - 'a'); }

		else { return false; }
	
		if (val >= np.second) {
			return false;
		}
	}

	return true;
}