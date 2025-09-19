#include "Zombie.hpp"

int main(void)
{

	Zombie *z1 = newZombie("elmehdi");
	z1->announce();
	delete(z1);

	Zombie *z2 = new Zombie("ali");
	z2->announce();
	delete(z2);

	randomChump("elmehdi elkabia");
}