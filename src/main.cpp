#include <iostream>
#include "Bank.h"

using namespace std;

int main()
{
    cout << "===== BANK SYSTEM DEMO RUN =====\n\n";

    // Create bank with rules
    Bank bank(1000.0, 2000.0);   // minBalance, overdraftLimit

    // Create accounts
    Account& acc1 = bank.createSavingAcc("Archit", 5000);
    Account& acc2 = bank.createCurrentAcc("Rahul", 3000);

    cout << "Accounts created\n";
    cout << "Savings Account No: " << acc1.getAccountNumber() << "\n";
    cout << "Current Account No: " << acc2.getAccountNumber() << "\n\n";

    // Deposit
    cout << "Depositing 2000 into Savings Account\n";
    acc1.deposit(2000);
    cout << "Balance: " << acc1.getBalance() << "\n\n";

    // Withdraw
    cout << "Withdrawing 1000 from Current Account\n";
    if (acc2.withdraw(1000))
        cout << "Withdrawal successful\n";
    else
        cout << "Withdrawal failed\n";

    cout << "Balance: " << acc2.getBalance() << "\n\n";

    // Transfer
    cout << "Transferring 1500 from Savings to Current\n";
    if (bank.transfer(
        acc1.getAccountNumber(),
        acc2.getAccountNumber(),
        1500))
        cout << "Transfer successful\n";
    else
        cout << "Transfer failed\n";

    cout << "\nFinal Account Status\n";
    cout << "---------------------\n";

    cout << "Savings Balance : " << acc1.getBalance() << "\n";
    cout << "Current Balance : " << acc2.getBalance() << "\n";

    cout << "\n===== DEMO COMPLETED =====\n";
    return 0;
}
