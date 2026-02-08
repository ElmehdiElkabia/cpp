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


void ScalarConverter::convert(const std::string &input)
{
	if (ScalarConverter::ischar(input))
		ScalarConverter::convertfromchar(input[0]);
	else if (ScalarConverter::isint(input))
	{
		int value  = std::stoi(input);
		ScalarConverter::convertfromint(value);
	}
	else if (ScalarConverter::isfloat(input))
	{
		float value = std::stof(input);
		ScalarConverter::convertfromfloat(value);
	}
	else if (ScalarConverter::isdouble(input))
	{
		double value = std::stod(input);
		ScalarConverter::convertfromdouble(value);
	}
	else
		std::cerr << "Error: Invalid input" << std::endl;
}

bool ScalarConverter::ischar(const std::string &input)
{
	unsigned char c = input[0];
	return (input.length() == 1 && !std::isdigit(c) &&
			std::isprint(c) &&
			c != '+' && c != '-');
}

bool ScalarConverter::isint(const std::string &input)
{
	if (input.empty())
		return false;

	size_t i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	if (input.length() == i)
		return false;
	for (; i < input.length(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(input[i])))
			return false;
	}
	return true;
}

bool ScalarConverter::isfloat(const std::string &input)
{
	if (input == "-inff" || input == "+inff" || input == "nanf")
		return true;

	if (input.empty())
		return false;

	size_t i = 0;
	bool found = false;
	if (input[i] == '+' || input[i] == '-')
		i++;
	if (input.length() - 1 <= i)
		return false;

	for (; i < input.length() - 1; i++)
	{
		if (input[i] == '.')
		{
			if (found)
				return false;
			found = true;
		}
		else if (!std::isdigit(static_cast<unsigned char>(input[i])))
			return false;
	}
	return found && input.back() == 'f';
}

bool ScalarConverter::isdouble(const std::string &input)
{
	if (input == "-inf" || input == "+inf" || input == "nan")
		return true;
	if (input.empty())
		return false;

	size_t i = 0;
	bool found = false;
	if (input[i] == '+' || input[i] == '-')
		i++;
	if (i >= input.length())
		return false;
	for (; input.length() < i; i++)
	{
		if (input[i] == '.')
		{
			if (found)
				return false;
			found = true;
		}
		else if (!std::isdigit(static_cast<unsigned char>(input[i])))
			return false;
	}
	return found;
}

void ScalarConverter::convertfromchar(char v)
{
	double d = static_cast<double>(v);

	ScalarConverter::printchar(d);
	ScalarConverter::printint(d);
	ScalarConverter::printfloat(d);
	ScalarConverter::printdouble(d);
}

void ScalarConverter::convertfromint(int v)
{
	double d = static_cast<double>(v);

	ScalarConverter::printchar(d);
	ScalarConverter::printint(d);
	ScalarConverter::printfloat(d);
	ScalarConverter::printdouble(d);
}

void ScalarConverter::convertfromfloat(float v)
{
	double d = static_cast<double>(v);

	ScalarConverter::printchar(d);
	ScalarConverter::printint(d);
	ScalarConverter::printfloat(d);
	ScalarConverter::printdouble(d);
}

void ScalarConverter::convertfromdouble(double v)
{

	ScalarConverter::printchar(v);
	ScalarConverter::printint(v);
	ScalarConverter::printfloat(v);
	ScalarConverter::printdouble(v);
}

void ScalarConverter::printchar(double v)
{
	if (std::isnan(v) || std::isinf(v))
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	if (v < 0 && v > 127)
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	else if (v < 32 || v == 127)
	{
		std::cout << "Non displayable" << std::endl;
		return;
	}
	std::cout << "char: " << "'" << static_cast<char>(v) << "'" << std::endl;
}

void ScalarConverter::printint(double v)
{
	if (std::isnan(v) || std::isinf(v))
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	if (v < std::numeric_limits<int>::min() || v > std::numeric_limits<int>::max())
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	std::cout << "int: " << static_cast<int>(v) << std::endl;
}

void ScalarConverter::printfloat(double v)
{
	if (std::isnan(v))
	{
		std::cout << "nanf" << std::endl;
		return;
	}
	if (std::isinf(v))
	{
		if (v > 0)
			std::cout << "+inff" << std::endl;
		else
			std::cout << "-inff" << std::endl;
		return;
	}
	if (v < -std::numeric_limits<float>::max() || v > std::numeric_limits<float>::max())
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	if (v - static_cast<int>(v) == 0)
		std::cout << "float: " << static_cast<int>(v) << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(v) << "f" << std::endl;
}

void ScalarConverter::printdouble(double v)
{
	if (std::isnan(v))
	{
		std::cout << "nan" << std::endl;
		return;
	}
	if (std::isinf(v))
	{
		if (v > 0)
			std::cout << "+inf" << std::endl;
		else
			std::cout << "-inf" << std::endl;
		return;
	}
	if (v < -std::numeric_limits<double>::max() || v > std::numeric_limits<double>::max())
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	if (v - static_cast<int>(v) == 0)
		std::cout << "double: " << static_cast<int>(v) << ".0" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(v) << std::endl;
}