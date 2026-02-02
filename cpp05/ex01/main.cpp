#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "\033[32m--- TEST 1: ---\033[0m" << std::endl;
	try
	{
		Form tax("Tax Form", 50, 100);
		Bureaucrat bureaucrat("Elmehdi", 1);

		std::cout << "Created: " << tax << std::endl;
		std::cout << "Created: " << bureaucrat << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\033[1;31mException : " << e.what() << "\033[0m" << std::endl;
	}

	try
	{
		Form impossible("Impossible", 0, 100);

		std::cout << "Created: " << impossible << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\033[31mException : " << e.what() << "\033[0m" << std::endl;
	}

	std::cout << std::endl
			  << "\033[32m--- TEST 2: ---\033[0m" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 5);
		Form contract("Employment Contract", 20, 50);

		std::cout << "Created: " << boss << std::endl;
		std::cout << "Created: " << contract << std::endl;

		boss.signForm(contract);

	}
	catch (std::exception &e)
	{
		std::cout << "\033[31mException : " << e.what() << "\033[0m" << std::endl;
	}

	std::cout << std::endl
			  << "\033[32m--- TEST 3: ---\033[0m" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 100);

		Form topSecret("Top Secret Doc", 50, 150);

		intern.signForm(topSecret);
	}
	catch (std::exception &e)
	{
		std::cout << "\033[31mException : " << e.what() << "\033[0m" << std::endl;
	}

	return 0;
}