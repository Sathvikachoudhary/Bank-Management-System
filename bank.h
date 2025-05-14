#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Bank {
private:
    static int cnt; 
    int accountNumber;
    string name;
    string password;
    double balance;
    int transactionCount; 
        string transactionHistory[5];

public:
    Bank(); 
    static int GenerateAccountNumber();  
    void CreateAccount();  
    bool VerifyAccount(int accNum);  
    bool VerifyPassword(const string& enteredPassword); 
    void Deposit();  
    bool WithDrawl();
    void BalEnq();  
    void ChangePassword(); 
    void DisplayAccount();  
    void TransactionHistory();  
    void SaveToFile();  
    void TransferMoney(double amount, Bank& toAccount);  
};

#endif