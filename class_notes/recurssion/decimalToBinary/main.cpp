#include <iostream>

using namespace std;

/*
For simplicity, you can assume that the decimal integer is greater than 0. 
Your submission will work with this assumption.
The program contains the main function and the decimalToBinary function. 
The main function prompts the user to enter an integer then invokes the decimalToBinary(int) 
to return a binary string for the integer. It displays the binary string.
The decimalToBinary(int value) function returns "" if value is 0, otherwise, 
it returns decimalToBinary(value / 2) + (value % 2 == 0? "0" : "1").
Note that decimalrBinary(value / 2) returns a string. value % 2 is 0 or 1.
*/
string decimalToBinary(int value);
int main()
{
    int value;
    cout << "Enter an int: ";
    cin >> value;

    cout << "binary: " << decimalToBinary(value) << endl;

    return 0;
}

string decimalToBinary(int value)
{
    if(value == 0)
        return "";
    else
    {
        return decimalToBinary(value / 2) + (value % 2 == 0? "0" : "1");
    }
}
