#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Constructor default is Call from class Brain\n";
}

Brain::Brain(const Brain &copy)
{
	*this = copy;
	std::cout << "Copy Constructor is Call from class Brain\n";
}

Brain &Brain::operator=(const Brain &copy)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
	std::cout << "Copy Assignment operator is Call from class Brain\n";
	return *this;
}

Brain::~Brain()
{
	std::cout << "Destructor is Call from brain\n";
}

