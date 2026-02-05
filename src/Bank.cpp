#pragma once
#include<Bank.h>


Bank::Bank(): nextAccountNumber(1001) {}
 
// emplace_back constructs the Account object directly inside the vector
// 1. Vector allocates memory for the new element
// 2. Account is constructed in-place using the given arguments
// This avoids creating a temporary object and avoids copy/move operations

Account& Bank::createAccount(const std::string& name, double initialBalance){
    accounts.emplace_back(name, nextAccountNumber ,initialBalance);
    nextAccountNumber++;
    return accounts.back();
}

Account& Bank::createAccount(const std::string& name){
    accounts.emplace_back(name,nextAccountNumber);
    nextAccountNumber++;
    return accounts.back();
}

Account* Bank::findAccount(int accNumber){
    for( auto& account : accounts)
    {
        if (accNumber == account.getAccountNumber())
        {
            return &account;
        }
    }
    return NULL;
}

bool Bank::transfer(int  fromAcc, int toAcc, double amount){
    Account* fromAccount = findAccount(fromAcc);
    Account* toAccount = findAccount(toAcc);

    // Withdraw first (this enforces all account rules)
    if (!fromAccount->withdraw(amount)) {
        return false; // insufficient balance
    }

    toAccount->deposit(amount);

    return true;
}