#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class  Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &copy);
		Fixed (const int n);
		Fixed (const float f);
		float toFloat( void ) const;
		int toInt( void ) const;

		int     getRawBits( void ) const;
		void    setRawBits( int const raw );
		
	private:
		int Value;
		static const int FractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);


#endif