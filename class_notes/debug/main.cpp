#include <iostream>
#include <chrono>

#define DEBUG //comment this out if you wish to turn off debug feature

#include <cassert>

using namespace std;
using namespace chrono;

long long int pow(int, int);

int main(int argc, const char * argv[])
{
    int input;
    long long int* res;
    res = new long long int;
    assert (res != nullptr);
    *res = 0;
    int x = 0, y = 0;
    cout << "Hello, what number to what exponent do wish computed:\t";
    cin >> x >> y;
    if (x==0) exit(1);
    auto start = chrono::steady_clock::now();
    *res = pow(x,y);
    auto end = chrono::steady_clock::now();
    cout << res<<endl;
    cout << "Elapsed time in nanoseconds: "
            << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
            << " ns" << endl;
#ifdef DEBUG
    cout << "Elapsed time in nanoseconds: "
            << chrono::duration_cast<chrono::seconds>(end - start).count()
            << " sec" << endl;
#endif // DEBUG
    return 0;
}

long long int pow(int x, int y)
{
    long long int res = x;
#ifdef DEBUG
    cout <<res<<'\t'<<x<<'\t'<<y<<'\n';
#endif // DEBUG
    for (int i = 1; i< y ;i++)
        if(y==1)
            return res;
        else
            res = res*x;
    return res;
}
