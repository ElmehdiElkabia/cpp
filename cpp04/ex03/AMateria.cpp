#include "AMateria.hpp"

AMateria::AMateria() : type("Default_Type")
{
	std::cout << "Default constructor is Call from class AMateria\n";
}

AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout << "Constructor is Call from class AMateria\n";
}

AMateria::AMateria(const AMateria &copy)
{
	this->type = copy.type;
	std::cout << "Copy Constructor is Call from class AMateria\n";
}

AMateria &AMateria::operator=(const AMateria &copy)
{
	if (this != &copy)
		this->type = copy.type;
	std::cout << "Copy Assignment Operator is Call from AMateria\n";
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "Destructor is Call from class AMateria\n";
}

const std::string &AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}
