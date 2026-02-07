#include "Account.h"
#include "CurrentAccount.h"
#include<string>

// REQUIRED static definition
double CurrentAccount::overdraftLimit = 0.0;

CurrentAccount::CurrentAccount(const std::string &name, int accNumber, double initialBalance) : Account(name, accNumber, initialBalance) {};

void CurrentAccount::setOverdraftLimit(double minBalance){
    overdraftLimit = minBalance;
}

bool CurrentAccount::withdraw(double amount){
    if (amount <= 0)
        return false;

    if (balance + overdraftLimit < amount )
        return false;

    balance -= amount;
    return true;
}