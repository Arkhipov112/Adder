#pragma once
#include <string>

typedef std::pair<std::string, int> NumberPair;

struct NumberBase final {
public:
	NumberBase(std::string number_a, int base_a, std::string number_b, int base_b, int base_c);

	NumberPair getFirstNumber() const noexcept;
	NumberPair getSecondNumber() const noexcept;
	int getTargetBase() const noexcept;

private:
	// Проверяет, чтобы number содержало только буквы и цифры
	bool isValidNumber(const std::string& number) const noexcept;

	// Вектор пар <значение,>
	std::pair<std::string, int> number_1, number_2;
	int target;
};