#include "Character.hpp"

Character::Character() : _name("Default_name")
{
	for (int i = 0; i < 4; i++)
	{
		this->inventory[i] = NULL;
	}
	std::cout << "Default Constructor is Call from class Character\n";
}

Character::Character(std::string const &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
	{
		this->inventory[i] = NULL;
	}
	std::cout << "Constructor is Call from class Character\n";
}

Character::Character(const Character &copy)
{
	this->_name = copy.getName();
	for (int i = 0; i < 4; i++)
	{
		if (copy.inventory[i] != NULL)
			this->inventory[i] = copy.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
	std::cout << "Copy Constructor is Call from class Character\n";
}

Character &Character::operator=(const Character &copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i] != NULL)
			{
				delete this->inventory[i];
				this->inventory[i] = NULL;
			}
		}
		this->_name = copy.getName();
		for (int i = 0; i < 4; i++)
		{
			if (copy.inventory[i] != NULL)
				this->inventory[i] = copy.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
	}
	std::cout << "Copy Assignment Operator is Call from class Character\n";
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] != NULL)
		{
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
	}
	std::cout << "Destructor is Call from class Character\n";
}

const std::string &Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria *m)
{
	if (m == NULL)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return;
	if (this->inventory[idx] == NULL)
		this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4 || this->inventory[idx] == NULL)
		return;
	if (this->inventory[idx] != NULL)
		this->inventory[idx]->use(target);
}