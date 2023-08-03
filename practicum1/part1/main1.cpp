#include <iostream>

using namespace std;

void findsmallest(int* a, int* b, int* c);

//swaps two ints
void swap(int*, int*);

int main()
{
    int aTemp, bTemp, cTemp;
    cin >> aTemp >> bTemp >> cTemp;

    int* a = &aTemp;
    int* b = &bTemp;
    int* c = &cTemp;

    findsmallest(a,b,c);

    cout << *a << " " << *b << " " << *c << endl;

    return 0;
}

void swap(int* d, int* c)
{
    int temp;
    temp = *d;
    *d = *c;
    *c = temp;
}


void findsmallest(int* a, int* b, int* c)
{
    if(*b < *a)
    {
        swap(b,a);
    }
    if(*c < *a)
    {
        swap(c,a);
    }
    if(*c < *b)
    {
        swap(c,b);
    }
}
