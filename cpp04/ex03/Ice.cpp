#include "Ice.hpp"

Ice::Ice()
{
	this->type = "ice";
	std::cout << "Default constructor is Call from class Ice\n";
}

Ice::Ice(const Ice &copy) : AMateria(copy)
{
	this->type = copy.type;
	std::cout << "Copy Constructor is Call from class Ice\n";
}

Ice &Ice::operator=(const Ice &copy)
{
	if (this != &copy)
		this->type = copy.type;
	std::cout << "Copy Assignment Operator is Call from Ice\n";
	return *this;
}

Ice::~Ice()
{
	std::cout << "Destructor is Call from class Ice\n";
}

void Ice::use(ICharacter &target)
{
	(void)target;
	std::cout << "* Shoots an ice bolt at " << this->type << std::endl;
}