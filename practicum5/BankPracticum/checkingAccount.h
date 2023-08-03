#ifndef checkingAccount_h
#define checkingAccount_h


#include <stdio.h>
#include "bankAccount.h"

const double DEFAULT_INTEREST_RATE_CHECKING = 0.04;
const double DEFAULT_MINIMUM_BALANCE = 500;
const double DEFAULT_SERVICE_CHARGE = 20;

class checkingAccount : public bankAccount
{
protected:
    double interestRate;
    double minimumBalance;
    double serviceCharge;

public:
    void setInterestRate(double intRate);
    void setMinimumBalance(double minBalance);
    void setServiceCharge(double servCharge);
    double getInterestRate() const;
    double getMinimumBalance() const;
    double getServiceCharge() const;
    void postInterest();
    void writeCheck(double amount);
    void print() const;
    void withdraw(double amount);
    bool verifyMinimumBalance(double amount);

    checkingAccount(double acctNumber, double bal, 
                    double minBal = DEFAULT_MINIMUM_BALANCE,
                    double intRate = DEFAULT_INTEREST_RATE_CHECKING,
                    double servC = DEFAULT_SERVICE_CHARGE);

};

#endif