#include <iostream>
#include <cmath>

using namespace std;

const double Small = 0.0000001;

class LinearEquation{

public:
    LinearEquation(double, double, double, double, double, double);
    double getA();
    double getB();
    double getC();
    double getD();
    double getE();
    double getF();
    bool isSolvable();
    double getX();
    double getY();

private:
    double a,b,c,d,e,f;

};

LinearEquation::LinearEquation(double num1, double num2, double num3, double num4, double num5, double num6){
    a = num1;
    b = num2;
    c = num3;
    d = num4;
    e = num5;
    f = num6;
}
double LinearEquation::getA(){
    return a;
}
double LinearEquation::getB(){
    return b;
}
double LinearEquation::getC(){
    return c;
}
double LinearEquation::getD(){
    return d;
}
double LinearEquation::getE(){
    return e;
}
double LinearEquation::getF(){
    return f;
}
bool LinearEquation::isSolvable(){
    //if the slopes of both lines are equal than the lines will never intersect so no solution
    return (abs(a*d - b*c) <= Small) ? false : true;
}
double LinearEquation::getX(){
    return (((e*d) - (b*f))/((a*d) - (b*c)));
}
double LinearEquation::getY(){
    return (((a*f) - (e*c))/((a*d) - (b*c)));
}

int main(){
    double num1, num2, num3, num4, num5, num6;
    cout << "Enter a,b,c,d,e,f: ";
    cin >> num1 >>num2>>num3>>num4>>num5>>num6;
    LinearEquation eqs(num1,num2,num3,num4,num5,num6);

    cout << eqs.isSolvable() << endl;

    if(eqs.isSolvable()){
        cout << "x is " << eqs.getX() << " and y is " << eqs.getY() << endl;
    }
    else{
        cout << "The equation has no solution" << endl;
    }
    return 0;
}