#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	Value = 0;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    std::cout << "Copy assignment operator called" << std::endl;

    if (this != &copy)
        this->Value = copy.Value;
    return (*this);
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}   

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->Value = raw;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->Value);
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    this->Value = n << FractionalBits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
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

