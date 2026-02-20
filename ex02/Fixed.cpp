#include "Fixed.hpp"

Fixed::Fixed()
{
	Value = 0;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    if (this != &copy)
        this->Value = copy.Value;
    return (*this);
}

Fixed::Fixed(const Fixed &copy)
{
    this->Value = copy.Value;
}

Fixed::~Fixed()
{
}   

void	Fixed::setRawBits( int const raw )
{
	this->Value = raw;
}

int	Fixed::getRawBits( void ) const
{
	return (this->Value);
}

Fixed::Fixed(const int n)
{
    this->Value = n << FractionalBits;
}

Fixed::Fixed(const float f)
{
	this->Value = roundf(f * (1 << FractionalBits));
}

float Fixed::toFloat( void ) const
{
	return ((float)this->Value / (1 << FractionalBits));
}

int Fixed::toInt( void ) const
{
	return (this->Value >> FractionalBits);
}


std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->Value > other.Value);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->Value < other.Value);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->Value >= other.Value);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->Value <= other.Value);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->Value == other.Value);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->Value != other.Value);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.Value = this->Value + other.Value;
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.Value = this->Value - other.Value;
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result.Value = (this->Value * other.Value) >> FractionalBits;
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	result.Value = (this->Value << FractionalBits) / other.Value;
	return (result);
}

Fixed &Fixed::operator++()
{
	this->Value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->Value++;
	return (temp);
}

Fixed &Fixed::operator--()
{
	this->Value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->Value--;
	return (temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if(a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if(a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if(a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if(a > b)
		return (a);
	return (b);
}

