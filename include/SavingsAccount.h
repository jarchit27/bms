#pragma once

#include "Account.h"
#include<string> 

class SavingsAccount : public Account
{
private:
    static double minimumBalance ;
public:
    void static setMinimumBalance(double minBalance);
    SavingsAccount(const std::string &name, int accNumber,double initialBalance);
    double getMinBalance();
    bool withdraw(double amount) override;
};