#include "Animal.hpp"
#include "Cat.hpp"
#include"Dog.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "Cat type "<< j->getType() << " " << std::endl;
	std::cout << "Dog type " << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete(meta);
	delete(i);
	delete(j);
	return 0;
}