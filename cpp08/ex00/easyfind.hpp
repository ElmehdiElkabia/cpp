#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <algorithm>

class NotFound : public std::exception
{
	virtual const char *what() const throw()
	{
		return ("Number not found");
	}
};

template <typename T>
typename T::iterator easyfind(T &container, int f);

#include "easyfind.tpp"
#endif