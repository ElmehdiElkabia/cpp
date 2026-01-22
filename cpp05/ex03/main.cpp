#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
    std::cout << "\n\033[36m--- TEST 1: THE INTERN ARRIVES ---\033[0m" << std::endl;
    Intern  someRandomIntern;
    Bureaucrat boss("Boss", 1); // A high-ranking boss to sign everything

    // Pointers to store the forms created by the intern
    AForm* rrf = NULL;
    AForm* scf = NULL;
    AForm* ppf = NULL;
    AForm* bad = NULL;

    std::cout << "\n\033[36m--- TEST 2: CREATING VALID FORMS ---\033[0m" << std::endl;
    
    // 1. Robotomy Request
    std::cout << "[Order]: Boss asks for a 'robotomy request' on 'Bender'" << std::endl;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf)
    {
        std::cout << *rrf << std::endl;
        boss.signForm(*rrf);
        boss.executeForm(*rrf); // Should make drill noises
    }

    std::cout << std::endl;

    // 2. Shrubbery Creation
    std::cout << "[Order]: Boss asks for a 'shrubbery creation' on 'Garden'" << std::endl;
    scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (scf)
    {
        std::cout << *scf << std::endl;
        boss.signForm(*scf);
        boss.executeForm(*scf); // Should create file
    }

    std::cout << std::endl;

    // 3. Presidential Pardon
    std::cout << "[Order]: Boss asks for a 'presidential pardon' on 'Criminal'" << std::endl;
    ppf = someRandomIntern.makeForm("presidential pardon", "Criminal");
    if (ppf)
    {
        std::cout << *ppf << std::endl;
        boss.signForm(*ppf);
        boss.executeForm(*ppf); // Should announce pardon
    }

    std::cout << "\n\033[36m--- TEST 3: CREATING INVALID FORM ---\033[0m" << std::endl;
    
    // 4. Unknown Form
    std::cout << "[Order]: Boss asks for a 'coffee making' form" << std::endl;
    bad = someRandomIntern.makeForm("coffee making", "Kitchen");
    
    if (bad)
        std::cout << "This should not exist!" << std::endl;
    else
        std::cout << "[Result]: Intern ignored the request (returned NULL)." << std::endl;

    std::cout << "\n\033[36m--- TEST 4: CLEANUP ---\033[0m" << std::endl;
    
    // Clean up memory because Intern allocated with 'new'
    delete rrf;
    delete scf;
    delete ppf;
    // delete bad; // bad is NULL, so technically safe to delete, but logically unnecessary

    return 0;
}