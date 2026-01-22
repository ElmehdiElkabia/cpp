#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat
{
private:
	std::string name;
	int grade;

public:
	Bureaucrat(std::string const name, int grade);
	~Bureaucrat();

	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};

	std::string getName() const;
	int getGrade() const;
	void increment();
	void decrement();

	void signForm(AForm &form); 

	void executeForm(AForm const &form) const;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif
