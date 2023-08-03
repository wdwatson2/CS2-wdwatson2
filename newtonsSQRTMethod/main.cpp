#include <cmath>
#include <iostream>

using namespace std;

const double EPSILON = 0.01;

double newtonSQRT(double x, double a);

int main()
{
    double x;
    cout << "enter number: ";
    cin >> x;
    cout << newtonSQRT(x, x) << endl;

    return 0;
}

double newtonSQRT(double x, double a)
{
    if(abs(pow(a,2) - x) <= EPSILON)
        return a;
    else
        return newtonSQRT(x, (pow(a, 2)+x)/(2*a));
}
