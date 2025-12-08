#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	AMateria *inventory[4];
	std::string _name;

private:
	Character();
	Character(std::string const &name);
	Character(const Character &copy);
	Character &operator=(const Character &copy);
	~Character();

	std::string const &getName() const;
	void equipe(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};

#endif