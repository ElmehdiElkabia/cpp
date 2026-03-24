#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>

class Span
{
private:
	unsigned int n;
	std::vector<int> v;

public:
	Span();
	Span(unsigned int i);
	Span(const Span &copy);
	Span &operator=(const Span &copy);
	~Span();

	void addNumber(int a);

	int shortestSpan();
	int longestSpan();

	class ContainerIsFull : public std::exception
	{
		virtual const char *what() const throw();
	};

	class NotEnough : public std::exception
	{
		virtual const char *what() const throw();
	};
};

#endif