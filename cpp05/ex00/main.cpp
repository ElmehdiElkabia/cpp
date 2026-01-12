#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "\033[32m--- TEST 1: ---\033[0m" << std::endl;
	try
	{
		Bureaucrat elmehdi("elmehdi", 5);
		std::cout << elmehdi << std::endl;

		elmehdi.increment();
		std::cout << elmehdi << std::endl;

		elmehdi.decrement();
		std::cout << elmehdi << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\033[1;31mException : " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\033[32m--- TEST 2: ---\033[0m" << std::endl;
	try
	{
		Bureaucrat elkabia("Elkabia", 2);
		std::cout << elkabia << std::endl;

		elkabia.increment();
		std::cout << elkabia << std::endl;

		elkabia.increment();
	}
	catch (std::exception &e)
	{
		std::cout << "\033[1;31mException : " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\033[32m--- TEST 3: ---\033[0m" << std::endl;
	try
	{
		Bureaucrat ali("Ali", 149);
		std::cout << ali << std::endl;

		ali.decrement();
		std::cout << ali << std::endl;

		ali.decrement();
	}
	catch (std::exception &e)
	{
		std::cout << "\033[1;31mException : " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\033[32m--- TEST 4: ---\033[0m" << std::endl;
	try
	{
		Bureaucrat jad("Jad", 0);
	}
	catch (std::exception &e)
	{
		std::cout << "\033[1;31mException : " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\033[32m--- TEST 5: ---\033[0m" << std::endl;
	try
	{
		Bureaucrat amine("Amine", 200);
	}
	catch (std::exception &e)
	{
		std::cout << "\033[1;31mException : " << e.what() << "\033[0m" << std::endl;
	}

	return 0;
}