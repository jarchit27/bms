#include <iostream>
#include "Bank.h"

void showMenu() {
    std::cout << "\n==== Bank Management System ====\n";
    std::cout << "1. Create Account\n";
    std::cout << "2. Deposit Money\n";
    std::cout << "3. Withdraw Money\n";
    std::cout << "4. Check Balance\n";
    std::cout << "5. Transfer Money\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Bank bank;
    int choice;

    while (true) {
        showMenu();
        std::cin >> choice;

        if (choice == 1) {
            std::string name;
            std::cout << "Enter owner name: ";
            std::cin >> name;

            Account& acc = bank.createAccount(name);
            std::cout << "Account created successfully.\n";
            std::cout << "Account Number: " << acc.getAccountNumber() << "\n";
        }

        else if (choice == 2) {
            int accNo;
            double amount;

            std::cout << "Enter account number: ";
            std::cin >> accNo;

            Account* acc = bank.findAccount(accNo);
            if (!acc) {
                std::cout << "Account not found.\n";
                continue;
            }

            std::cout << "Enter amount to deposit: ";
            std::cin >> amount;
            if (amount <= 0)
            {
                std::cout << "Invalid deposit amount.\n";
                continue;
            }
            acc->deposit(amount);
            std::cout << "Deposit successful.\n";
        }

        else if (choice == 3) {
            int accNo;
            double amount;

            std::cout << "Enter account number: ";
            std::cin >> accNo;

            Account* acc = bank.findAccount(accNo);
            if (!acc) {
                std::cout << "Account not found.\n";
                continue;
            }

            std::cout << "Enter amount to withdraw: ";
            std::cin >> amount;
            if (amount <= 0)
            {
                std::cout << "Invalid withdrawal amount.\n";
                continue;
            }
            if (acc->withdraw(amount)) {
                std::cout << "Withdrawal successful.\n";
            } else {
                std::cout << "Insufficient balance.\n";
            }
        }

        else if (choice == 4) {
            int accNo;
            std::cout << "Enter account number: ";
            std::cin >> accNo;

            Account* acc = bank.findAccount(accNo);
            if (!acc) {
                std::cout << "Account not found.\n";
            } else {
                std::cout << "Account Number: " << acc->getAccountNumber() << "\n";
                std::cout << "Account Holder: " << acc->getOwnerName() << "\n";
                std::cout << "Current balance: " << acc->getBalance() << "\n";
            }
        }

        else if (choice == 5) {
            int fromAcc, toAcc;
            double amount;

            std::cout << "From Account Number: ";
            std::cin >> fromAcc;

            Account* fromAccount = bank.findAccount(fromAcc);
            if (!fromAccount) {
                std::cout << "From account not found.\n";
                continue;
            }

            std::cout << "To Account Number: ";
            std::cin >> toAcc;

            Account* toAccount = bank.findAccount(toAcc);
            if (!toAccount) {
                std::cout << "To account not found.\n";
                continue;
            }
            if (fromAcc == toAcc) {
                std::cout << "Cannot transfer to the same account.\n";
                continue;
            }


            std::cout << "Amount to transfer: ";
            std::cin >> amount;

            if (amount <= 0)
            {
                std::cout << "Invalid transfer amount.\n";
                continue;
            }

            if (bank.transfer(fromAcc, toAcc, amount)) {
                std::cout << "Transfer successful.\n";
            } else {
                std::cout << "Transfer failed. Check account balance.\n";
            }
        }

        else if (choice == 6) {
            std::cout << "Thank you for using the Bank System.\n";
            break;
        }
        else {
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}