#include <sstream>
#include <stdexcept>

#include "parser.hpp"

namespace {
	const int PARSED_COUNT = 5;
}

numbase parser::read(std::istream& in) {
	std::vector<std::string> temp;

	std::string line;
	while (std::getline(in, line)) {
		for (const auto& i : split(line, " \t:\"")) {
			temp.push_back(i);
		}
	}

	if (temp.size() != PARSED_COUNT) {
		throw (std::length_error("Does not match the type"));
	}

	numbase res(temp[1], std::stoi(temp[0]), temp[3], std::stoi(temp[2]), std::stoi(temp[4]));
	return res;
}

void parser::write(std::ostream& out, const std::string& buffer) {
	for (char c : buffer) {
		if ((c < '0' || c > '9') && (c < 'a' || c > 'z') && (c < 'A' || c > 'Z')) {
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