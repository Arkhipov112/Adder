#include <stdexcept>

#include "parser.hpp"

namespace {
	// Проверяет, что каждый символ строки буква или цифра
	bool check(const std::string& line) {
		for (char symbol : line) {
			if ((symbol < '0' || symbol > '9') && (symbol < 'a' || symbol > 'z') && (symbol < 'A' || symbol > 'Z')) {
				return false;
			}
		}

		return true;
	}
}

BaseNumber Parser::read(std::istream& in) {
	BaseNumber result;

	std::vector<std::string> temp;

	std::string line;
	while (std::getline(in, line)) {
		// Разделительные символы ' ', ':', '"'
		for (const auto& i : parse(split(trim(line), " :\""))) {
			temp.push_back(i);
		}
	}

	if (temp.size() != 5) {
		throw (std::length_error("Does not match the type"));
	}

	result.base_a = std::stoi(temp[0]);
	result.number_a = temp[1];

	result.base_b = std::stoi(temp[2]);
	result.number_b = temp[3];

	result.base_c = std::stoi(temp[4]);

	if ((result.base_a < 0) || (result.base_b < 0) || (result.base_c < 0)) {
		throw (std::invalid_argument("Base cannot be negative"));
	}

	if (!check(result.number_a) || !check(result.number_b)) {
		throw (std::invalid_argument("Number must contain the characters (from 0 to 9) and (from a to z) and (from A to Z)"));
	}

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