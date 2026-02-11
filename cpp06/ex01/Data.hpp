#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data
{
private:
	std::string text;
	int number;

public:
	Data();
	Data(std::string t, int n);
	Data(const Data &copy);
	Data &operator=(const Data &copy);
	~Data();

	int getInt() const;
	std::string getString() const;
};

#endif