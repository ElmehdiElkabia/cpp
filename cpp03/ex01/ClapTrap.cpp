#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("ClapTrap"), hit_point(10), energy_point(10), attack_damage(0)
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
};

ClapTrap::ClapTrap(std::string name) : name(name), hit_point(10), energy_point(10), attack_damage(0)
{
    std::cout << "ClapTrap Constructor called" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
    *this = claptrap;
    std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
{
    if (this != &claptrap)
    {
        this->name = claptrap.name;
        this->energy_point = claptrap.energy_point;
        this->attack_damage = claptrap.attack_damage;
        this->hit_point = claptrap.hit_point;
    }
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called" << std::endl;
};

void ClapTrap::attack(const std::string &target)
{
    if (this->energy_point > 0 && this->hit_point > 0)
    {
        this->energy_point--;
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
    }
    else if (this->energy_point == 0)
        std::cout << "ClapTrap " << this->name << " has no energy left to attack" << std::endl;
    else
        std::cout << "ClapTrap " << this->name << " is out of hit points and can't move!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hit_point > 0)
    {
        this->hit_point -= amount;
        this->attack_damage += amount;
        if (this->hit_point <= 0)
        {
            this->hit_point = 0;
            std::cout << "ClapTrap " << this->name << " took " << amount << " damage and is destroyed!" << std::endl;
        }
        else
            std::cout << "ClapTrap " << this->name << " took " << amount << " and now has " << this->hit_point << " hit points left." << std::endl;
    }
    else if (this->hit_point == 0)
        std::cout << "ClapTrap " << this->name << " is already destroyed." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energy_point > 0 && this->hit_point > 0)
    {
        this->energy_point--;
        this->hit_point += amount;
        std::cout << "ClapTrap " << this->name << " repaired itself for " << amount << " hit point and now has " << this->hit_point << " hit points left" << std::endl;
    }
    else if (this->energy_point == 0)
        std::cout << "ClapTrap " << this->name << " has no energy left to repair" << std::endl;
    else
        std::cout << "ClapTrap " << this->name << " is destroyed and can't repair itself." << std::endl;
}