#include "StringPalindrome.h"
#include <iostream>

using namespace std;

StringPalindrome::StringPalindrome(char sentence[])
{
    int i = 0;
    char ch = sentence[i];

    while(ch != '\0')
    {
        original.add(ch);
        reversed.add(ch);
        i++;
        ch = sentence[i];
    }

    //now I must reverse reversed.
    reversed.reverse();
}

void StringPalindrome::printForward()
{
    for(auto iter = original.begin(); iter != original.end(); ++iter)
    {
        cout << *iter;
    }
    cout << endl;
}
void StringPalindrome::printReversed()
{
    for(auto iter = reversed.begin(); iter != reversed.end(); ++iter)
    {
        cout << *iter;
    }
    cout << endl;
}

bool StringPalindrome::isPalindrome()
{
    auto iterRV = reversed.begin();
    for(auto iterOG = original.begin(); iterOG != original.end(); ++iterOG, ++iterRV)
    {
        if(*iterOG == ' ')
            ++iterOG;
        if(*iterRV == ' ')
            ++iterRV;
        if(*iterOG != *iterRV)
            return false;
    }
    return true;
}