#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal *meta = new Animal();
	std::cout << "\n";
	const Animal *j = new Dog();
	std::cout << "\n";
	const Animal *i = new Cat();
	std::cout << "\n";

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << "\n";
	i->makeSound(); // will output the cat sound!
	std::cout << "\n";
	j->makeSound();
	std::cout << "\n";
	meta->makeSound();
	std::cout << "\n";

	delete meta;
	std::cout << "\n";
	delete i;
	std::cout << "\n";
	delete j;

	std::cout << "\n=== Copy tests ===" << std::endl;

	Dog a;
	std::cout << "\n";
	Dog b(a); // copy constructor
	std::cout << "\n";
	Dog c;
	std::cout << "\n";
	c = b; // assignment operator

	// a.makeSound();
	// b.makeSound();
	// c.makeSound();
}