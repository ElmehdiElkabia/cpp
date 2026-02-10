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

static bool ischar(const std::string &input)
{
	unsigned char c = input[0];
	return (input.length() == 1 && !std::isdigit(c) &&
			std::isprint(c) &&
			c != '+' && c != '-');
}

static bool isint(const std::string &input)
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

static bool isfloat(const std::string &input)
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
		if (input[i] == '.' || input[i] == 'e')
		{
			if (found)
				return false;
			found = true;
		}
		else if (!std::isdigit(static_cast<unsigned char>(input[i])))
			return false;
	}
	return found && input[i] == 'f';
}

static bool isdouble(const std::string &input)
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
	for (; i < input.length(); i++)
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

static void printchar(double v)
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

static void printint(double v)
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

static void printfloat(double v)
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

static void printdouble(double v)
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

static void convertfromchar(double v)
{
	printchar(v);
	printint(v);
	printfloat(v);
	printdouble(v);
}

static void convertfromint(double v)
{

	printchar(v);
	printint(v);
	printfloat(v);
	printdouble(v);
}

static void convertfromfloat(double v)
{

	printchar(v);
	printint(v);
	printfloat(v);
	printdouble(v);
}

static void convertfromdouble(double v)
{

	printchar(v);
	printint(v);
	printfloat(v);
	printdouble(v);
}

void ScalarConverter::convert(const std::string &input)
{
	if (ischar(input))
	{
		convertfromchar(static_cast<double>(input[0]));
		return;
	}

	char *end;
	double v = std::strtod(input.c_str(), &end);

	if ((std::string)end != "f" && *end != 0)
	{
		std::cerr << "Error: Invalid input" << std::endl;
		return;
	}

	if (isfloat(input))
		convertfromfloat(v);
	else if (isint(input) && v >= std::numeric_limits<int>::min() && v <= std::numeric_limits<int>::max())
		convertfromint(v);
	else if (isdouble(input) || isint(input))
		convertfromdouble(v);
}