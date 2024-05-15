#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <string>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//TESTAR SE FUNCIONA CONSTRUTOR SEM PARAMETROS CHAMA O COM PARAMETROS MAS COM UM 0
Account::Account() {}

//g++ tests.cpp Account.cpp -o output && ./output
Account::Account(int initial_deposit)
{
    _displayTimestamp();
    _amount = initial_deposit;
    this->_accountIndex = _nbAccounts;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    
    //static members
    _totalAmount += initial_deposit;
    _nbAccounts +=  1;
    
    //checkar se certo
    std::cout << "index:" << this->_accountIndex  << ";amount:" 
    << this->_amount << ";created" << "\n";
}

Account::~Account() { 
    _displayTimestamp();
    //TODO Destructor message
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
                << ";closed" << "\n";
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    _totalNbDeposits++;
    this->_nbDeposits++;
    int previous = this->_amount;
    this->_amount += deposit;
    _totalAmount += deposit;

    //checkar se certo
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << previous 
			  << ";deposit:" << deposit << ";amount:" << this->_amount
			  << ";nb_deposits:" << this->_nbDeposits << "\n"; 
}

//ADD THIS TO THE CLASS atributes
//maybe if the account has enough money returns true if not false
bool Account::makeWithdrawal(int withdrawal)
{
     _displayTimestamp();
     if (withdrawal > this->_amount)
     {
        //checkar se certo
        std::cout << "index:" << this->_accountIndex  << ";p_amount:" 
        << this->_amount << ";withdrawal:refused" << "\n";
        return false; 
     }
        
     int previous = this->_amount;
     this->_amount -= withdrawal;
     this->_nbWithdrawals++;
     _totalNbWithdrawals++;
     _totalAmount -= withdrawal;
     std::cout << "index:" << _accountIndex << ";p_amount:" << previous 
	 << ";withdrawal:" << withdrawal << ";amount:" << _amount
	 << ";nb_withdrawals:" << _nbWithdrawals << "\n";
     return true;
}

int Account::checkAmount() const {
    return this->_amount;
}

void Account::displayStatus() const {
     //TODO
     _displayTimestamp();
     std::cout << "index:" << _accountIndex << ";amount:" << _amount 
			  << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << "\n";  
}
 
void Account::displayAccountsInfos() {
     //TODO
     _displayTimestamp();
     std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() 
			  << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << "\n"; 
}

//getters for the static members
int Account::getNbAccounts() {return _nbAccounts;}
int Account::getTotalAmount() {return _totalAmount;}
int Account::getNbDeposits() {return _totalNbDeposits;}
int Account::getNbWithdrawals() {return _totalNbWithdrawals;}

void Account::_displayTimestamp() 
{
    std::time_t time = std::time(0);
    char formattedTime[17];
    strftime(formattedTime, 18, "%Y%m%d_%H%M%S] ", localtime(&time));
    std::cout << std::string("[") + formattedTime;
}


