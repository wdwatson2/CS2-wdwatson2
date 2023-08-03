#include "stackType.h"
#include "queueType.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include <string>

using namespace std;

bool isPalindrome(string line)
{
    stackType<char> trashcan(400);
    queueType<char> pipe(400);

    trashcan.initializeStack();
    pipe.initializeQueue();
    int size = 0;

    for(auto & ch : line)
    {
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
        {
            size++;
            trashcan.push(tolower(ch));
            pipe.push(tolower(ch));
        }
    }

    for(int i = 0; i < size; i++)
    {
        if(trashcan.top() != pipe.bottom())
        {
            return false;
        }
        trashcan.pop();
        pipe.pop();
    }
    return true;

}
int main()
{
    string line;
    fstream inf;
    inf.open("Practicum week 14-test palindromes.txt", ios::in);

    for(int i = 0; i < 10; i++)
    {   
        getline(inf, line);

        if(inf.eof())
            return 0;
        if(!line.empty())
        {            
            if(isPalindrome(line))
                cout << line << "\nYep. The sentence is a palindrome.\n" << endl;
            else
                cout << line << "\nNope. The sentence is not a palindrome.\n" << endl;
        }    
    }

    inf.close();

    cout << "\nEnter A possible palindrome: ";
    getline(cin, line);

    if(isPalindrome(line))
        cout << "Yep. Its a palindrome." << endl;
    else
        cout << "Nope. Its not a palindrome." << endl;

    return 0;
}