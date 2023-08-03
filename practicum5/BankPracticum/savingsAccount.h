#ifndef savingsAccount_h
#define savingsAccount_h

#include "bankAccount.h"

const double DEFAULT_INTEREST_RATE_SAVINGS = 0.04;

class savingsAccount : public bankAccount
{
protected:
    double interestRate;
public:
    void setInterestRate(double intRate);
    double getInterestRate() const;
    void postInterest();
    void print() const;
    void withdraw(double amount);

    savingsAccount(double acctNumber, double bal, 
                    double intRate = DEFAULT_INTEREST_RATE_SAVINGS);

};

#endif