#include <iostream>
#include <cmath>

using namespace std;

class QuadraticEquation{
public:
    QuadraticEquation(double, double, double);
    double getA();
    double getB();
    double getC();
    double getDiscriminate();
    double getRoot1();
    double getRoot2();
private:
    double a,b,c;
};

QuadraticEquation::QuadraticEquation(double num1, double num2, double num3){
    a = num1;
    b = num2;
    c = num3;
}
double QuadraticEquation::getA(){
    return a;
}
double QuadraticEquation::getB(){
    return b;
}
double QuadraticEquation::getC(){
    return c;
}
double QuadraticEquation::getDiscriminate(){
    return (pow(b, 2) - 4*a*c);
}
double QuadraticEquation::getRoot1(){
    return (-(b) + sqrt(getDiscriminate()))/(2*a);
}
double QuadraticEquation::getRoot2(){
    return (-(b) - sqrt(getDiscriminate()))/(2*a);
}


int main(){
    double a,b,c;
    cout << "Enter a,b,c: ";
    cin >> a >> b >> c;

    QuadraticEquation eq(a,b,c);

    double discriminate = eq.getDiscriminate();

    if(discriminate < 0){
        cout << "The equation has no roots" << endl;
    }
    else if(discriminate == 0){
        cout << "The root is " << eq.getRoot1() << endl;
    }
    else{
        cout << "The roots are " << eq.getRoot1() << " and " << eq.getRoot2() << endl;
    }

    return 0;
}