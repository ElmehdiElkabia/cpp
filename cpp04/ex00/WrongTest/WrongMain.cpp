#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const WrongAnimal *meta = new WrongAnimal();
	std::cout << "\n";
	const WrongAnimal *i = new WrongCat();
	std::cout << "\n";

	std::cout << meta->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << "\n";
	i->makeSound(); //the WrongCat should output the WrongAnimal sound!
	std::cout << "\n";
	meta->makeSound(); //the WrongCat should output the WrongAnimal sound!
	std::cout << "\n";

	delete meta;
	std::cout << "\n";
	delete i;
}