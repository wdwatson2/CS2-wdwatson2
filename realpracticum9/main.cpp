#include "StringPalindrome.h"
#include <iostream>

using namespace std;


int main()
{
    char sentence[128];
    cout << "Enter possible palindrome: ";
    cin.getline(sentence, 128);

    StringPalindrome palindrome(sentence);

    palindrome.printForward();
    palindrome.printReversed();
    cout << palindrome.isPalindrome() << endl;
}