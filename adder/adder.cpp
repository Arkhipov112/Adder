#include "adder.hpp"

#include <algorithm>
#include <cmath>

number_with_base adder::add(const addition_param& ap) {
	int dec_num_a = to_dec(ap.get_number_with_base_a());
	int dec_num_b = to_dec(ap.get_number_with_base_b());

	number_with_base res (to_str(dec_num_a + dec_num_b, ap.get_to_base()), ap.get_to_base());

	return res;
}

int adder::to_dec(const number_with_base& nb) {
	int res = 0;
	
	size_t len = nb.get_num().length();
	for (size_t i = 0; i < len; ++i) {
		char digit = static_cast<char>(nb.get_num()[(len - 1) - i]);
		int val = std::isdigit(digit) ? (digit - '0') : (10 + (std::toupper(digit) - 'A'));
		
		res += val * static_cast<int>(std::pow(nb.get_base(), i));
	}

	return res;
}

std::string adder::to_str(int num, int base) {
	std::string res;

	while (num > 0) {
		int r = num % base;

		// Сделать проще +
		res += r + (r < 10 ? '0' : 'A' - 10);

		num /= base;
	}

	std::reverse(res.begin(), res.end());

	return res;
}