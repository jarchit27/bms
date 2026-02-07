#include<Bank.h>
#include<memory>
    
Bank::Bank(double minBalance, double overdraftLmt) : nextAccountNumber(1001)
{
    SavingsAccount::setMinimumBalance(minBalance);
    CurrentAccount::setOverdraftLimit(overdraftLmt);
}

// emplace_back constructs the Account object directly inside the vector
// 1. Vector allocates memory for the new element
// 2. Account is constructed in-place using the given arguments
// This avoids creating a temporary object and avoids copy/move operations

Account& Bank::createSavingAcc(const std::string& name, double initialBal){
    accounts.push_back(std::make_unique<SavingsAccount>(name,nextAccountNumber,initialBal));
    nextAccountNumber++;
    return *accounts.back();
}

Account& Bank::createCurrentAcc(const std::string& name ,double initialBal){
    accounts.push_back(std::make_unique<CurrentAccount>(name,nextAccountNumber,initialBal));
    nextAccountNumber++;
    return *accounts.back();
}

Account* Bank::findAccount(int accNumber){
    for( auto& account : accounts)
    {
        if (accNumber == account->getAccountNumber())
        {
            return account.get();
        }
    }
    return NULL;
}

bool Bank::transfer(int  fromAcc, int toAcc, double amount){
    Account* fromAccount = findAccount(fromAcc);
    Account* toAccount = findAccount(toAcc);

    if (!fromAccount || !toAccount) return false;

    // Withdraw first (this enforces all account rules)
    if (!fromAccount->withdraw(amount)) {
        return false; // insufficient balance
    }

    toAccount->deposit(amount);

    return true;
}