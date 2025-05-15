#pragma once
#include <string>

// Разбить на файлы

class number_with_base {
public:
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

class addition_param final {
public:
	explicit addition_param(const number_with_base& nb_a, const number_with_base& nb_b, int to_base);

	number_with_base get_number_with_base_a() const noexcept;
	number_with_base get_number_with_base_b() const noexcept;
	int get_to_base() const noexcept;

private:
	// Другое название +
	number_with_base a, b;

	// Другое название +
	int to_base;
};