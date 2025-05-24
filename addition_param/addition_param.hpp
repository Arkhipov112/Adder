#pragma once
#include "../number_base/number_base.hpp"

class addition_param final {
public:
	explicit addition_param(const number_with_base& nb_a, const number_with_base& nb_b, int to_base);

	number_with_base get_number_with_base_a() const noexcept;
	number_with_base get_number_with_base_b() const noexcept;
	int get_to_base() const noexcept;

private:
	number_with_base a, b;
	int to_base;
};