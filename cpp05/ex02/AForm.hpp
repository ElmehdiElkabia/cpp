#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;
#include <iostream>
#include <exception>

class AForm
{
private:
	const std::string name;
	bool issigned;
	const int signgrade;
	const int execgrade;

public:
	AForm(const std::string name, int signgrade, int execgrade);
	AForm(const AForm &copy);
	AForm &operator=(const AForm &copy);
	~AForm();

	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
		virtual const char *what() const throw();
	};

	std::string getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;

	void beSigned(const Bureaucrat &bureaucrat);

	virtual void execute(Bureaucrat const &executor) const = 0;
	void checkExecutability(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &os, const Form &obj);

#endif