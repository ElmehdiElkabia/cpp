#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	this->_brain = new Brain();
	std::cout << "Constructor default is Call from class Dog\n";
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	this->type = copy.type;
	this->_brain = new Brain(*(copy._brain));
	std::cout << "Copy Constructor is Call from class Dog\n";
}

Dog &Dog::operator=(const Dog &copy)
{
	if (this != &copy)
	{
		Animal::operator=(copy);
		this->type = copy.type;
		delete _brain;
		this->_brain = new Brain(*(copy._brain));
	}
	std::cout << "Copy Assignment Operator is Call from class Dog\n";
	return *this;
}

Dog::~Dog()
{
	std::cout << "Destructor is Call from class Dog\n";
	delete _brain;
}

void Dog::makeSound() const
{
	std::cout << "dogs don't meow\n";
}


