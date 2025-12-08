#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "Constructor default is Call from class WrongAnimal\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    *this = copy;
    std::cout << "Copy Constructor is Call from class WrongAnimal\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
    if (this != &copy)
        this->type = copy.type;
    std::cout << "Copy Assignment operator is Call from class WrongAnimal\n";
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Destructor is Call from class WrongAnimal\n";
}

std::string WrongAnimal::getType() const
{
    return this->type;
}
void WrongAnimal::set_type(std::string set_type)
{
    this->type = set_type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimals have a Sound\n" ;
}