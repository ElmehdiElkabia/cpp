#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "=== Polymorphism test ===" << std::endl;

	const Animal *dog = new Dog();
	std::cout << "\n";

	const Animal *cat = new Cat();
	std::cout << "\n";

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl << "\n";


	dog->makeSound();
	std::cout << "\n";

	cat->makeSound();
	std::cout << "\n";

	delete dog;
	std::cout << "\n";

	delete cat;

	std::cout << "\n=== Copy tests ===" << std::endl;

	Dog a;
	std::cout << "\n";

	Dog b(a);
	std::cout << "\n";

	Dog c;
	std::cout << "\n";

	c = b;
	std::cout << "\n";

	a.makeSound();
	std::cout << "\n";

	b.makeSound();
	std::cout << "\n";

	c.makeSound();
	std::cout << "\n";

	return 0;
}
