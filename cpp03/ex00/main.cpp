#include "ClapTrap.hpp"

int main()
{
    ClapTrap a;
    ClapTrap b("target");

    a.attack("target_1");
    a.takeDamage(9);
    a.takeDamage(10);
    a.beRepaired(5);
    a.attack("target_2");
    b.beRepaired(3);
    for (int i = 0; i < 12; i++)
        b.attack("target_loop");
    b.beRepaired(3);
}