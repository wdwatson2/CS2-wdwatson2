#include <iostream>

using namespace std;

int main()
{
    char temp[120];

    temp = "asdf";

    for(int i = 0; i < sizeof(temp); i++)
    {
        cout << temp[i];
    }
    cout << endl;

    return 0;
}