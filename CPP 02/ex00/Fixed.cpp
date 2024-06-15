#include "Fixed.hpp"

// FP numbers AC
// static const int o que é e como inicializar~
//copy assigment operator overload //TODO
// getRawBits e set RawBits implementar


//solve the nBits problem
Fixed::Fixed() {
    this->value = 0;
    //print Default contructor
    //how to initialize the nBits atributte
}

Fixed::Fixed(Fixed &f)
{
    //TO DO
    //print constructor
    //checkar se esta correto
    //nBits

    this->value = f.value;
}

Fixed::~Fixed(){
    //TODO 
    //print destructor
}

