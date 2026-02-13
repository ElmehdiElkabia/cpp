#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <exception>

Base *generate(void)
{
	std::srand(std::time(NULL));

	int random = std::rand() % 3;

	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else if (random == 2)
		return new C();
	return NULL;
}

void identify(Base *p)
{
	if (!p)
	{
		std::cout << "Null pointer" << std::endl;
		return;
	}

	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception &)
	{
	}

	try
	{
		B b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception &)
	{
	}

	try
	{
		C c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception &)
	{
	}

	std::cout << "Unknown type" << std::endl;
}

int main()
{

	std::cout << "Generating random object..." << std::endl;
	Base *ptr = generate();

	// Identify using the pointer function
	std::cout << "Identify (pointer):   ";
	identify(ptr);

	// Identify using the reference function
	std::cout << "Identify (reference): ";
	identify(*ptr);

	delete ptr;

	return 0;
}