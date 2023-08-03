#include "bankAccount.h"
#include <iostream>
#include <iomanip>

using namespace std;

bankAccount::bankAccount(int acctNumber, double bal)
{
    accountNumber = acctNumber;
    balance = bal;
}


double bankAccount::getBalance() const
{
    return balance;
}

int bankAccount::getAccountNumber() const
{
    return accountNumber;
}

void bankAccount::deposit(double amount)
{
    balance += amount;
}

void bankAccount::withdraw(double amount)
{
    balance -= amount;
}

void bankAccount::setAccountNumber(int acct)
{
    accountNumber = acct;
}

void bankAccount::print() const
{
    cout << fixed << setprecision(2);
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: "  <<  balance << endl;
}
