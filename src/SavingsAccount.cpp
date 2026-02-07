#include "Account.h"
#include "SavingsAccount.h"
#include<string>

double SavingsAccount::minimumBalance = 0.0;

SavingsAccount::SavingsAccount(const std::string& name, int accNumber, double initialBalance):Account(name,accNumber,initialBalance) {};

double SavingsAccount::getMinBalance() {
    return minimumBalance;
}

void SavingsAccount::setMinimumBalance(double minBalance) {
    minimumBalance = minBalance;
}

bool SavingsAccount::withdraw(double amount) {
    if (amount <= 0)
        return false;

    if (balance - amount < minimumBalance)
        return false;

    balance -= amount;
    return true;
}
