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
	for (; input.length() < i; i++)
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

	for (; input.length() - 1 < i; i++)
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
	return found && input[i] == 'f';
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