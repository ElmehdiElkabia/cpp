#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    hit_point = 100;
    energy_point = 100;
    attack_damage = 30;
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    hit_point = 100;
    energy_point = 100;
    attack_damage = 30;
    std::cout << "FragTrap Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragtrap) : ClapTrap(fragtrap)
{
    *this = fragtrap;
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragtrap)
{
    if (this != &fragtrap)
    {
        this->name = fragtrap.name;
        this->hit_point = fragtrap.hit_point;
        this->attack_damage = fragtrap.attack_damage;
        this->energy_point = fragtrap.energy_point;
    }
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->name << " high five guys!" << std::endl;
}