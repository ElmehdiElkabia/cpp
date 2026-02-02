#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &copy){(void)copy}
ScalarConverter &ScalarConverter::operator(const ScalarConverter &copy)
{
	(void)copy;
	return *this;
}
ScalarConverter::~ScalarConverter(){}