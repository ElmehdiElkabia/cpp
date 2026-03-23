#include "Span.hpp"

int main()
{
	std::cout << "===== BASIC TEST =====" << std::endl;
	try
	{
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n===== FULL CONTAINER TEST =====" << std::endl;
	try
	{
		Span sp(2);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== NOT ENOUGH NUMBERS TEST =====" << std::endl;
	try
	{
		Span sp(5);
		sp.addNumber(42);

		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== LARGE TEST (10,000 numbers) =====" << std::endl;
	try
	{
		Span sp(10000);

		for (int i = 0; i < 10000; i++)
			sp.addNumber(i);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n===== DUPLICATE TEST =====" << std::endl;
	try
	{
		Span sp(5);
		sp.addNumber(5);
		sp.addNumber(5);
		sp.addNumber(10);

		std::cout << "Shortest span (expect 0): " << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n===== NEGATIVE NUMBERS TEST =====" << std::endl;
	try
	{
		Span sp(5);
		sp.addNumber(-10);
		sp.addNumber(-20);
		sp.addNumber(5);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}