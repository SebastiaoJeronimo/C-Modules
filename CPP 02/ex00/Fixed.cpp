
/* SHALLOW AND DEEP COPY 
*
* Java 
* https://www.infoworld.com/article/2173838/how-to-copy-objects-in-java-shallow-copy-and-deep-copy.html
*
* python
* https://www.geeksforgeeks.org/copy-python-deep-copy-shallow-copy//
*
* C++
* https://www.geeksforgeeks.org/shallow-copy-and-deep-copy-in-c/
* 
* Javascript
* https://medium.com/nerd-for-tech/deep-dive-into-shallow-and-deep-copy-in-javascript-d6b2ba746ccd
*/

/* 
    copy constructor and assignment operator -> https://youtu.be/pKKXGxEapaU?si=GOXJG--9SyBrQKcy
    copy constructor -> is used when we are creating a completely new object based on other object
    assignment operator -> is used when changing the values of a already existing object based on other object

    COPY CONSTRUCTOR in C++
    https://www.geeksforgeeks.org/copy-constructor-in-cpp/
    ASSIGNMENT OPERATOR in C++
*/
#include "Fixed.hpp"

// FP numbers AC
// static const int o que é e como inicializar
//copy assigment operator overload //TODO
// getRawBits e set RawBits implementar


//solve the nBits problem
Fixed::Fixed() {
    std::cout << "Default constructor called" << "\n";
    this->value = 0;
    //print Default contructor
    //how to initialize the nBits atributte
}

Fixed::Fixed(const Fixed &f)
{
    std::cout << "Copy constructor called" << "\n";
    this->value = f.value;
}

//16:37
Fixed & Fixed::operator=(const Fixed &f)
{
    std::cout << "Copy assignment operator called" << "\n";
    this->value = f.value;

    return *this; //did not understand this
}


Fixed::~Fixed(){
    std::cout << "Destructor called" << "\n";
}


int Fixed::getRawBits() const{
    std::cout << "getRawBits member function called" << "\n";
    return this->value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << "\n";
    this->value = raw;
}
