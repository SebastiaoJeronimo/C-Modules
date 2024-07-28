#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

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

        int getRawBits() const;
        void setRawBits(int const raw);
    private:
        int value;
        static const int nBits = 8;
};

//overload operator global function
std::ostream & operator<<(std::ostream & out, const Fixed &fixed);

#endif