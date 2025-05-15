#include "additionparam.hpp"

#include <stdexcept>

addition_param::addition_param(const number_with_base& a, const number_with_base& b, int to_base) 
: a(a), b(b), to_base(to_base) {
	if (((to_base < BASE_MIN) || (to_base > BASE_MAX))) {
		throw (std::invalid_argument("Target takes a value from 2 to 36"));
	}
}

number_with_base addition_param::get_number_with_base_a() const noexcept {
	return a;
}

number_with_base addition_param::get_number_with_base_b() const noexcept {
	return b;
}

int addition_param::get_to_base() const noexcept {
	return to_base;
}