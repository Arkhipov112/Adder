#pragma once
#include "../addition_param/addition_param.hpp"

#include <iostream>
#include <string>
#include <vector>

class parser final {
public:
	parser() = delete;

	static addition_param read(std::istream& in);
	static void write(std::ostream& out, const std::string& buffer);

private:
	static std::vector<std::string> split(const std::string& line, const std::string& delims);
};