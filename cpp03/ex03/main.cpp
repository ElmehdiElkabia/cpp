#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    std::cout << "\n--- ClapTrap Tests ---\n";
    ClapTrap clap("CLAPPY");
    clap.attack("target dummy");
    clap.takeDamage(5);
    clap.beRepaired(3);
    clap.takeDamage(10); // should destroy

    std::cout << "\n--- ScavTrap Tests ---\n";
    ScavTrap scav("SCAVY");
    scav.attack("enemy robot");
    scav.guardGate();
    scav.takeDamage(50);
    scav.beRepaired(20);

    std::cout << "\n--- FragTrap Tests ---\n";
    FragTrap frag("FRAGGY");
    frag.attack("evil drone");
    frag.highFivesGuys();
    frag.takeDamage(80);
    frag.beRepaired(40);

    std::cout << "\n--- DiamondTrap Tests ---\n";
    DiamondTrap diamond("DIAMONDY");
    diamond.attack("boss monster");  // uses ScavTrap’s attack
    diamond.takeDamage(20);
    diamond.beRepaired(10);
    diamond.whoAmI();                // show both names
    diamond.guardGate();             // from ScavTrap
    diamond.highFivesGuys();         // from FragTrap

    std::cout << "\n--- Test Done ---\n";
    return 0;
}
