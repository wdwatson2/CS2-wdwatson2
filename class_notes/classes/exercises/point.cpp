#include <iostream>
#include <cmath>

using namespace std;

class MyPoint{
public:
    MyPoint();
    MyPoint(double, double);
    double getX();
    double getY();
    double distance(MyPoint);
private:
    double x, y;
};

MyPoint::MyPoint(){
    x = 0;
    y = 0;
}
MyPoint::MyPoint(double x1, double y1){
    x = x1;
    y = y1;
}
double MyPoint::getX(){
    return x;
}
double MyPoint::getY(){
    return y;
}
double MyPoint::distance(MyPoint point2){
    return sqrt(pow((point2.getX() - x), 2) + pow((point2.getY() - y), 2));
}

int main(){
    MyPoint pt1;
    MyPoint pt2(10, 30.5);

    cout << pt1.distance(pt2) << endl;


    return 0;
}