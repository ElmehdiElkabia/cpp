#include "Intern.hpp"

Intern::Intern() {};

Intern::Intern(const Intern &copy)
{
	(void)copy;
}

Intern &Intern::operator=(const Intern &copy)
{
	(void)copy;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Destructor from Class Intern is Call" << std::endl;
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(Intern::*fc[3])(std::string) = {&Intern::makeShrubbery,
											&Intern::makeRobotomy,
											&Intern::makePresidential};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;

			return ((this->*fc[i])(target));
		}
	}
	std::cout << "Intern cannot create " << formName << " because it doesn't exist." << std::endl;
	return NULL;
}

AForm *Intern::makeShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidential(std::string target)
{
	return new PresidentialPardonForm(target);
}