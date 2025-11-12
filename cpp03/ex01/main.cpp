#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap a("1");
    ScavTrap c("3");

    // ScavTrap *obj;
    // obj = new ScavTrap("3");

    c.guardGate();
    a.attack("3");
    c.takeDamage(10);
    a.attack("3");
    c.takeDamage(10);
    a.takeDamage(9);
    // obj->attack("1");
    // obj->takeDamage(150);
    // obj->guardGate();

    // delete obj;
}