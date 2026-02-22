#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0){};

template <typename T>
Array<T>::Array(unsigned int n) : _array(NULL), _size(n)
{
	if (n > 0)
		_array = new T[n];
};

template <typename T>
Array<T>::Array(const Array &copy) : _array(NULL), _size(copy._size)
{
	if (_size > 0)
	{
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = copy._array[i];
	}
}

template <typename T>
T &Array<T>::operator=(const Array &copy)
{
	if (this != &copy)
	{
		delete[] _array;

		_size = copy._size;
		_array = NULL;

		if (_size > 0)
		{
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = copy._array[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete [] _array;
}

template <typename T>
unsigned int Array<T>::size() const
{
	return this->_size;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw IndexNotFound();
	return _array[i];
}

template <typename T>
const T &Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
		throw IndexNotFound();
	return _array[i];
}

template <typename T>
const char *Array<T>::IndexNotFound::what() const throw()
{
	return "Array index is out of bounds";
}