#include "Form.hpp"

Form::Form(const std::string name, int signgrade, int execgrade) : name(name),
																   issigned(false),
																   signgrade(signgrade),
																   execgrade(execgrade)
{
	if (signgrade < 1)
		throw GradeTooHighException();
	else if (signgrade > 150)
		throw GradeTooLowException();

	if (execgrade < 1)
		throw GradeTooHighException();
	else if (execgrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &copy) : name(copy.getName()),
							   issigned(copy.getIsSigned()),
							   signgrade(copy.getSignGrade()),
							   execgrade(copy.getExecGrade())

{
	this->issigned = copy.getIsSigned();
}

Form &Form::operator=(const Form &copy)
{
	if (this != &copy)
	{
		this->issigned = copy.getIsSigned();
	}
	return *this;
}

Form::~Form()
{
	std::cout << "Destructor from Class Form is Call" << std::endl;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Form Grade is too high! Maximum is 1.";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form Grade is too low! Minimum is 150.";
}

std::string Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return issigned;
}

int Form::getSignGrade() const
{
	return signgrade;
}

int Form::getExecGrade() const
{
	return execgrade;
}

std::ostream &operator<<(std::ostream &os, const Form &obj)
{
	os << obj.getName() << " / " << obj.getIsSigned() << " / " << obj.getSignGrade() << " / " << obj.getExecGrade() << std::endl;
	return os;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->signgrade)
		this->issigned = true;
	else
		throw GradeTooLowException();
}