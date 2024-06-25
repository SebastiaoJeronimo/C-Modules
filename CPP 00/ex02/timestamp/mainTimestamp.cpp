//this main is for testing the timestamp

#include <iostream>
#include <ctime>

//g++ mainTimestamp.cpp && ./a.out
int main ()
{
    //IN THE LOG FILE THE TIMESTAMP WILL BE IN THE FORMAT: [YYYYMMDD_HHMMSS]
    // "[ YEAR + MONTH + DAY + _ + HOUR + MINUTE + SECOND ]"

    //std::time_t time( std::time_t* arg );
    //stores it in the object pointed to by arg, unless arg is a null pointer.
    //std::time_t is a type that holds the time in seconds since 00:00:00 UTC, January 1, 1970
    std::time_t time = std::time(0);
    //Unix engineers arbitrarily selected 1 January 1970 00:00:00 UTC 
    std::cout << time << " this corresponds to the number of seconds since the Epoch\n";

    //char* asctime (const struct tm * timeptr);
    //Www Mmm dd hh:mm:ss yyyy
    //Www is the weekday, Mmm the month, dd the day of the month, hh:mm:ss the time, and yyyy the year.
    std::cout << asctime(localtime(&time)) << "time function used in localTime\n";
    std::cout << "UTC:   " << std::gmtime(&time) << '\n';
    std::cout << "local: " << std::localtime(&time) << '\n';

    //to format the time we will use strftime
    //returns the number of characters written in the array, not counting the terminating null character.
    //char* strftime (char* ptr, size_t maxsize, const char* format, const struct tm* timeptr);
    char formattedTime[18];
    strftime(formattedTime, 18, "[%Y%m%d_%H%M%S]", localtime(&time));
    std::cout << "local with format:   " << formattedTime << '\n';
    strftime(formattedTime, 18, "[%Y_%H]", gmtime(&time));
    std::cout << "UTC with format: just the year and the hour in 24h format" << formattedTime << '\n';

     std::cout << "return of local with format:   " <<  strftime(0, 18, "[%Y%m%d_%H%M%S]", std::localtime(&time)) << '\n';
    std::cout << "return of UTC with format:     " <<  strftime(0, 18, "[%Y%m%d_%H%M%S]", std::gmtime(&time)) << '\n';
}
