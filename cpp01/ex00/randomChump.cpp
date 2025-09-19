#include "Zombie.hpp"

void	randomChump(std::string name)
{
	if (name.length() > 0)
	{
		Zombie *zombie = new Zombie(name);
		zombie->announce();
		delete(zombie);
	}
}