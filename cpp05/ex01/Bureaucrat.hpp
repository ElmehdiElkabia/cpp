#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Form.hpp"
#include <iostream>
#include <exception>

class Form;

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

	void signForm(Form &form); 

};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif
