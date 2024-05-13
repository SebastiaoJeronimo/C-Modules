#include "Account.hpp"


//TESTAR SE FUNCIONA CONSTRUTOR SEM PARAMETROS CHAMA O COM PARAMETROS MAS COM UM 0
Account::Account() {Account(0);}

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    //static members
    _nbAccounts =+ 1;
    _totalAmount =+ initial_deposit;
}

Account::~Account() {}

void Account::makeDeposit(int deposit)
{
    _totalNbDeposits++;
    _nbDeposits++;
    _amount =+ deposit;
}

//maybe if the account has enough money returns true if not false
bool Account::makeWithdrawal(int withdrawal)
{
     //TODO
}

int Account::checkAmount() const {
    return _amount;
}

void Account::displayStatus() const {
     //TODO
}
 
void Account::displayAccountsInfos() {
     //TODO
}

//getters for the static members
int Account::getNbAccounts() {return _nbAccounts;}
int Account::getTotalAmount() {return _totalAmount;}
int Account::getNbDeposits() {} //TODO
int Account::getNbWithdrawals() {} //TODO

void Account::_displayTimestamp() 
{
    //TO DO
}


