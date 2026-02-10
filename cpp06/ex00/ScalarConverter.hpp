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

#endif