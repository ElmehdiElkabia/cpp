#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Shrubbery", 25, 5),
												   target("default_target") {};

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Shrubbery", 25, 5),
																	 target(target) {};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy),
																					 target(copy.target) {};

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		this->target = copy.target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor from Class PresidentialPardonForm is Call" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	AForm::checkExecutability(executor);

	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}