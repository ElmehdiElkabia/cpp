#include "iter.hpp"

void incremment(int &i)
{
	i++;
}

void toupperchar(char &c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
}

void print(int &i)
{
	std::cout << "[" << i << "]";
}

void printchar(char &c)
{
	std::cout << c << ";";
}

int main(void)
{
	int arrayint[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	size_t sizeint = sizeof(arrayint) / sizeof(int);

	std::cout << "\n----------- array int -----------\n";

	std::cout << "befor incremment \n";
	iter(arrayint, sizeint, print);
	iter(arrayint, sizeint, incremment);
	std::cout << "\nafter incremment \n";
	iter(arrayint, sizeint, print);

	std::cout << "\n\n----------- array char -----------\n";

	char arraychar[] = {'e', 'd', 'H', 'r', 'o', 'l', 's'};
	size_t sizechar = sizeof(arraychar) / sizeof(char);

	std::cout << "befor to upper case \n";
	iter(arraychar, sizechar, printchar);
	iter(arraychar, sizechar, toupperchar);
	std::cout << "\nafter to upper case \n";
	iter(arraychar, sizechar, printchar);
}