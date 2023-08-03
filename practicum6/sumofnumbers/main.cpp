#include <iostream>
#include <cassert>

using namespace std;

/*
Write a program, utilising a recursive function, which calculates the sum of
consecutive (natural) numbers from 1 to n, where n is input by the user. This
can be recursively defined as:
sum(n) = 1, where n = 1
sum(n) = n + sum(n-1), where n > 1
*/

int sumNaturals(int n);

int main()
{
    int n;
    cout << "Enter natural number: ";
    cin >> n;

    cout << sumNaturals(n) << endl;
    return 0;
}

int sumNaturals(int n)
{
    if(n == 0)
        return 0;
    else
        return n + sumNaturals(n-1);
}

// int sumNaturals(int n)
// {
//     int summ = 0;
//     for(int i = 1; i <= n; i++)
//     {
//         summ+=i;
//     }
//     return summ;
// }
