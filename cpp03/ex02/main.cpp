#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    // ClapTrap a("1");
    // ClapTrap b("2");
    // ScavTrap c("3");
    // FragTrap d("4");

    // a.attack("2");
    // b.takeDamage(a.getAttackDmg());
    // a.attack("2");
    // b.takeDamage(a.getAttackDmg());
    // a.attack("2");
    // b.takeDamage(a.getAttackDmg());
    // c.guardGate();
    // d.highFivesGuys();

    ClapTrap *scav;
    scav = new ScavTrap("1");

    // FragTrap *frag;
    // frag = new FragTrap("2");
    // FragTrap copy(*frag);

    // copy.attack("ilias");
    // copy.highFivesGuys();
    // // scav->attack("2");
    // frag->takeDamage(100);
    // frag->highFivesGuys();

    scav->attack("1");

    // delete scav;
    delete scav;

    return (0);
}