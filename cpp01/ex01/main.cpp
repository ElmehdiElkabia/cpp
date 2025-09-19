#include "Zombie.hpp"

int main(void)
{
	Zombie *z;
	int N = 10;

	z = zombieHorde(N, "elmehdi");
	for (int i = 0; i < N; i++)
	{
		z[i].announce();
	}
	delete[] z;
}