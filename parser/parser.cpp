#include <stdexcept>

#include "parser.hpp"

namespace {
	const int NumberParsedData = 5;
}

NumberBase Parser::read(std::istream& in) {
	std::vector<std::string> temp;

	std::string line;
	while (std::getline(in, line)) {
		// Разделительные символы ' ', ':', '"'
		for (const auto& i : parse(split(trim(line), " :\""))) {
			temp.push_back(i);
		}
	}

	if (temp.size() != NumberParsedData) {
		throw (std::length_error("Does not match the type"));
	}

	NumberBase result(temp[1], std::stoi(temp[0]), temp[3], std::stoi(temp[2]), std::stoi(temp[4]));
	return result;
}

void Parser::write(std::ostream& out, const std::string& buffer) noexcept {
	out << (": \"" + buffer + "\"");
}

std::string Parser::trim(const std::string& line) noexcept {
	std::string result;

	// Пропускаем символы ' ' и '\t'
	std::string whitespace{ " \t" };

	size_t first = line.find_first_not_of(whitespace);
	if (first == std::string::npos) {
		return result;
	}

	size_t last = line.find_last_not_of(whitespace);

	result = line.substr(first, (last - first) + 1);

	return result;
}

std::string Parser::split(const std::string& line, const std::string& delimiters) noexcept {
	std::string result;

	bool need_space = false;
	for (char symbol : line) {
		if (delimiters.find(symbol) != std::string::npos) {
			need_space = true;
		}

		else {
			if (need_space) {
				result += ' ';
				need_space = false;
			}

			result += symbol;
		}
	}

	return result;
}

std::vector<std::string> Parser::parse(const std::string& line) noexcept {
	std::vector<std::string> result;

	size_t first = 0;
	// Парсим значения, которые отделены ' '
	size_t last = line.find(' ');

	while (last != std::string::npos) {
		result.push_back(line.substr(first, last - first));
		first = last + 1;
		last = line.find(' ', first);
	}
	result.push_back(line.substr(first));

	return result;
}