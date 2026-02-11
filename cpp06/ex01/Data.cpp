#include "Data.hpp"

Data::Data() : str("str"), number(0) {};

Data::Data(std::string t, int n) : str(t), number(n) {};

Data::Data(const Data &copy) : str(copy.str), number(copy.number) {};

Data &Data::operator=(const Data &copy)
{
	if (this != &copy)
	{
		this->str = copy.str;
		this->number = copy.number;
	}
	return *this;
}

Data::~Data() {}

int Data::getInt() const { return number; }

std::string Data::getString() const { return str; }