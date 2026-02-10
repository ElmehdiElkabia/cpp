#ifndef SCARLARCONVERTER_HPP
#define SCARLARCONVERTER_HPP

#include <iostream>
#include <cmath>
#include <limits>
#include <cstdlib>



class ScalarConverter
{
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter &operator=(const ScalarConverter &copy);
	~ScalarConverter();

	static bool ischar(const std::string &input);
	static bool isint(const std::string &input);
	static bool isfloat(const std::string &input);
	static bool isdouble(const std::string &input);

	static void convertfromchar(double v);
	static void convertfromint(double v);
	static void convertfromfloat(double v);
	static void convertfromdouble(double v);

	static void printchar(double v);
	static void printint(double v);
	static void printfloat(double v);
	static void printdouble(double v);

	static void convert(const std::string &input);
};

#endif