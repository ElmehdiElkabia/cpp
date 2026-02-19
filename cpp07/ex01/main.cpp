#include "iter.hpp"

void increment(int &i)
{
	i++;
}

void toupperchar(char &c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
}

void print(const int &i)
{
	std::cout << "[" << i << "]";
}

void printchar(const char &c)
{
	std::cout << c << ";";
}

void printstring(const std::string &str)
{
	std::cout << str << std::endl;
}

void appendSomething(std::string &str)
{
	str += "!";
}

int main(void)
{
	int arrayint[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	const size_t sizeint = sizeof(arrayint) / sizeof(int);

	std::cout << "\n----------- array int -----------\n";

	std::cout << "befor increment \n";
	iter(arrayint, sizeint, print);
	iter(arrayint, sizeint, increment);
	std::cout << "\nafter increment \n";
	iter(arrayint, sizeint, print);

	std::cout << "\n\n----------- array char -----------\n";

	char arraychar[] = {'e', 'd', 'H', 'r', 'o', 'l', 's'};
	const size_t sizechar = sizeof(arraychar) / sizeof(char);

	std::cout << "befor to upper case \n";
	iter(arraychar, sizechar, printchar);
	iter(arraychar, sizechar, toupperchar);
	std::cout << "\nafter to upper case \n";
	iter(arraychar, sizechar, printchar);

	std::cout << "\n\n----------- array string -----------\n";

	std::string arraystr[] = {
		"hello",
		"world",
		"template",
		"iter",
		"function"};

	const size_t sizestr = sizeof(arraystr) / sizeof(std::string);

	std::cout << "before modification\n";
	iter(arraystr, sizestr, printstring);
	iter(arraystr, sizestr, appendSomething);

	std::cout << "\nafter modification\n";
	iter(arraystr, sizestr, printstring);
}