#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    public: 
        Fixed();         //Default Constructor
        Fixed(Fixed &f); //Copy Constructor
        //copy assigment operator overload //TODO
        ~Fixed();       //Destructor

        int getRawBits(void) const;
        void setRawBits(int const raw);


    private:
        int value;
        static const int nBits;
};


#endif