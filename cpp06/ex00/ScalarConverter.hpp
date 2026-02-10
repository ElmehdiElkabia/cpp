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

	static void convert(const std::string &input);
};

void convertfromchar(double v);
void convertfromint(double v);
void convertfromfloat(double v);
void convertfromdouble(double v);

bool ischar(const std::string &input);
bool isint(const std::string &input);
bool isfloat(const std::string &input);
bool isdouble(const std::string &input);

void printchar(double v);
void printint(double v);
void printfloat(double v);
void printdouble(double v);
#endif