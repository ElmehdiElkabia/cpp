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