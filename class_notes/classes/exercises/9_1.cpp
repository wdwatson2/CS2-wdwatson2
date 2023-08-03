#include <iostream>
using namespace std;

class Rectangle{
public:
    Rectangle();
    Rectangle(double, double);
    double getWidth();
    double getHeight();
    void setWidth(double);
    void setHeight(double);
    double getArea();
    double getPerimeter();

private:
    double width, height;
};

Rectangle::Rectangle(){
    height = 1;
    width = 1;
}
Rectangle::Rectangle(double w, double h){
    (w >= 0) ? width = w : width = 1;
    (h >= 0) ? height = h : height = 1;
}
double Rectangle::getHeight(){
    return height;
}
double Rectangle::getWidth(){
    return width;
}
void Rectangle::setHeight(double h){
    (h >= 0) ? height = h : height = 1;
}
void Rectangle::setWidth(double w){
    (w >= 0) ? width = w : width = 1;
}
double Rectangle::getArea(){
    return width*height;
}
double Rectangle::getPerimeter(){
    return (2*width)+(2*height);
}

int main(){
    Rectangle rec1(4, 40);
    Rectangle rec2(3.5, 35.9);

    cout << rec1.getWidth() << ' '
        << rec1.getHeight() << ' '
        << rec1.getArea() << ' '
        << rec1.getPerimeter() << endl;
    cout << rec2.getWidth() << ' '
        << rec2.getHeight() << ' '
        << rec2.getArea() << ' '
        << rec2.getPerimeter() << endl;
    return 0;
}