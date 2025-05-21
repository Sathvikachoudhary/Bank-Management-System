
# 🏦 BANKING MANAGEMENT SYSTEM
## 📚 PROJECT OVERVIEW:
This is a Banking Management System developed in C++, using classes and file handling. It simulates basic banking operations like account creation, deposits, withdrawals, fund transfers, balance checks, and transaction history. Each user has a secure password-protected account and transactions are tracked for every account during runtime.
## 📋 KEY FEATURES:
🔐 Password-protected account actions  
🔢 Auto-generated Account Number using static counter  
➕ Create a new bank account  
💰 Deposit funds (with password)  
💸 Withdraw funds (with password & balance check)  
🔍 Search account by account number  
💳 Transfer funds between accounts  
📜 View last 5 transactions  
📊 Check account balance (with password)  
🧾 Display individual account details  
📂 Display all accounts  
🔑 Change account password  
💾 Save account details to text file  
❌ Exit the application  
## 📂 FILE STRUCTURE:
📦 Banking-Management-System/
- ├── 🧾 `bankapp.cpp` -> Menu-driven main program logic
- ├── 🧾 `bank.cpp` -> Bank class definitions and operations
- ├── 📘 `bank.h` -> Class declarations & function prototypes
## ⚙️ HOW TO COMPILE AND RUN:
### ✅ METHOD 1: Manual Compilation
- g++ bankapp.cpp bank.cpp -o banking_system
- `./banking_system`        # For Linux/macOS
- `banking_system.exe`      # For Windows
### ✅ METHOD 2: Using Makefile (Optional)
- `banking_system`: bankapp.o bank.o
  g++ bankapp.o bank.o -o banking_system
- `bankapp.o`: bankapp.cpp
  g++ -c bankapp.cpp
- `bank.o`: bank.cpp
  g++ -c bank.cpp
- clean:
	rm -f *.o `banking_system`
- To compile: `make`
- To run: `./banking_system`
## 🖥️ MENU OPTIONS:
1. Create Account
2. Deposit Money
3. Withdraw Money
4. Balance Enquiry
5. View Last 5 Transactions
6. Display Account Details
7. Search Account by Number
8. Transfer Money
9. Change Password
10. Display All Accounts
11. Save Account to File
12. Exit

# Happy Coding....!
