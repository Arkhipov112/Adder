#pragma once
#include <string>

#include "../numbase/numbase.hpp"

class adder final {
public:
	adder() = delete;
	static std::string add(const numbase& nb);

private:
	static int to_dec(const numpair& np);
	static std::string to_str(int num, int base);
};