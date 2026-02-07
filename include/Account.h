#pragma once

#include <string>

class Account {

protected:
    std::string ownerName;
    int accountNumber;
    double balance;

public:
    // Constructor
    Account(const std::string &name, int accNumber, double initialBalance);
    Account(const std::string &name, int accNumber);

    // Destructor
    virtual ~Account() = default;
    
    // Read-only accessors
    double getBalance() const;
    std::string getOwnerName() const;
    int getAccountNumber() const;

    // Operations
    void deposit(double amount);
    virtual bool withdraw(double amount) = 0;
};