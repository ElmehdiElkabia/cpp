#include "Zombie.hpp"

int main(void)
{
	Zombie *z;

	z = newZombie("elmehdi elkabia");
	z->announce();
	delete z;

	randomChump("elmehdi");
}