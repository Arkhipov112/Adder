#include <algorithm>
#include <cmath>

#include "adder.hpp"

std::string adder::add(const numbase& nb) {
	std::string res;

	int dec_num_a = to_dec(nb.get_numpair_a().first, nb.get_numpair_a().second);
	int dec_num_b = to_dec(nb.get_numpair_b().first, nb.get_numpair_b().second);

	res = to_str(dec_num_a + dec_num_b, nb.get_target());

	return res;
}

int adder::to_dec(const std::string& num, int base) {
	int res = 0;
	
	size_t len = num.length();
	for (size_t i = 0; i < len; ++i) {
		char digit = static_cast<char>(num[(len - 1) - i]);
		int val = std::isdigit(digit) ? (digit - '0') : (std::toupper(digit) - 'A' + 10);
		
		res += val * static_cast<int>(std::pow(base, i));
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