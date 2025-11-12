#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    hit_point = 100;
    energy_point = 50;
    attack_damage = 20;
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    hit_point = 100;
    energy_point = 50;
    attack_damage = 20;
    std::cout << "ScavTrap Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap) : ClapTrap(scavtrap)
{
    *this = scavtrap;
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap)
{
    if (this != &scavtrap)
    {
        this->name = scavtrap.name;
        this->hit_point = scavtrap.hit_point;
        this->attack_damage = scavtrap.attack_damage;
        this->energy_point = scavtrap.energy_point;
    }
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->energy_point > 0 && this->hit_point > 0)
    {
        this->energy_point--;
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
    }
    else if (this->energy_point == 0)
        std::cout << "ScavTrap " << this->name << " has no energy left to attack" << std::endl;
    else
        std::cout << "ScavTrap " << this->name << " is out of hit points and can't move!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gate Keeper!" << std::endl;
}