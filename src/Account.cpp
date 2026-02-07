#include <string>
#include <iostream>
#include "Account.h"

// Constructor
Account::Account(const std::string &name, int accNumber, double initialBalance): ownerName(name), accountNumber(accNumber), balance(initialBalance){};

Account::Account(const std::string &name, int accNumber):ownerName(name){
    accountNumber = accNumber;
    balance = 0.0;
}

// Read-only accessors
double Account::getBalance() const {
    return balance;
}

int Account::getAccountNumber() const {
    return accountNumber;
}

std::string Account::getOwnerName() const {
    return ownerName;
}

// Operations
void Account::deposit(double amount){    
    balance+= amount;
}