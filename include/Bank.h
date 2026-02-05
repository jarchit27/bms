#pragma once

#include <vector>
#include <string>
#include <Account.h>

class Bank
{
private:
    std::vector<Account> accounts;
    int nextAccountNumber;

public:


    Bank();
    Account& createAccount(const std::string& name, double initialBalance);
    Account& createAccount(const std::string& name);

    Account* findAccount(int accountNo);

    bool transfer(int fromAcc, int toAcc, double amount);
};