#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade)
{
	this->name = name;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high! Maximum is 1.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low! Minimum is 150.";
}

std::string Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::increment()
{
	if (this->grade == 1)
		throw GradeTooHighException();
	this->grade--;
	std::cout << "Bureaucrat promoted! New grade: " << this->grade << std::endl;
}

void Bureaucrat::decrement()
{
	if (this->grade == 150)
		throw GradeTooLowException();
	this->grade++;
	std::cout << "Bureaucrat demoted. New grade: " << this->grade << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor is Call" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
	return os;
}