#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called\n";
};

Fixed::Fixed(const int &param)
{
	std::cout << "Int constructor called\n";
	this->_value = param << this->_bits;
}

Fixed::Fixed(const float &param)
{
	std::cout << "Float constructor called\n";
	this->_value = roundf(param * (1 << this->_bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

float Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)(1 << this->_bits));
}

int Fixed::toInt(void) const
{
	return (this->_value >> this->_bits);
}

int Fixed::getRawBits(void) const
{
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

Fixed &Fixed::operator = (const Fixed &fixed)
{
	std::cout << "Assignation operator called\n";
	this->_value = fixed.getRawBits();
	return (*this);
}

std::ostream &operator << (std::ostream &stream, const Fixed &fixed)
{
	stream << fixed.toFloat();
	return (stream);
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called\n";
	*this = fixed;
}