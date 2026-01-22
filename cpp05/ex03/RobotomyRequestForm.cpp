#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45),
											 target("default_target") {};

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45),
															   target(target) {};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy),
																			target(copy.target) {};

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		this->target = copy.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor from Class RobotomyRequestForm is Call" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::checkExecutability(executor);

	std::cout << " VRRRRRRRRR... BZZZZZZZT......VRRRRRRRRR... BZZZZZZZT..." << std::endl;

	if (std::rand() % 2 == 0)
		std::cout << "that :" << this->getTarget() << " has been robotomized successfully !" << std::endl;
	else
		std::cout << "Robotomy failed! " << this->getTarget()  << std::endl;
}