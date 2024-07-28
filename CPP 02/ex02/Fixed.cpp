#include "Fixed.hpp"

//IEEE 754 Binary to Float Conversion -> https://www.youtube.com/watch?v=8cRQT93Olek
//Fixed point representation -> https://www.geeksforgeeks.org/fixed-point-representation/
//Fixed point in embedded systems IMPORTANT -> https://www.youtube.com/watch?v=YXKDjVcCWyE


Fixed::Fixed(const float num)
{
    
    std::cout << "Float constructor called" << "\n";
    //Representation = round(float * 2^n)
    //example floating point number  -3.141593 with 12 characters
    //round ( -3.141593 * 2^12) = -12868
    // negative numbers??
    this->value = roundf(num * pow(2,nBits));
}

Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << "\n";
    //same  thing as value = num << 2^nBits
    // negative numbers??
    this->value = num * pow(2,nBits); // 8(1) 8(1) 8(1) , the last 8 bits are decimal bits
}

Fixed::Fixed() {
    std::cout << "Default constructor called" << "\n";
    this->value = 0;  
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

//converting fixed point to floating point and vice versa
int Fixed::toInt() const {
    return (this->value >> nBits);
}

float Fixed::toFloat() const {
    return (((float) this->value) / (powf(2, nBits)));
}

bool Fixed::operator>(const Fixed & originalRight)  const{
    return (this->value > originalRight.value);
}

bool Fixed::operator<(const Fixed & originalRight)  const{
    return (this->value < originalRight.value);
}

bool Fixed::operator==(const Fixed & originalRight)  const{
    return (this->value == originalRight.value);
}

bool Fixed::operator!=(const Fixed & originalRight)  const{
    return (this->value != originalRight.value);
}

bool Fixed::operator>=(const Fixed & originalRight)  const{
    return (this->value >= originalRight.value);
}

bool Fixed::operator<=(const Fixed & originalRight)  const{
    return (this->value <= originalRight.value);
}


//check fixed point operations
Fixed & Fixed::operator-(const Fixed & originalRight)
{
    //assignment operator called returns a object ref 
    *this = Fixed((this->toFloat() - originalRight.toFloat()));
    return *this;
}

Fixed & Fixed::operator+(const Fixed & originalRight)
{
    *this = Fixed((this->toFloat() + originalRight.toFloat()));
    return *this;
}

Fixed & Fixed::operator*(const Fixed & originalRight)
{
    *this = Fixed((this->toFloat() * originalRight.toFloat()));
    return *this;
}

Fixed & Fixed::operator/(const Fixed & originalRight)
{
    *this = Fixed((this->toFloat() / originalRight.toFloat()));
    return *this;
}

//what is the epsilon?
//its the smallest number that 1 + e > 1
Fixed & Fixed::operator++(int){
    // TO DO 
}

Fixed & Fixed::operator++(){
    // TO DO 
}

Fixed & Fixed::operator--(int){
    // TO DO 
}

Fixed & Fixed::operator--(){
    // TO DO 
}


std::ostream & operator<<(std::ostream & out, const Fixed &fixed)
{
    return (out << fixed.toFloat());
}