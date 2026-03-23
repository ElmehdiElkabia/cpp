#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

template <typename T>
void printFound(const T& value)
{
	std::cout << "Found: " << value << std::endl;
}

void testVector()
{
	std::cout << "===== VECTOR TESTS =====" << std::endl;

	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);

	try
	{
		std::vector<int>::iterator it = easyfind(v, 20);
		printFound(*it);
	}
	catch (const std::exception& e)
	{
		std::cout << "20 not found: " << e.what() << std::endl;
	}

	try
	{
		std::vector<int>::iterator it = easyfind(v, 99);
		printFound(*it);
	}
	catch (const std::exception& e)
	{
		std::cout << "99 not found: " << e.what() << std::endl;
	}

	std::cout << std::endl;
}

void testList()
{
	std::cout << "===== LIST TESTS =====" << std::endl;

	std::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);

	try
	{
		std::list<int>::iterator it = easyfind(l, 3);
		printFound(*it);
	}
	catch (const std::exception& e)
	{
		std::cout << "3 not found: " << e.what() << std::endl;
	}

	try
	{
		std::list<int>::iterator it = easyfind(l, -1);
		printFound(*it);
	}
	catch (const std::exception& e)
	{
		std::cout << "-1 not found: " << e.what() << std::endl;
	}

	std::cout << std::endl;
}

void testDeque()
{
	std::cout << "===== DEQUE TESTS =====" << std::endl;

	std::deque<int> d;
	d.push_back(5);
	d.push_back(15);
	d.push_back(25);
	d.push_back(35);

	try
	{
		std::deque<int>::iterator it = easyfind(d, 35);
		printFound(*it);
	}
	catch (const std::exception& e)
	{
		std::cout << "35 not found: " << e.what() << std::endl;
	}

	try
	{
		std::deque<int>::iterator it = easyfind(d, 100);
		printFound(*it);
	}
	catch (const std::exception& e)
	{
		std::cout << "100 not found: " << e.what() << std::endl;
	}

	std::cout << std::endl;
}

void testEmptyContainer()
{
	std::cout << "===== EMPTY CONTAINER TEST =====" << std::endl;

	std::vector<int> empty;

	try
	{
		std::vector<int>::iterator it = easyfind(empty, 1);
		printFound(*it);
	}
	catch (const std::exception& e)
	{
		std::cout << "Empty container search failed: " << e.what() << std::endl;
	}

	std::cout << std::endl;
}

void testSingleElement()
{
	std::cout << "===== SINGLE ELEMENT TEST =====" << std::endl;

	std::list<int> one;
	one.push_back(42);

	try
	{
		std::list<int>::iterator it = easyfind(one, 42);
		printFound(*it);
	}
	catch (const std::exception& e)
	{
		std::cout << "42 not found: " << e.what() << std::endl;
	}

	try
	{
		std::list<int>::iterator it = easyfind(one, 0);
		printFound(*it);
	}
	catch (const std::exception& e)
	{
		std::cout << "0 not found: " << e.what() << std::endl;
	}

	std::cout << std::endl;
}

int main()
{
	testVector();
	testList();
	testDeque();
	testEmptyContainer();
	testSingleElement();
	return 0;
}