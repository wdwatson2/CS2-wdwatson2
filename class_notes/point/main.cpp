// #include <iostream>
// #include <cmath>
// using namespace std;

// class MyPoint
// {
// private:
//   double x;
//   double y;

// public:
//   MyPoint()
//   {
//     x = y = 0;
//   }

//   MyPoint(double x, double y)
//   {
//     this->x = x;
//     this->y = y;
//   }

//   double distance(const MyPoint& p2) const
//   {
//     return sqrt((x - p2.x) * (x - p2.x) + (y - p2.y) * (y - p2.y));
//   }

//   double getX() const
//   {
//     return x;
//   }

//   double getY() const
//   {
//     return y;
//   }
// };

// class ThreeDPoint: public MyPoint
// {
// private:
//   double z;

// public:
//   ThreeDPoint();
//   ThreeDPoint(double x, double y, double z);
//   double getZ() const;
//   double distance(const ThreeDPoint& p2);
// };

// // Write the code to implement the constructors and functions in ThreePoint
// ThreeDPoint::ThreeDPoint()
// {
//     z = 0;
// }
// ThreeDPoint::ThreeDPoint(double x, double y, double z): MyPoint(x, y)
// {
//     this->z = z;
// }

// double ThreeDPoint::getZ() const
// {
//     return z;
// }

// double ThreeDPoint::distance(const ThreeDPoint& p2)
// {
    
//     return (sqrt(pow((getX() - p2.getX()), 2) + pow((getY() - p2.getY()), 2) + pow((z - p2.getZ()), 2)));
// }

// int main()
// {
//   // Write code here in the main function
// /*
// that creates two points (0, 0, 0) and (10, 30, 25.5) and displays the distance between them
// */

//     ThreeDPoint pt1;
//     ThreeDPoint pt2(10, 30, 25.5);

//     cout << pt1.distance(pt2) << endl;
//   return 0;
// }

class SavingsAccount : public BankAccout
{
private:
    double interestRate;
    int interestType;
    
public:
    SavingsAccount(double intRate, string intType);
    double getInterestRate();
    int getInterestType();
};
SavingsAccount(double intRate, string intType)
{
    interestRate = intRate;
    if(intType == "Simple")
        interestType = 1;
    else
        interestType = 2;
}
double getInterestRate()
{
    return interestRate;
}
int getInterestType()
{
    return interestType;
}
