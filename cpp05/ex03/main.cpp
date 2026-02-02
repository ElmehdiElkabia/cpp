#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
    std::cout << "\n\033[32m--- TEST 1: ---\033[0m" << std::endl;
    Intern  someRandomIntern;
    Bureaucrat boss("Boss", 1);

	std::cout << "Created: " << boss << std::endl;

    AForm* rrf = NULL;
    AForm* scf = NULL;
    AForm* ppf = NULL;
    AForm* bad = NULL;

    std::cout << "\n\033[32m--- TEST 2: ---\033[0m" << std::endl;
    

    std::cout << "[Order]: Boss asks for a 'robotomy request' on 'Bender'" << std::endl;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf)
    {
        std::cout << *rrf << std::endl;
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
    }

    std::cout << std::endl;

    std::cout << "[Order]: Boss asks for a 'shrubbery creation' on 'Garden'" << std::endl;
    scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (scf)
    {
        std::cout << *scf << std::endl;
        boss.signForm(*scf);
        boss.executeForm(*scf); 
    }

    std::cout << std::endl;

    std::cout << "[Order]: Boss asks for a 'presidential pardon' on 'Criminal'" << std::endl;
    ppf = someRandomIntern.makeForm("presidential pardon", "Criminal");
    if (ppf)
    {
        std::cout << *ppf << std::endl;
        boss.signForm(*ppf);
        boss.executeForm(*ppf);
    }

    std::cout << "\n\033[32m--- TEST 3: ---\033[0m" << std::endl;
    

    std::cout << "[Order]: Boss asks for a 'coffee making' form" << std::endl;
    bad = someRandomIntern.makeForm("coffee making", "Kitchen");
    
    if (bad)
        std::cout << "This should not exist!" << std::endl;
    else
        std::cout << "[Result]: Intern ignored the request (returned NULL)." << std::endl;

    std::cout << "\n\033[32m--- TEST 4: CLEANUP ---\033[0m" << std::endl;
    
    delete rrf;
    delete scf;
    delete ppf;

    return 0;
}