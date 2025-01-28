#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BankAccount {
private:
    string accountHolder; // Stores the name of the account holder
    double balance;       // Stores the current balance of the account

public:
    // Constructor to initialize a new account with the account holder's name and initial deposit
    BankAccount(string holder, double initialDeposit) {
        accountHolder = holder;
        balance = initialDeposit;
    }

    // Method to deposit money into the account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        }
        else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Method to withdraw money from the account
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
        }
        else {
            cout << "Invalid withdrawal amount or insufficient funds." << endl;
        }
    }

    // Method to check and display the current balance of the account
    void checkBalance() const {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Current Balance: $" << balance << endl;
    }

    // Method to get the account holder's name (used to identify accounts)
    string getAccountHolder() const {
        return accountHolder;
    }
};

int main() {
    vector<BankAccount> accounts; // Stores all accounts in a vector
    int choice;
    string name;
    double amount;

    while (true) {
        cout << "\n--- Bank Account System ---\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Check Balance\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            // Create a new account
            cout << "Enter account holder's name: ";
            cin >> name;
            cout << "Enter initial deposit: ";
            cin >> amount;

            // Check if account already exists
            bool exists = false;
            for (const auto& account : accounts) {
                if (account.getAccountHolder() == name) {
                    exists = true;
                    break;
                }
            }

            if (!exists) {
                accounts.emplace_back(name, amount);
                cout << "Account created successfully!\n";
            }
            else {
                cout << "Account already exists.\n";
            }
        }
        else if (choice == 2) {
            // Deposit money into an existing account
            cout << "Enter account holder's name: ";
            cin >> name;
            bool found = false;

            for (auto& account : accounts) {
                if (account.getAccountHolder() == name) {
                    cout << "Enter deposit amount: ";
                    cin >> amount;
                    account.deposit(amount);
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Account not found.\n";
            }
        }
        else if (choice == 3) {
            // Withdraw money from an existing account
            cout << "Enter account holder's name: ";
            cin >> name;
            bool found = false;

            for (auto& account : accounts) {
                if (account.getAccountHolder() == name) {
                    cout << "Enter withdrawal amount: ";
                    cin >> amount;
                    account.withdraw(amount);
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Account not found.\n";
            }
        }
        else if (choice == 4) {
            // Check the balance of an existing account
            cout << "Enter account holder's name: ";
            cin >> name;
            bool found = false;

            for (const auto& account : accounts) {
                if (account.getAccountHolder() == name) {
                    account.checkBalance();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Account not found.\n";
            }
        }
        else if (choice == 5) {
            // Exit the program
            cout << "Thank you for using the Bank Account System!\n";
            return 0;
        }
        else {
            cout << "Invalid option. Please try again.\n";
        }
    }
}