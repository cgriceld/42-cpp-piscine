#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed(const int &param);
	Fixed(const float &param);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	Fixed &operator = (const Fixed &fixed);

private:
	int _value;
	static const int _bits;
};

std::ostream &operator << (std::ostream &stream, const Fixed &fixed);

#endif