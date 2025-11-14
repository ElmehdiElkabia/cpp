#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "\n--- ClapTrap Tests ---\n";
    ClapTrap clap("CLAPPY");
    clap.attack("target dummy");
    clap.takeDamage(5);
    clap.beRepaired(3);
    clap.takeDamage(10);

    std::cout << "\n--- ScavTrap Tests ---\n";
    ScavTrap scav("SCAVY");
    scav.attack("enemy robot");
    scav.guardGate();
    scav.takeDamage(50);
    scav.beRepaired(20);

    std::cout << "\n--- ScavTrap Tests ---\n";

    ClapTrap *c = &scav;
    c->attack("10");

    std::cout << "\n--- Test Done ---\n";
    return 0;
}
