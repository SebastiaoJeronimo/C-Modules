#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
        Fixed();
        ~Fixed();
        Fixed(const int num);
        Fixed(const float fNum);
        Fixed(const Fixed & original);
        Fixed & operator=(const Fixed & originalRight);
        float toFloat( void ) const;
        int toInt( void ) const;
    private:
        int value;
        static const int nBits = 8;
};

//overload operator global function
std::ostream & operator<<(std::ostream & out, const Fixed &fixed);

#endif