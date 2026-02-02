#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::srand(std::time(NULL));

	std::cout << "\n\033[32m--- TEST 1: ---\033[0m" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 137);
		ShrubberyCreationForm shrub("home");

		std::cout << shrub << std::endl;

		bob.executeForm(shrub);

		bob.signForm(shrub);

		bob.executeForm(shrub);
	}
	catch (std::exception &e)
	{
		std::cout << "\033[1;31mException : " << e.what() << "\033[0m" << std::endl;
	}

	std::cout << "\n\033[32m--- TEST 2: ---\033[0m" << std::endl;
	try
	{
		Bureaucrat doctor("Dr. House", 45); 
		RobotomyRequestForm robot("Bender");

		doctor.signForm(robot);

		std::cout << "Attempt 1: ";
		doctor.executeForm(robot);
		std::cout << "Attempt 2: ";
		doctor.executeForm(robot);
		std::cout << "Attempt 3: ";
		doctor.executeForm(robot);
		std::cout << "Attempt 4: ";
		doctor.executeForm(robot);
	}
	catch (std::exception &e)
	{
		std::cout << "\033[1;31mException : " << e.what() << "\033[0m" << std::endl;
	}

	std::cout << "\n\033[32m--- TEST 3: ---\033[0m" << std::endl;
	try
	{
		Bureaucrat king("King Arthur", 5);
		Bureaucrat peasant("Peasant", 100);
		PresidentialPardonForm pardon("Arthur Dent");

		
		peasant.signForm(pardon);

		
		king.signForm(pardon);

		std::cout << "--- Peasant trying to execute ---" << std::endl;
		peasant.executeForm(pardon);

		std::cout << "--- King trying to execute ---" << std::endl;
		king.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << "\033[1;31mException : " << e.what() << "\033[0m" << std::endl;
	}

	return 0;
}