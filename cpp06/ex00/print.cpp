#include "ScalarConverter.hpp"

void printchar(double v)
{

	if (std::isnan(v) || std::isinf(v))
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}
	if (v < 0 || v > 127)
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}
	else if (v < 32 || v == 127)
	{
		std::cout << "char: Non displayable" << std::endl;
		return;
	}
	std::cout << "char: " << "'" << static_cast<char>(v) << "'" << std::endl;
}

void printint(double v)
{
	if (std::isnan(v) || std::isinf(v))
	{
		std::cout << "int: impossible" << std::endl;
		return;
	}
	if (v < std::numeric_limits<int>::min() || v > std::numeric_limits<int>::max())
	{
		std::cout << "int: impossible" << std::endl;
		return;
	}
	std::cout << "int: " << static_cast<int>(v) << std::endl;
}

void printfloat(double v)
{
	if (std::isnan(v))
	{
		std::cout << "float: nanf" << std::endl;
		return;
	}
	if (std::isinf(v))
	{
		if (v > 0)
			std::cout << "float: +inff" << std::endl;
		else
			std::cout << "float: -inff" << std::endl;
		return;
	}
	if (v < -std::numeric_limits<float>::max() || v > std::numeric_limits<float>::max())
	{
		std::cout << "float: impossible" << std::endl;
		return;
	}
	if (v - static_cast<int>(v) == 0)
		std::cout << "float: " << static_cast<int>(v) << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(v) << "f" << std::endl;
}

void printdouble(double v)
{
	if (std::isnan(v))
	{
		std::cout << "double: nan" << std::endl;
		return;
	}
	if (std::isinf(v))
	{
		if (v > 0)
			std::cout << "double: +inf" << std::endl;
		else
			std::cout << "double: -inf" << std::endl;
		return;
	}
	if (v < -std::numeric_limits<double>::max() || v > std::numeric_limits<double>::max())
	{
		std::cout << "double: impossible" << std::endl;
		return;
	}
	if (v - static_cast<int>(v) == 0)
		std::cout << "double: " << static_cast<int>(v) << ".0" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(v) << std::endl;
}