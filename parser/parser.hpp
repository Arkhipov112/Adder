#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "../adder/adder.hpp"

class Parser final {
public:
	Parser() = delete;

	static BaseNumber read(std::istream& in);
	static void write(std::ostream& out, const std::string& buffer) noexcept;

private:
	// Возвращает строку без отступов слева и справа
	static std::string trim(const std::string& line) noexcept;

	// Заменяет разделительные символы на пробел
	static std::string split(const std::string& line, const std::string& delimiters) noexcept;

	// Возвращает вектор из отдельных значений
	static std::vector<std::string> parse(const std::string& line) noexcept;
};