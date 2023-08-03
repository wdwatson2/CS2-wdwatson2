#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    fstream stream;
    
    stream.open("Exercise13_1.txt", ios::out | ios::app);
    
    for(int i =0; i< 99; i++)
    {
        stream << i << " ";
    }
    
    return 0;
}