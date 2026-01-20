#include <iostream>
#include <cstdlib> // For srand
#include <ctime>   // For time
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    // 1. Seed the random number generator for Robotomy
    std::srand(std::time(NULL));

    std::cout << "\n\033[36m--- TEST 1: SHRUBBERY CREATION FORM ---\033[0m" << std::endl;
    try {
        Bureaucrat bob("Bob", 137); // Grade just high enough to execute
        ShrubberyCreationForm shrub("home");

        std::cout << shrub << std::endl;
        
        // Try to execute before signing (Should fail)
        bob.executeForm(shrub); 

        // Sign it
        bob.signForm(shrub);

        // Execute it (Should work and create 'home_shrubbery')
        bob.executeForm(shrub);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[36m--- TEST 2: ROBOTOMY REQUEST FORM ---\033[0m" << std::endl;
    try {
        Bureaucrat doctor("Dr. House", 45); // Grade 45 is needed to execute
        RobotomyRequestForm robot("Bender");

        doctor.signForm(robot);
        
        // Run it 4 times to see the 50% chance in action
        std::cout << "Attempt 1: "; doctor.executeForm(robot);
        std::cout << "Attempt 2: "; doctor.executeForm(robot);
        std::cout << "Attempt 3: "; doctor.executeForm(robot);
        std::cout << "Attempt 4: "; doctor.executeForm(robot);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[36m--- TEST 3: PRESIDENTIAL PARDON FORM ---\033[0m" << std::endl;
    try {
        Bureaucrat king("King Arthur", 5);   // Can execute (Grade 5)
        Bureaucrat peasant("Peasant", 100); // Cannot execute
        PresidentialPardonForm pardon("Arthur Dent");

        // Peasant tries to sign (Fail)
        peasant.signForm(pardon);

        // King signs (Success)
        king.signForm(pardon);

        // Peasant tries to execute (Fail: Grade too low)
        std::cout << "--- Peasant trying to execute ---" << std::endl;
        peasant.executeForm(pardon);

        // King executes (Success)
        std::cout << "--- King trying to execute ---" << std::endl;
        king.executeForm(pardon);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}