#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	this->_brain = new Brain();
	std::cout << "Constructor default is Call from class Cat\n";
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	this->type = copy.type;
	this->_brain = new Brain(*(copy._brain));
	std::cout << "Copy Constructor is Call from class Cat\n";
}

Cat &Cat::operator=(const Cat &copy)
{
	if (this != &copy)
	{
		Animal::operator=(copy);
		this->type = copy.type;
		delete _brain;
		this->_brain = new Brain(*copy._brain);
	}
	std::cout << "Copy Assignment Operator is Call from class Cat\n";
	return *this;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Destructor is Call from class Cat\n";
}

void Cat::makeSound() const
{
	std::cout << "Cats don't bark\n";
}