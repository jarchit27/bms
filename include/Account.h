#pragma once

#include <string>

class Account {

private:
    std::string ownerName;
    int accountNumber;
    double balance;

public:
    // Constructor
    Account(const std::string &name, int accNumber, double initialBalance);
    Account(const std::string &name, int accNumber);
    
    // Read-only accessors
    double getBalance() const;
    std::string getOwnerName() const;
    int getAccountNumber() const;

    // Operations
    void deposit(double amount);
    bool withdraw(double amount);
};