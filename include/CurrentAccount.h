#pragma once

#include "Account.h"
#include<string>


class CurrentAccount : public Account
{
private:
    static double overdraftLimit;
    
public:
    static void setOverdraftLimit(double overdraftLmt);
    CurrentAccount(const std::string &name, int accNumber, double initialBalance);
    bool withdraw(double amount) override;
};