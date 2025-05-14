#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "../numbase/numbase.hpp"

class parser final {
public:
	parser() = delete;

	static numbase read(std::istream& in);
	static void write(std::ostream& out, const std::string& buffer);

private:
	static std::vector<std::string> split(const std::string& line, const std::string& delims);
};