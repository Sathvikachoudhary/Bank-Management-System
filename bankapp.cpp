#include <iostream>
#include <string>
#include "bank.h"

using namespace std;

int main() {
    const int MAX_ACCOUNTS = 100;  // Maximum number of accounts
    Bank accounts[MAX_ACCOUNTS];   // Array of accounts
    int currentAccountCount = 0;   // Keeps track of the number of accounts created

    char choice;

    while (true) {
        cout << "===== Bank Menu =====" << endl;
        cout << "c/C: Create Account" << endl;
        cout << "d/D: Deposit" << endl;
        cout << "w/W: Withdraw" << endl;
        cout << "b/B: Balance Enquiry" << endl;
        cout << "p/P: Change Password" << endl;
        cout << "h/H: Transaction History (Last 5)" << endl;
        cout << "a/A: Display Account Details" << endl;
        cout << "s/S: Save Account to File" << endl;
        cout << "f/F: Search Account" << endl;
        cout << "t/T: Transfer Money" << endl;
        cout << "e/E: Display All Accounts" << endl;
        cout << "q/Q: Quit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'c': case 'C': {
                if (currentAccountCount < MAX_ACCOUNTS) {
                    accounts[currentAccountCount].CreateAccount();
                    currentAccountCount++;
                } else {
                    cout << "Account limit reached!" << endl;
                }
                break;
            }
            case 'd': case 'D': {
                int accNum;
                string password;

                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter password: ";
                cin >> password;

                bool found = false;
                for (int i = 0; i < currentAccountCount; i++) {
                    if (accounts[i].VerifyAccount(accNum)) {
                        if (accounts[i].VerifyPassword(password)) {
                            accounts[i].Deposit();
                        } else {
                            cout << "Incorrect password!" << endl;
                        }
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account not found!" << endl;
                }
                break;
            }
            case 'w': case 'W': {
                int accNum;
                string password;

                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter password: ";
                cin >> password;

                bool found = false;
                for (int i = 0; i < currentAccountCount; i++) {
                    if (accounts[i].VerifyAccount(accNum)) {
                        if (accounts[i].VerifyPassword(password)) {
                            if (!accounts[i].WithDrawl()) {
                                cout << "Withdrawal failed!" << endl;
                            }
                        } else {
                            cout << "Incorrect password!" << endl;
                        }
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account not found!" << endl;
                }
                break;
            }
            case 'b': case 'B': {
                int accNum;
                string password;

                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter password: ";
                cin >> password;

                bool found = false;
                for (int i = 0; i < currentAccountCount; i++) {
                    if (accounts[i].VerifyAccount(accNum)) {
                        if (accounts[i].VerifyPassword(password)) {
                            accounts[i].BalEnq();
                        } else {
                            cout << "Incorrect password!" << endl;
                        }
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account not found!" << endl;
                }
                break;
            }
            case 'p': case 'P': {
                int accNum;
                string password;

                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter password: ";
                cin >> password;

                bool found = false;
                for (int i = 0; i < currentAccountCount; i++) {
                    if (accounts[i].VerifyAccount(accNum)) {
                        if (accounts[i].VerifyPassword(password)) {
                            accounts[i].ChangePassword();
                        } else {
                            cout << "Incorrect password!" << endl;
                        }
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account not found!" << endl;
                }
                break;
            }
            case 'h': case 'H': {
                int accNum;

                cout << "Enter account number: ";
                cin >> accNum;

                bool found = false;
                for (int i = 0; i < currentAccountCount; i++) {
                    if (accounts[i].VerifyAccount(accNum)) {
                        accounts[i].TransactionHistory();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account not found!" << endl;
                }
                break;
            }
            case 'a': case 'A': {
                int accNum;

                cout << "Enter account number: ";
                cin >> accNum;

                bool found = false;
                for (int i = 0; i < currentAccountCount; i++) {
                    if (accounts[i].VerifyAccount(accNum)) {
                        accounts[i].DisplayAccount();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account not found!" << endl;
                }
                break;
            }
            case 's': case 'S': {
                int accNum;

                cout << "Enter account number: ";
                cin >> accNum;

                bool found = false;
                for (int i = 0; i < currentAccountCount; i++) {
                    if (accounts[i].VerifyAccount(accNum)) {
                        accounts[i].SaveToFile();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account not found!" << endl;
                }
                break;
            }
            case 'f': case 'F': {
                int accNum;

                cout << "Enter account number: ";
                cin >> accNum;

                bool found = false;
                for (int i = 0; i < currentAccountCount; i++) {
                    if (accounts[i].VerifyAccount(accNum)) {
                        accounts[i].DisplayAccount();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account not found!" << endl;
                }
                break;
            }
            case 't': case 'T': {
                int fromAcc, toAcc;
                double amount;
                string password;

                cout << "Enter sender account number: ";
                cin >> fromAcc;
                cout << "Enter password: ";
                cin >> password;

                bool found = false;
                for (int i = 0; i < currentAccountCount; i++) {
                    if (accounts[i].VerifyAccount(fromAcc)) {
                        if (accounts[i].VerifyPassword(password)) {
                            cout << "Enter receiver account number: ";
                            cin >> toAcc;
                            cout << "Enter amount to transfer: ";
                            cin >> amount;

                            bool receiverFound = false;
                            for (int j = 0; j < currentAccountCount; j++) {
                                if (accounts[j].VerifyAccount(toAcc)) {
                                    accounts[i].TransferMoney(amount, accounts[j]);
                                    receiverFound = true;
                                    break;
                                }
                            }
                            if (!receiverFound) {
                                cout << "Receiver account not found!" << endl;
                            }
                        } else {
                            cout << "Incorrect password!" << endl;
                        }
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Sender account not found!" << endl;
                }
                break;
            }
            case 'e': case 'E': {
                for (int i = 0; i < currentAccountCount; i++) {
                    accounts[i].DisplayAccount();
                }
                break;
            }
            case 'q': case 'Q':
                cout << "Exiting the program!" << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
