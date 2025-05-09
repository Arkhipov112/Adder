#pragma once
#include <string>

typedef std::pair<std::string, int> numpair;

struct numbase final {
public:
	numbase(std::string num_a, int base_a, std::string num_b, int base_b, int base_c);
	numpair get_numpair_a() const noexcept;
	numpair get_numpair_b() const noexcept;
	int get_target() const noexcept;

private:
	bool is_valid_num(const std::string& num) const noexcept;

	numpair numpair_a, numpair_b;
	int target;
};