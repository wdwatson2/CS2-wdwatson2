#include <string>
#include <iostream>


using namespace std;

string replace(string sentence)
{
    if(sentence == "")
        return "";
    else if (sentence[0] == ' ')
        return '*'+replace(sentence.substr(1));
    else
        return sentence[0]+replace(sentence.substr(1));
}

int main()
{
    string word;
    getline(cin, word);


    cout << replace(word) << endl;

    return 0;
}