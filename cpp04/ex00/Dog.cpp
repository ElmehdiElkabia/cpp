#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &dog)
{
    type = dog.type;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
    if (this != &dog)
        this->type = dog.type;
    std::cout << "Dog copy assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dogs don't neow" << std::endl;
}