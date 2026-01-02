#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
	const std::string name;
	int grade;

public:
	std::string getName() const;
	int getGrade();
	void GradeTooHighException();
	void GradeTooLowException();
};

#endif