#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Constructor default is Call from class Animal\n";
}

Animal::Animal(const Animal &copy)
{
    *this = copy;
    std::cout << "Copy Constructor is Call from class Animal\n";
}

Animal &Animal::operator=(const Animal &copy)
{
    if (this != &copy)
        this->type = copy.type;
    std::cout << "Copy Assignment operator is Call from class Animal\n";
    return *this;
}

Animal::~Animal()
{
    std::cout << "Destructor is Call from class Animal\n";
}

std::string Animal::getType() const
{
    return this->type;
}
void Animal::set_type(std::string set_type)
{
    this->type = set_type;
}

