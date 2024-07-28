#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    //STATIC MEMBER FUNCTIONS 
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

        //comparison operators
        bool operator>(const Fixed & originalRight)  const;
        bool operator<(const Fixed & originalRight)  const;
        bool operator==(const Fixed & originalRight) const;
        bool operator!=(const Fixed & originalRight) const;
        bool operator>=(const Fixed & originalRight) const;
        bool operator<=(const Fixed & originalRight) const;

        //arithmetic operators
        Fixed & operator*(const Fixed & originalRight);
        Fixed & operator-(const Fixed & originalRight);
        Fixed & operator+(const Fixed & originalRight);
        Fixed & operator/(const Fixed & originalRight);

        //increment/decrement operators
        Fixed & operator++(int); //postfix ++
        Fixed & operator++();    //prefix  ++
        Fixed & operator--(int); //postfix --
        Fixed & operator--();    //prefix  --

    private:
        int value;
        static const int nBits = 8;
};

//overload operator global function
std::ostream & operator<<(std::ostream & out, const Fixed &fixed);

#endif