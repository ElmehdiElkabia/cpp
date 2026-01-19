#include "AForm.hpp"

AForm::AForm(const std::string name, int signgrade, int execgrade) : name(name),
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

AForm::AForm(const AForm &copy) : name(copy.getName()),
								  issigned(copy.getIsSigned()),
								  signgrade(copy.getSignGrade()),
								  execgrade(copy.getExecGrade())

{
	this->issigned = copy.getIsSigned();
}

AForm &AForm::operator=(const AForm &copy)
{
	if (this != &copy)
	{
		this->issigned = copy.getIsSigned();
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "Destructor from Class AForm is Call" << std::endl;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "AForm Grade is too high! Maximum is 1.";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "AForm Grade is too low! Minimum is 150.";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form not signed! You must sign the form before executing it.";
}

std::string AForm::getName() const
{
	return name;
}

bool AForm::getIsSigned() const
{
	return issigned;
}

int AForm::getSignGrade() const
{
	return signgrade;
}

int AForm::getExecGrade() const
{
	return execgrade;
}

std::ostream &operator<<(std::ostream &os, const AForm &obj)
{
	os << "AForm '" << obj.getName() << "':" << " Status: " << obj.getIsSigned() << " Required Grade to Sign: " << obj.getSignGrade() << " Required Grade to Execute: " << obj.getExecGrade() << std::endl;
	return os;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->signgrade)
		this->issigned = true;
	else
		throw GradeTooLowException();
}

void AForm::checkExecutability(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
		throw FormNotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
}