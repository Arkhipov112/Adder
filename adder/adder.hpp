#pragma once
#include "../addition_param/addition_param.hpp"

#include <string>

class adder final {
public:
	adder() = delete;
	static number_with_base add(const addition_param& ap);

private:
	static int to_dec(const number_with_base& nb);
	static std::string to_str(int num, int base);
};