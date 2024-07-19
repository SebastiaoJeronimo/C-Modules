#include <string>
#include <iostream>

//void functionRvalues(std::string &&str) you can still do something like this for later move semantics
void functionByValue(std::string str)
{
    std::cout << "Value" << "\n";
    std::cout << "this is the name of the passed string " << str << "\n"; 
    std::cout << "this is memory address of the passed string " << &str << "\n"; 
}

//this function only allows lvalues as parameters
void functionReference(std::string &str)
{
    std::cout << "Reference" << "\n";
    std::cout << "this is the name of the passed string " << str << "\n"; 
    std::cout << "this is memory address of the passed string " << &str << "\n"; 
}

//this function allows both lvalues and rvalues as parameters
void functionConstReference(const std::string &str)
{
    std::cout << "Const Reference" << "\n";
    std::cout << "this is the name of the passed string " << str << "\n"; 
    std::cout << "this is memory address of the passed string " << &str << "\n"; 
}



//advanced lvalues and rvalues
// https://youtu.be/XS2JddPq7GQ?si=D3_GZOVyfQazU7oz
//pratical use
// https://www3.ntu.edu.sg/home/ehchua/programming/cpp/cp4_PointerReference.html
//summed up
// https://stackoverflow.com/questions/8627956/ways-of-passing-arguments-value-vs-reference-vs-pointer 
int main()
{
    //g++ -std=c++98 *.cpp && valgrind ./a.out

    //using std::str
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str; 
    std::string  & stringREF = str;

    std::cout << "Memory address of the string variable " << &str << "\n";
    std::cout << "Memory address that the pointer is pointing to " << stringPTR << "\n";
    std::cout << "Memory address which the reference is referring to " << &stringREF << "\n";
    //-------------------------------------------------------------------------------

    std::cout << "The value of the string variable is " << str << "\n";
    std::cout << "The value pointed to by stringPTR " << *stringPTR << "\n";
    std::cout << "The value pointed to by stringREF " << stringREF << "\n";

    /*
    std::string lvalue = "THIS STRING IS NOT A CONSTANT";
    std::cout << "Memory address of the lvalue string " << &lvalue << "\n";

    //----- BY REFERENCE --------------------------
    //REFERENCES CANNOT BE NULL
    functionReference(lvalue);
    //functionReference("string constant"); //cant pass rvalues if the declaration asks for a reference it will give errors

    //----- CONST REFERENCE ------------------------
    functionConstReference(lvalue);
    functionConstReference("string constant"); //since this function takes a const reference as an argument it will allow rvalues

    //------ BY VALUE ------------------------------
    functionByValue(lvalue);
    functionByValue("string constant");
    */
} 