#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void)copy;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void)copy;
	return *this;
}
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::ischar(const std::string &input)
{
	if (input.size() == 1 &&
		!std::isdigit(input[0]) &&
		std::isprint(input[0]) &&
		input[0] != '+' &&
		input[0] != '-')
		return true;
	else
		false;
}

bool ScalarConverter::isint(const std::string &input)
{
	
}