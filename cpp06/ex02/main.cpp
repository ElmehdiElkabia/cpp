#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <exception>

Base *generate(void)
{
	int i = std::rand() % 3;

	if (i == 0)
		return new A();
	else if (i == 1)
		return new B();
	else if (i == 2)
		return new C();
	return NULL;
}

void identify(Base *p)
{
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
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception &)
	{
	}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception &)
	{
	}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception &)
	{
	}
}

int main()
{
	std::srand(std::time(NULL));

	std::cout << "Generating random object..." << std::endl;
	Base *ptr = generate();

	// 3. Identify using the pointer function
	std::cout << "Identify (pointer):   ";
	identify(ptr);

	// 4. Identify using the reference function
	std::cout << "Identify (reference): ";
	identify(*ptr);

	delete ptr;

	return 0;
}