

#include "checkingAccount.h"
#include <iostream>
#include <iomanip>
using namespace std;

checkingAccount::checkingAccount(double acctNumber, double bal, double minBal, double intRate, double servC)
{
    accountNumber = acctNumber;
    balance = bal;
    minimumBalance = minBal;
    interestRate = intRate;
    serviceCharge = servC;
}

void checkingAccount::writeCheck(double amount)
{
    withdraw(amount);
}

void checkingAccount::setInterestRate(double intRate)
{
    interestRate = intRate;
}

void checkingAccount::setMinimumBalance(double minBalance)
{
    minimumBalance = minBalance;
}
void checkingAccount::setServiceCharge(double servCharge)
{
    serviceCharge = servCharge;
}

double checkingAccount::getInterestRate() const
{
    return interestRate;
}
double checkingAccount::getMinimumBalance() const
{
    return minimumBalance;
}
double checkingAccount::getServiceCharge() const
{
    return serviceCharge;
}

void checkingAccount::postInterest()
{
    balance += balance*interestRate;
}
void checkingAccount::print() const
{
    cout << "Checking Account" << endl;
    cout << fixed << setprecision(2);
    bankAccount::print();
    cout << "Interest Rate: " << interestRate << endl;
    cout << "Minimum Balance: " << minimumBalance << endl;
    cout << "Service Charge: " << serviceCharge << endl;
  
}
void checkingAccount::withdraw(double amount)
{   
    if(balance-amount < 0)
        cout << "insufficient funds to withdraw that amount" << endl;
    else if (balance-amount < minimumBalance)
    {   
        if(balance-amount-serviceCharge < 0)
        {
            cout << "Insuggicient funds to withdraw that amount" << endl;
        }
        else
        {
            cout << "You have been charged the service fee" << endl;
            balance -= (amount+serviceCharge);
        }
    }
    else  
        balance -= amount;

}
bool checkingAccount::verifyMinimumBalance(double amount)
{
    return (minimumBalance > balance - amount);
}
