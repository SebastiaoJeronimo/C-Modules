#include <iostream> // read and write to the console
#include <fstream>  // read and write to files

#include <string>
#include <string.h>

//c++ -std=c++98 *.cpp *.hpp && valgrind ./a.out
int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "-------------ERROR-------------" << "\n";
        std::cout << "This program expects exactly 3 arguments" << "\n";
        std::cout << "1st argument is the name of the file that we are going to copy and replace" << "\n";
        std::cout << "2nd argument is the string that we are going to replace" << "\n";
        std::cout << "3rd argument is the string that we are going to replace the 2nd argument with" << "\n";
        return 1;
    }


    /*
    //how to write into a text file
    std::fstream myFile; 
    myFile.open("test.txt", std::ios::out); //name of the file , and the mode (write mode in this case)
    
    if (myFile.is_open()) //check if the file is open
    {
        std::cout << "File opened successfully" << std::endl;
        myFile << "First Line\n";
        myFile << "Second Line\n";
        myFile.close();
    }
    else
    {
        std::cout << "Error opening the file" << std::endl;
        return 1;
    }

    //how to read from a text file
    std::fstream myFile2;
    myFile2.open("test.txt", std::ios::in); //name of the file , and the mode (read mode in this case)
    if (myFile2.is_open()) //check if the file is open
    {
        std::cout << "File opened successfully" << std::endl;
        std::string line;
        while (std::getline(myFile2, line))
        {
            std::cout << line << std::endl;
        }
        myFile2.close();
    }
    else
    {
        std::cout << "Error opening the file" << std::endl;
        return 1;
    }
    */

    std::fstream inputFile;
    std::fstream outputFile;


    inputFile.open(argv[1], std::ios::in);         //name of the file , and the mode (read mode in this case)
    outputFile.open("newFile.txt", std::ios::out); //name of the file , and the mode (write mode in this case)

    if (!inputFile.is_open() || !outputFile.is_open())
    {
        std::cout << "file opening error" << "\n";
        return 1;
    }


    //HOW TO TRANSFORM char *str to std::string str 
    //You can use the std::string constructor std::string str(char *str)

    std::string     textLine;
    int             indexReplace;
    while (std::getline(inputFile, textLine))
    {
            indexReplace = textLine.find(std::string(argv[2]));
            while (std::string::npos != indexReplace)
            {
                //std::cout << indexReplace << "\n";
                //std::cout << textLine <<  "\n";
                textLine = textLine.substr(0,indexReplace) + std::string(argv[3]) + textLine.substr(indexReplace + strlen(argv[2]),textLine.length());
                indexReplace = textLine.find(std::string(argv[2]));
            }
            outputFile << textLine;
    }
}