#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

class Form
{
private:
	const std::string name;
	bool issigned;
	const int signgrade;
	const int execgrade;

public:
	Form(const std::string name, int signgrade, int execgrade);
	Form(const Form &copy);
	Form &operator=(const Form &copy);
	~Form();

	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};

	std::string getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;

	void beSigned(const Bureaucrat &bureaucrat);


};

std::ostream &operator<<(std::ostream &os,const Form &obj);

#endif