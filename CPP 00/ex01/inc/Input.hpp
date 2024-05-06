#ifndef INPUT_HPP
#define INPUT_HPP

#define EXIT_STR "EXIT"
#define ADD_STR "ADD"
#define SEARCH_STR "SEARCH"
#define SEPARATOR "|"

#define EXIT 1
#define ADD 2
#define SEARCH 3
#define OTHER 42

#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>
#include <stdlib.h> 

void displayContact(PhoneBook &PhoneBook);
std::string cropInfo(std::string info);
void buildAndPrintLine(std::string str1, std::string str2, std::string str3, std::string str4);
void searchContactTable(PhoneBook &PhoneBook);
void showMenu();
void unsupportedCommand();
int getCommand();
void getContactInfo(std::string &firstName, std::string &lastName, std::string &nickName, std::string &phoneNumber, std::string &darkestSecret);
void addContact(PhoneBook &PhoneBook);
void displayContact(PhoneBook &PhoneBook);
std::string cropInfo(std::string info);
#endif