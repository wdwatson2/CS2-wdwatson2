#ifndef bankAccount_h
#define bankAccount_h


class bankAccount
{
protected:
    int accountNumber;
    double balance;

public:
    double getBalance() const;
    void deposit(double amount);
    void withdraw(double amount);
    void setAccountNumber(int acct);
    int getAccountNumber() const;
    void print() const; //only allowed to read
    bankAccount(int acctNumber = 1, double balance = 0);
};


#endif