#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>


template <typename T>
class Array
{
private:
	T *_array;
	unsigned int _size;

public:
	Array();
	Array(unsigned int n);
	Array(const Array &copy);
	T &operator=(const Array &copy);
	~Array();

	unsigned int size() const;

	T &operator[](unsigned int i);
	const T &operator[](unsigned int i) const;

	class IndexNotFound : public std::exception
	{
		virtual const char *what() const throw();
	};
};

#include "Array.tpp"

#endif