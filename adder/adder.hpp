#pragma once
#include <string>

#include "../numbase/numbase.hpp"

class adder final {
public:
	adder() = delete;
	static std::string add(const numbase& nb) noexcept;

private:
	static int to_dec(const std::string& num, int base) noexcept;
	static std::string to_str(int num, int base) noexcept;
};