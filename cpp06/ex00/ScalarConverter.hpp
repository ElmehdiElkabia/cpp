#ifndef SCARLARCONVERTER_HPP
#define SCARLARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
private:
	std::string exp;
	// char c;
	int i;
	float f;
	double d;
public:
	static void convert(std::string exp);
};

#endif