#include "bank.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Initialize static member for account number generation
int Bank::cnt = 1000;

Bank::Bank() {
    accountNumber = 0;
    balance = 0.0;
    transactionCount = 0;
}

int Bank::GenerateAccountNumber() {
    return cnt++;
}

void Bank::CreateAccount() {
    accountNumber = GenerateAccountNumber();

    cin.ignore(); // To clear the input buffer
    cout << "Enter account holder's name: ";
    getline(cin, name);

    cout << "Create a password for your account: ";
    getline(cin, password);

    balance = 0.0;
    transactionCount = 0;

    cout << "Account created successfully! Your account number is: " << accountNumber << endl;
}

bool Bank::VerifyAccount(int accNum) {
    return accountNumber == accNum;
}

bool Bank::VerifyPassword(const string& enteredPassword) {
    return password == enteredPassword;
}

void Bank::Deposit() {
    double amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;

    if (amount > 0) {
        balance += amount;
        cout << "Deposit successful! New balance: " << balance << endl;
        // Save transaction history (last 5)
        if (transactionCount < 5) {
            transactionHistory[transactionCount] = "Deposited: " + to_string(amount);
            transactionCount++;
        } else {
            for (int i = 1; i < 5; i++) {
                transactionHistory[i - 1] = transactionHistory[i];
            }
            transactionHistory[4] = "Deposited: " + to_string(amount);
        }
    } else {
        cout << "Invalid deposit amount!" << endl;
    }
}

bool Bank::WithDrawl() {
    double amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;

    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Withdrawal successful!" << endl;
        // Save transaction history (last 5)
        if (transactionCount < 5) {
            transactionHistory[transactionCount] = "Withdrawn: " + to_string(amount);
            transactionCount++;
        } else {
            for (int i = 1; i < 5; i++) {
                transactionHistory[i - 1] = transactionHistory[i];
            }
            transactionHistory[4] = "Withdrawn: " + to_string(amount);
        }
        return true;
    } else {
        cout << "Invalid withdrawal amount!" << endl;
        return false;
    }
}

void Bank::BalEnq() {
    cout << "Current balance: " << balance << endl;
}

void Bank::ChangePassword() {
    string oldPassword, newPassword;
    cout << "Enter old password: ";
    cin >> oldPassword;
    if (oldPassword == password) {
        cout << "Enter new password: ";
        cin >> newPassword;
        password = newPassword;
        cout << "Password changed successfully!" << endl;
    } else {
        cout << "Incorrect old password!" << endl;
    }
}

void Bank::DisplayAccount() {
    cout << "Account Number: " << accountNumber << endl;
    cout << "Account Holder Name: " << name << endl;
    cout << "Balance: " << balance << endl;
}

void Bank::TransactionHistory() {
    cout << "Transaction History (last 5):" << endl;
    for (int i = 0; i < transactionCount; i++) {
        cout << transactionHistory[i] << endl;
    }
}

void Bank::SaveToFile() {
    ofstream outFile("account_" + to_string(accountNumber) + ".txt");
    outFile << "Account Number: " << accountNumber << endl;
    outFile << "Account Holder Name: " << name << endl;
    outFile << "Balance: " << balance << endl;
    outFile << "Transaction History (last 5):" << endl;
    for (int i = 0; i < transactionCount; i++) {
        outFile << transactionHistory[i] << endl;
    }
    outFile.close();
    cout << "Account details saved to file." << endl;
}
void Bank::TransferMoney(double amount, Bank& toAccount) {
    if (amount > 0 && amount <= balance) {
        // Perform the transfer
        balance -= amount;
        toAccount.balance += amount;
        cout << "Transfer successful! Your new balance: " << balance << endl;

        // Log the transaction in sender's history
        if (transactionCount < 5) {
            transactionHistory[transactionCount] = "Transferred: " + to_string(amount) + " to account " + to_string(toAccount.accountNumber);
            transactionCount++;
        } else {
            for (int i = 1; i < 5; i++) {
                transactionHistory[i - 1] = transactionHistory[i];
            }
            transactionHistory[4] = "Transferred: " + to_string(amount) + " to account " + to_string(toAccount.accountNumber);
        }

        // Log the transaction in receiver's history
        if (toAccount.transactionCount < 5) {
            toAccount.transactionHistory[toAccount.transactionCount] = "Received: " + to_string(amount) + " from account " + to_string(accountNumber);
            toAccount.transactionCount++;
        } else {
            for (int i = 1; i < 5; i++) {
                toAccount.transactionHistory[i - 1] = toAccount.transactionHistory[i];
            }
            toAccount.transactionHistory[4] = "Received: " + to_string(amount) + " from account " + to_string(accountNumber);
        }
    } else {
        cout << "Invalid transfer amount!" << endl;
    }
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        