#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
}

Fixed::Fixed(const int v)
{
	value = v << fbits;
}

Fixed::Fixed(const float f)
{
	value = roundf(f * (1 << fbits));
}

Fixed::Fixed(const Fixed &fixed)
{
	value = fixed.value;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	if (this != &fixed)
		value = fixed.value;

	return *this;
}

Fixed::~Fixed()
{
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

bool Fixed::operator>(const Fixed &fixed) const
{
	return value > fixed.value;
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return value < fixed.value;
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return value >= fixed.value;
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return value <= fixed.value;
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return value == fixed.value;
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return value != fixed.value;
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
	return (this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	return (this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	return (this->toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++()
{
	value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed old(*this);
	value++;
	return old;
}

Fixed &Fixed::operator--()
{
	value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed old(*this);
	value--;
	return old;
}

Fixed& Fixed::min(Fixed &v1, Fixed &v2)
{
	if (v1.toFloat() > v2.toFloat())
		return v2;
	return v1;
}

Fixed& Fixed::max(Fixed &v1, Fixed &v2)
{
	if (v1.toFloat() > v2.toFloat())
		return v1;
	return v2;
}

const Fixed& Fixed::min(const Fixed &v1, const Fixed &v2)
{
	if (v1.toFloat() > v2.toFloat())
		return v2;
	return v1;
}

const Fixed& Fixed::max(const Fixed &v1, const Fixed &v2)
{
	if (v1.toFloat() > v2.toFloat())
		return v1;
	return v2;
}