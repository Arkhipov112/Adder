#include "parser.hpp"

#include <sstream>
#include <stdexcept>

namespace {
	const int PARSED_LINE = 3;
}

addition_param parser::read(std::istream& in) {
	number_with_base a;
	number_with_base b;
	int base;

	std::vector<std::string> temp;

	int line_count = 0;

	std::string line;
	while (std::getline(in, line)) {
		std::vector<std::string> temp = split(line, " \t:\"");

		// Пропускать неверные строки +
		try {
			if (line_count < PARSED_LINE - 1) {
				line_count == 0 ? a = number_with_base(temp[1], std::stod(temp[0])) : b = number_with_base(temp[1], std::stod(temp[0]));
			}

			else if (line_count == PARSED_LINE - 1) {
				base = std::stod(temp[0]);
			}
		}

		catch (const std::exception& ex) {
			continue;
		}

		++line_count;
	}

	if (line_count != PARSED_LINE) {
		throw (std::invalid_argument("Does not match the type"));
	}

	return addition_param(a, b, base);
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