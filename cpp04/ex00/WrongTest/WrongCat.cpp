#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "Constructor default is Call from class WrongCat\n";
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	*this = copy;
	std::cout << "Copy Constructor is Call from class WrongCat\n";
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	if (this != &copy)
	{
		this->type = copy.type;
		WrongAnimal::operator=(copy);
	}
	std::cout << "Copy Assignment Operator is Call from class WrongCat\n";
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor is Call from class WrongCat\n";
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCats don't bark\n";
}