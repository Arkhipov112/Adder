#include "parser.hpp"

#include <sstream>
#include <stdexcept>

namespace {
	const int PARSED_COUNT = 5;
}

addition_param parser::read(std::istream& in) {
	std::vector<std::string> temp;

	std::string line;
	while (std::getline(in, line)) {
		for (const auto& i : split(line, " \t:\"")) {
			temp.push_back(i);
		}
	}

	// Пропускать неверные строки
	if (temp.size() != PARSED_COUNT) {
		throw (std::length_error("Does not match the type"));
	}

	addition_param res(number_with_base(temp[1], std::stoi(temp[0])), number_with_base(temp[3], std::stoi(temp[2])), std::stoi(temp[4]));
	return res;
}

void parser::write(std::ostream& out, const std::string& buffer) {
	for (char c : buffer) {
		if (!std::isalpha(c) && !std::isdigit(c)) {
    		throw (std::invalid_argument("Buffer can contain only letters and numbers"));
		}
	}

	out << (": \"" + buffer + "\"");
}



std::vector<std::string> parser::split(const std::string& line, const std::string& delims) {
	std::vector<std::string> res;

	std::istringstream iss(line);
	std::string token;

	char c;
	while (iss.get(c)) {
		if (delims.find(c) != std::string::npos) {
			if (!token.empty()) {
				res.push_back(token);
				token.clear();
			}
		}

		else {
			token += c;
		}
	}

	if (!token.empty()) {
		res.push_back(token);
	}

	return res;
}