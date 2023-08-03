#include <iostream>
#include <string>
using namespace std;
/*
The program contains the main function and 
two overloaded count functions. 
The main function prompts the user for the input 
string and then a character. It then invokes the 
count(const string& s, char a) function.
The count(const string& s, char ch) function 
invokes count(s, ch, s.length() - 1).
The count(s, ch, high) is a recursive helper 
function. The function returns 0 if high < 0. 
Otherwise, 
it returns count(s, ch, high - 1) + (s[high] == ch ? 1 : 0).
*/
int count(const string& s, char a);
int count(const string& s, char a, int high);

int main()
{
    string sentence;
    char letter;
    cout << "enter string: ";
    getline(cin, sentence);
    cout << "enter character: ";
    cin >> letter;
    
    cout << "There is " << count(sentence, letter) << " " << letter << " in " << sentence << endl;
    
    return 0;
}
int count(const string& s, char a)
{
    return count(s, a, s.length()-1);
}
int count(const string& s, char a, int high)
{
    if(high < 0)
        return 0;
    else
    {
        return count(s, a, high - 1) + (s[high] == a ? 1 : 0);
    }
}
