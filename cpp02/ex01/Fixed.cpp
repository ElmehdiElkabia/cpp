#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int v)
{
	value = v << fbits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
{
	value = roundf(f * (1 << fbits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	value = fixed.value;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	if (this != &fixed)
		value = fixed.value;
	std::cout << "Copy assignment operator called" << std::endl;

	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return value / (float)(1 << fbits);
}

int Fixed::toInt(void) const
{
	return value >> fbits;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}