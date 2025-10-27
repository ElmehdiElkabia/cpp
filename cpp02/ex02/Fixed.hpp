#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int value;
	static const int fbits = 8;

public:
	Fixed();
	Fixed(const int v);
	Fixed(const float f);
	Fixed(const Fixed &fixed);
	Fixed &operator=(const Fixed &fixed);

	bool operator>(const Fixed &fixed) const;
	bool operator<(const Fixed &fixed) const;
	bool operator>=(const Fixed &fixed) const;
	bool operator<=(const Fixed &fixed) const;
	bool operator==(const Fixed &fixed) const;
	bool operator!=(const Fixed &fixed) const;

	Fixed operator+(const Fixed &fixed) const;
	Fixed operator-(const Fixed &fixed) const;
	Fixed operator*(const Fixed &fixed) const;
	Fixed operator/(const Fixed &fixed) const;

	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

	static Fixed &min(Fixed &v1, Fixed &v2);
	static const Fixed &min(const Fixed &v1, const Fixed &v2);
	static Fixed &max(Fixed &v1, Fixed &v2);
	static const Fixed &max(const Fixed &v1, const Fixed &v2);

	~Fixed();

	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif