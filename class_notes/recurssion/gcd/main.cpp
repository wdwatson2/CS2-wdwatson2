#include <iostream>


using namespace std;

/*
The program contains the main function and the gcd(int m, int n). 
The main function prompts the user for the input m and n. It then invokes gcd(m, n) to return the GCD of m and n.
gcd(m, n) returns n if m % n is 0. Otherwise, gcd(m, n) is return gcd(n, m % n)
*/
int gcd(int m, int n);
int main()
{
    int m, n;
    cout << "Enter the first number: ";
    cin >>m;
    cout << "Enter the second number: ";
    cin >> n;

    cout << "The GCD of " << m << " and " << n << " is " << gcd(m,n) << endl;

    return 0;
}
int gcd(int m, int n)
{
    if(m%n == 0)
        return n;
    else
    {
        return gcd(n, m%n);
    }
}
