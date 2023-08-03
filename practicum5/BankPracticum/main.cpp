#include "checkingAccount.h"
#include "savingsAccount.h"
#include <iostream>

using namespace std;

int main()
{
    checkingAccount checkTest(1, 5636535.90); //creating checkingaccount object with defualt interest, min, and serv charge

    //derived methods from bankAccount class
    checkTest.print();

    //changing data fields
    checkTest.setInterestRate(.05);
    checkTest.setMinimumBalance(250);
    
    //reprinting to show changes
    checkTest.print();

    //withdrawing too much
    checkTest.writeCheck(5700000);

    //withdrawing over min balance
    checkTest.writeCheck(5636335.90);

    checkTest.print();


    savingsAccount savTest(2, 890.50);

    //derived methods from bankAccount class
    savTest.print();

    //changing data fields
    savTest.setInterestRate(.05);
    
    //reprinting to show changes
    savTest.print();

    //withdrawing too much
    savTest.withdraw(5700000);

    savTest.print();

    return 0;
}