#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137),
												 target("default_target") {};

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137),
																   target(target) {};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy),
																				  target(copy.target) {};

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		this->target = copy.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor from Class ShrubberyCreationForm is Call" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	AForm::checkExecutability(executor);

	std::cout << "planting trees at " << this->getTarget() << "..." << std::endl;

	std::string fileName = this->getTarget() + "_shrubbery";
	std::ofstream outputfile(fileName.c_str());

	if (!outputfile.is_open())
	{
		std::cerr << "Error: Could not create file " << fileName << std::endl;
		return;
	}

	outputfile << "                       ___\n"
				  "                 _,-'\"\"   \"\"\"\"`--.\n"
				  "              ,-'          __,,-- \\\n"
				  "            ,'    __,--\"\"\"\"dF      )\n"
				  "           /   .-\"Hb_,--\"\"dF      /\n"
				  "         ,'       _Hb ___dF\"-._,-'\n"
				  "       ,'      _,-\"\"\"\"   \"\"--..__\n"
				  "      (     ,-'                  `.\n"
				  "       `._,'     _   _             ;\n"
				  "        ,'     ,' `-'Hb-.___..._,-'\n"
				  "        \\    ,'\"Hb.-'HH`-.dHF\"\n"
				  "         `--'   \"Hb  HH  dF\"\n"
				  "                 \"Hb HH dF\n"
				  "                  \"HbHHdF\n"
				  "                   |HHHF\n"
				  "                   |HHH|\n"
				  "                   |HHH|\n"
				  "                   |HHH|\n"
				  "                   |HHH|\n"
				  "                   dHHHb\n"
				  "                 .dFd|bHb.               o\n"
				  "       o       .dHFdH|HbTHb.          o /\n"
				  " \\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y\n"
				  " ##########################################\n";

	outputfile.close();
	std::cout << "Successfully created a shrubbery at " << this->getTarget() << "." << std::endl;
}
