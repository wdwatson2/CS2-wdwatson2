#include <iostream>

using namespace std;


/*
The program contains the main function and the sumDigits(long n). 
The main function prompts the user for the input number n. 
It then invokes sumDigits(n) to return the sum of the digits in n.
sumDigits(n) returns n if n is a single digit. 
Otherwise, it returns sumDigits(n / 10) + sumDigits(n % 10). 
n % 10 is the last digit in n. n / 10 is the remaining number after removing the last digit.
*/
int sumDigits(long n);
int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;

    cout << "The sum of " << n << " digits is " << sumDigits(n) << endl;

    return 0;
}
int sumDigits(long n)
{
    if(n < 10)
        return n;
    else
    {
        return sumDigits(n/10) + sumDigits(n%10);
    }
}
