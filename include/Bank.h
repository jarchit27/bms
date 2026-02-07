#pragma once

#include <vector>
#include <string>
#include <memory>

#include <Account.h>
#include <SavingsAccount.h>
#include<CurrentAccount.h>

class Bank
{
private:
    std::vector<std::unique_ptr<Account>> accounts;
    int nextAccountNumber;
public:

    Bank(double minBalance , double overdraftLimit);
    Account& createSavingAcc(const std::string& name,double initialBal);
    Account& createCurrentAcc(const std::string& name,double initialBal);

    Account* findAccount(int accountNo);

    bool transfer(int fromAcc, int toAcc, double amount);
};
