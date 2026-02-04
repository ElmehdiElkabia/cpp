#ifndef SCARLARCONVERTER_HPP
#define SCARLARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter &operator=(const ScalarConverter &copy);
	~ScalarConverter();

	bool ischar(const std::string &input);
	bool isint(const std::string &input);
	bool isfloat(const std::string &input);
	bool isdouble(const std::string &input);
	bool isdouble(const std::string &input);
	bool ispseudoliteral(const std::string &input);

	void convertfromchar(char v);
	void convertfromint(int v);
	void convertfromfloat(float v);
	void convertfromdouble(double v);

	void printchar(double v);
	void printint(double v);
	void printfloat(double v);
	void printdouble(double v);

	static void convert(std::string &input);
};

#endif