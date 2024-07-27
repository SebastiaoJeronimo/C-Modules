#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    public: 
        Fixed();                                    //Default Constructor
        Fixed(const Fixed &f);                      //Copy Constructor
        Fixed& operator=(const Fixed& original);    //Copy assignment operator overload
        ~Fixed();                                   //Destructor

        int getRawBits(void) const;
        void setRawBits(int const raw);
    private:
        int value;
        static const int nBits = 8;
};
#endif