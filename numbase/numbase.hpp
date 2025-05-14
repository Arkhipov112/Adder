#pragma once
#include <string>

class number_with_base {
public:
	explicit number_with_base(const std::string& num, int base);
	
	std::string get_num() const noexcept;
	int get_base() const noexcept;

private:
	bool is_valid_base() const noexcept;
	bool is_valid_num() const;

	std::string num;
	int base;
};

class addition_param final {
public:
	explicit addition_param(const number_with_base& nb_a, const number_with_base& nb_b, int target);

	number_with_base get_number_with_base_a() const noexcept;
	number_with_base get_number_with_base_b() const noexcept;
	int get_target() const noexcept;

private:
	number_with_base nb_a, nb_b;
	int target;
};