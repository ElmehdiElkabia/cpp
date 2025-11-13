#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("_clap_name"), name("DiamondTrap")
{
	this->hit_point = FragTrap::hit_point;
	this->energy_point = ScavTrap::energy_point;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), name(name)
{
	this->hit_point = FragTrap::hit_point;
	this->energy_point = ScavTrap::energy_point;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << "DiamondTrap  constructor called" << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap) : ClapTrap(diamondtrap), FragTrap(diamondtrap), ScavTrap(diamondtrap)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondtrap)
{
	if (this != &diamondtrap)
	{
		this->name = diamondtrap.name;
		this->hit_point = diamondtrap.hit_point;
		this->energy_point = diamondtrap.energy_point;
		this->attack_damage = diamondtrap.attack_damage;
	}
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << this->name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}