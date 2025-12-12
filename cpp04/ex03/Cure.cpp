#include "Cure.hpp"

Cure::Cure() : AMateria()
{
	this->type = "Cure";
	std::cout << "Default constructor is Call from class Cure\n";
}

Cure::Cure(const Cure &copy) : AMateria(copy)
{
	this->type = copy.type;
	std::cout << "Copy Constructor is Call from class Cure\n";
}

Cure &Cure::operator=(const Cure &copy)
{
	if (this != &copy)
		this->type = copy.type;
	std::cout << "Copy Assignment Operator is Call from Cure\n";
	return *this;
}

Cure::~Cure()
{
	std::cout << "Destructor is Call from class Cure\n";
}

AMateria *Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

