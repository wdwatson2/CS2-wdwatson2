#include <iostream>
#include <cmath>

using namespace std;

/*
Write a program, utilising a recursive function, which calculates the nth
Fibonacci number. The Fibonacci sequence is 0, 1, 1, 2, 3, 5, 8, 13, ... where
the first two terms are 0 and 1 and each successive term is defined as the sum
of the two preceding terms. This can be recursively defined as:
fib(n) = n, where n < 2
fib(n) = fib (n-1) + fib(n-2), where n > 2
*/

const int n_0 = 0;
const int n_1 = 1;

long long int fibonacci(int n);

int main()
{
    int n;
    cout << "Enter what fibonnaci number you want: ";
    cin >> n;

    // cout << "Its " << fibonacci(n) << endl;

    for(int i = 0; i <=n ; i++)
    {
        cout << fibonacci(i) << endl;
    }

    return 0;
}

// long long int fibonacci(int n)
// {
//     if(n == 0)
//         return 0;
//     else if(n == 1)
//         return 1;
//     else
//         return fibonacci(n-1) + fibonacci(n-2);
// }

long long int fibonacci(int n)
{
    long long int target;
    long long int * nums = new long long int[n+1]; //need to create array of unknown size so do it at runtime

    nums[0] = n_0; //placing the first two fibonacci numbers in the array
    nums[1] = n_1;

    for(int i = 2; i <= n; i++)
    {
        nums[i] = nums[i-1] + nums[i-2];
    }
    target = nums[n];

    delete[] nums;
    return target;
}
