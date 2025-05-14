#pragma once
#include <string>

typedef std::pair<std::string, int> numpair;

struct numbase final {
public:
	numbase(const numpair& np_a, const numpair& np_b, int target);

	numpair get_numpair_a() const noexcept;
	numpair get_numpair_b() const noexcept;
	int get_target() const noexcept;

private:
	bool is_valid_base(const numpair& np) const noexcept;
	bool is_valid_num(const numpair& np) const;

	numpair np_a, np_b;
	int target;
};