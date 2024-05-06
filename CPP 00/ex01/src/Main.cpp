#include "Input.hpp"

int main ()
{
    PhoneBook PhoneBook;
    showMenu();
    int command = getCommand();
    while (command != EXIT)
    {
        switch (command)
        {
        case ADD:
            addContact(PhoneBook);
            break;
        case SEARCH:
            searchContactTable(PhoneBook);
            break;
        default:
            unsupportedCommand();
            break;
        }
        command = getCommand();
    }
}

void addContact(PhoneBook &PhoneBook) //NOT HAVE EMPTY FIELDS
{
    std::string firstName, lastName , nickName, phoneNumber, darkestSecret;
    std::cout << "Enter the first name\n";
    std::getline(std::cin, firstName);
    std::cout << "Enter the last name\n";
    std::getline(std::cin, lastName);
    std::cout << "Enter the nick name\n";
    std::getline(std::cin, nickName);
    std::cout << "Enter the phone number\n";
    std::getline(std::cin, phoneNumber);
    std::cout << "Enter the darkest secret\n";
    std::getline(std::cin, darkestSecret);
    PhoneBook.addContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
}

int getCommand()
{
    std::string commandString;
    std::cout << "Please choose a command:\n";
    std::getline(std::cin, commandString); //manda o que esta no input para a variavel commandString
    if (commandString == ADD_STR)
        return ADD;
    if (commandString == SEARCH_STR)
        return SEARCH;
    if (commandString == EXIT_STR)
        return EXIT;
    return OTHER;
}

void unsupportedCommand()
{
    std::cout << "Please choose a supported command from those bellow\n";
    showMenu();
}

void showMenu()
{
    std::cout << "======COMMANDS AVAILABLE======\n";
    std::cout << "ADD    to save a new contact\n";
    std::cout << "SEARCH to display a specific contact\n";
    std::cout << "EXIT   to quit the program\n";
}

void searchContactTable(PhoneBook &PhoneBook)
{
    int numContacts = PhoneBook.getCounter();
    if (numContacts == 0)
    {
        std::cout << "There are no contacts in this phoneBook\n";
        return;
    }
    buildAndPrintLine("index", "first name", "last name", "nickname");
    for (int i = 0 ; i < numContacts; i++)
    {
        Contact contact = PhoneBook.getContact(i);
        std::stringstream ss; // to convert int to string
        std::string indexString;
        ss << i+1;
        ss >>indexString;
        buildAndPrintLine(indexString, contact.getFirstName(), contact.getLastName(), contact.getNickname());
    }
    displayContact(PhoneBook);
}

void buildAndPrintLine(std::string str1, std::string str2, std::string str3, std::string str4){
    std::cout << cropInfo(str1) << SEPARATOR;
    std::cout << cropInfo(str2) << SEPARATOR;
    std::cout << cropInfo(str3) << SEPARATOR;
    std::cout << cropInfo(str4) << SEPARATOR << "\n";
}
 
std::string cropInfo(std::string info) {
       int begin = info.find_first_not_of(" \t");
       int end = info.find_last_not_of(" \t");
       if (begin == (int) std::string::npos)
            info = " "; //so pq sim
       else info.substr(begin, end);
       if (info.length() > 10)
              return info.substr(0, 9) + ".";
       int numSpaces = 10 - info.length(); //num space chars to add 
       std::string str = "";
       for(int i = 0; i<numSpaces; i++)
              str += " ";
       return str+info;
}

void displayContact(PhoneBook &PhoneBook)
{
    std::string strindex;
    std::cout << "Enter the index of the contact you want to display\n";
    std::cin >> strindex;
    int index = atoi(strindex.c_str()); 
    if (index <= 0 || index > PhoneBook.getCounter()) //counter a 0 erro atoi de ahifehf
    {
        std::cout << "Invalid index\n";
        return;
    }
    Contact contact = PhoneBook.getContact(index-1);
    std::cout << "First name: " << contact.getFirstName() << "\n";
    std::cout << "Last name: " << contact.getLastName() << "\n";
    std::cout << "Nick name: " << contact.getNickname() << "\n";
    std::cout << "Phone number: " << contact.getPhoneNumber() << "\n";
    std::cout << "Darkest secret: " << contact.getDarkestSecret() << "\n";
}