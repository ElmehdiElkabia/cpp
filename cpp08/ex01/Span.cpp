#include "Span.hpp"

Span::Span() : n(0) {};

Span::Span(unsigned int i) : n(i) {};

Span::Span(const Span &copy)
{
	*this = copy;
}

Span &Span::operator=(const Span &copy)
{
	if (this != &copy)
	{
		n = copy.n;
		v = copy.v;
	}
	return *this;
}

Span::~Span() {}



const char *Span::ContainerIsFull::what() const throw()
{
	return "The Container Is Full\n";
}

const char *Span::NotEnough::what() const throw()
{
	return "The Container less than 2 values\n";
}

void Span::addNumber(int a)
{
	if (v.size() >= n)
		throw ContainerIsFull();
	v.push_back(a);
}

int Span::shortestSpan()
{
	if (v.size() <= 1)
		throw NotEnough();
	std::vector<int> tmp = v;
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return min;
}

int Span::longestSpan()
{
	if (v.size() <= 1)
		throw NotEnough();
	std::vector<int> tmp = v;
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}