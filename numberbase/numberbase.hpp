#pragma once
#include <string>

namespace {
	const int BASE_MIN = 2;
	const int BASE_MAX = 36;
}

class number_with_base {
public:
	number_with_base();
	explicit number_with_base(const std::string& num, int base);
	
	std::string get_num() const noexcept;
	int get_base() const noexcept;

private:
	bool is_valid_base() const noexcept;
	bool is_valid_num() const;

	std::string num;

	// unsigned ?
	// unsigned base = -4294967280U; - присвоиться значени 16
	int base;
};