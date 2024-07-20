#include "Harl.hpp"

//c++ -std=c++98 *.cpp *.hpp && valgrind ./a.out
int main() {
    // Create an instance of the HARL class
    Harl harl;
    // Test the HARL class methods
    harl.complain(DEBUG);
    harl.complain(INFO);
    harl.complain(WARNING);
    harl.complain(ERROR);
    harl.complain("RANDOM NONSENSE");
    return 0;
}