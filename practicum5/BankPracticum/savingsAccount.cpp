#include "savingsAccount.h"
#include <iostream>
#include <iomanip>

using namespace std;

/*
private:
    double interestRate;
public:

*/

savingsAccount::savingsAccount(double acctNumber, double bal, double intRate)
{
    accountNumber = acctNumber;
    balance = bal;
    interestRate = intRate;
}

void savingsAccount::setInterestRate(double intRate)
{
    interestRate = intRate;
}

double savingsAccount::getInterestRate() const
{
    return interestRate;
}

void savingsAccount::postInterest()
{
    balance += balance*interestRate;
}

void savingsAccount::withdraw(double amount)
{
    if(balance - amount < 0)
    {
        cout << "Insufficient funds to withdraw that amount" << endl;
    }
    else    
        balance -= amount;
}

void savingsAccount::print() const
{
    cout << fixed << setprecision(2);
    bankAccount::print();
    cout << "Interest Rate: " << interestRate << endl;
}

