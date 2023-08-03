#include <iostream>

using namespace std;

// int quotient(int num1, int num2)
// {
//     if (num2 == 0)
//         throw num1;
//     return num1/num2;
// }

// int main()
// {
//     //division
//     int num1, num2;
//     cout << "Enter two nums seperated by space: ";
//     cin >> num1 >> num2;

//     //if num2=0 then we get error. How can we catch it?
//     try
//     {
//         cout << "The quotient is: " << quotient(num1, num2) << endl;
//     }
//     catch(int ex)
//     {
//         cout << "ERROR: An integer " << ex << " cannot be divided by zero" << endl;
//         exit(1);
//     }
//     return 0;
// }

int main()
{
    try
    {
        for(int i = 1; i <= 100; i++)
        {
            new int[70000000]; //of course this will allocate this memory just fine
            cout << i << " arrays have been created" << endl; //but imagine if you did run out of memory
        }
    }
    catch(bad_alloc & e)
    {
        std::cerr << e.what() << '\n';
    }
    
}