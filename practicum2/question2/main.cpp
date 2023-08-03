#include <cstring>
#include <iostream>

using namespace std;

int noname(const char* p)
{
    char* r = (char*) p;
    while (*r != '\0')
        r++;
    return r - p;
}

int main(){

    char* p = "hellottt";
    cout << noname(p) << endl;

    return 0;
}
