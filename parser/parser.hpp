#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "../numbase/numbase.hpp"

class parser final {
public:
	parser() = delete;

	static numbase read(std::istream& in);
	static void write(std::ostream& out, const std::string& buffer) noexcept;

private:
	static std::string trim(const std::string& line) noexcept;
	static std::string split(const std::string& line, const std::string& delims) noexcept;
	static std::vector<std::string> parse(const std::string& line) noexcept;
};