#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Default constructor called" << std::endl;
};

Animal::Animal(const Animal &animal)
{
    type = animal.type;
    std::cout << "Copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &animal)
{
    if (this != &animal)
        this->type = animal.type;
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}

void Animal::setType(std::string value)
{
    type = value;
}

void Animal::makeSound() const
{
    std::cout << "Animals have a sound" << std::endl;
}