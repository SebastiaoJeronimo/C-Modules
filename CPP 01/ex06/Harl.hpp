#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

#define DEBUG       "DEBUG"
#define INFO        "INFO"
#define WARNING     "WARNING"
#define ERROR       "ERROR"

class Harl{
    private:
        //array of pointers to functions without using typedef
        /*
        arr    //arr 
        arr [] //is an array (so index it)
        * arr [] //of pointers (so dereference them)
        (* arr [])() //to functions taking nothing (so call them with ())
        void (* arr [])() //returning void 

        void (* arr [])() = {};
        -----------------------------------------------------------------


        Extra: Wonder how to declare an array of 3 pointers to functions taking int and returning a pointer to an array of 4 pointers to functions taking double and returning char? (how cool is that, huh? :))
        arr //arr
        arr [3] //is an array of 3 (index it)
        * arr [3] //pointers
        (* arr [3])(int) //to functions taking int (call it) and
        *(* arr [3])(int) //returning a pointer (dereference it)
        (*(* arr [3])(int))[4] //to an array of 4
        *(*(* arr [3])(int))[4] //pointers
        (*(*(* arr [3])(int))[4])(double) //to functions taking double and
        char  (*(*(* arr [3])(int))[4])(double) //returning char
        */
        int  getLevelValue(std::string);
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
    public:
        Harl();
        ~Harl();
        void complain(std::string level);
};
#endif


// (char)(*(*(* arr [3])(int))[4])(double)