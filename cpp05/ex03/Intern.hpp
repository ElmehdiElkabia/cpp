#ifndef INTERN_HPP
#define INTERN_HPP

#include <istream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	// helper functions .the  outside class doesn't need to see
private:
	AForm *makeShrubbery(std::string target);
	AForm *makeRobotomy(std::string target);
	AForm *makePresidential(std::string target);

public:
	Intern();
	Intern(const Intern &copy);
	Intern &operator=(const Intern &copy);
	~Intern();

	class NameNotExist : public std::exception
	{
		virtual const char *what() const throw();
	};

	AForm *makeForm(std::string formName, std::string target);
};

#endif