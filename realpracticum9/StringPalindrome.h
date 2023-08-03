#ifndef StringPalindrome_h
#define StringPalindrome_h
#include "linkedList.h"


class StringPalindrome
{
private:
    LinkedList<char> original;
    LinkedList<char> reversed;
public:
    StringPalindrome(char[]);
    // ~StringPalindrome();

    bool isPalindrome();
    void printForward();
    void printReversed();
};

#endif