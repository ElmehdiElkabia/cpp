#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <iterator>
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

	template <typename InputIt>
	void addNumber(InputIt first, InputIt last)
	{
		size_t range = std::distance(first, last);
		if (v.size() + range > n)
			throw ContainerIsFull();
		v.insert(v.end(), first, last);
	}

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

	// void print() const
	// {
	// 	std::vector<int>::const_iterator it;
	// 	for (it = v.begin(); it != v.end(); ++it)
	// 		std::cout << *it << " ";
	// 	std::cout << std::endl;
	// }
};

#endif