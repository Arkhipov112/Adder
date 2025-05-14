#include <algorithm>
#include <cmath>

#include "adder.hpp"

std::string adder::add(const numbase& nb) {
	std::string res;

	int dec_num_a = to_dec(nb.get_numpair_a());
	int dec_num_b = to_dec(nb.get_numpair_b());

	res = to_str(dec_num_a + dec_num_b, nb.get_target());

	return res;
}

int adder::to_dec(const numpair& np) {
	int res = 0;
	
	size_t len = np.first.length();
	for (size_t i = 0; i < len; ++i) {
		char digit = static_cast<char>(np.first[(len - 1) - i]);
		int val = std::isdigit(digit) ? (digit - '0') : (10 + (std::toupper(digit) - 'A'));
		
		res += val * static_cast<int>(std::pow(np.second, i));
	}

	return res;
}

std::string adder::to_str(int num, int base) {
	std::string res;

	while (num > 0) {
		int r = num % base;

		if (r < 10) {
			res += r + '0';
		}

		else {
			res += r + 'A' - 10;
		}

		num /= base;
	}

	std::reverse(res.begin(), res.end());

	return res;
}