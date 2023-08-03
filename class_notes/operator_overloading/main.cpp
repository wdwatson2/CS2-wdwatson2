/*

The equation of a line in standard form is ax + by = c, wherein both a and b cannot be zero, and a, b, and c are real numbers. If b 6= 0, then –a/b is the
slope of the line. If a = 0, then it is a horizontal line, and if b = 0, then it is a vertical line. The slope of a vertical line is undefined. Two lines are
parallel if they have the same slope or both are vertical lines. Two lines are perpendicular if either one of the lines is horizontal and the other is vertical
or the product of their slopes is –1. Design the class lineType to store a line. To store a line, you need to store the values of a (coefficient of x), b
(coefficient of y), and c. Your class must contain the following operations.
 
1. If a line is nonvertical, then determine its slope.
2. Determine if two lines are equal. (Two lines a1x + b1y = c1 and a2x + b2y = c2 are equal if either a1 = a2, b1 = b2, and c1 = c2 or a1 = ka2, b1 = kb2, and c1
   = kc2 for some real number k.)
3. Determine if two lines are parallel.
4. Determine if two lines are perpendicular.
5. If two lines are not parallel, then find the point of intersection. 
The class lineType should:
a. Overloads the stream insertion operator, <<, for easy output.
b. Overloads the stream extraction operator, >>, for easy intput. (The line ax + by = c is input as (a, b, c).)
c. Overloads the assignment operator to copy a line into another line.
d. Overloads the unary operator +, as a member function, so that it returns true if a line is vertical; false otherwise.
e. Overloads the unary operator -, as a member function, so that it returns true if a line is horizontal; false otherwise.
f. Overloads the operator ==, as a member function, so that it returns true if two lines are equal; false otherwise.
g. Overloads the operator ||, as a member function, so that it returns true if two lines are parallel; false otherwise.
h. Overloads the operator &&, as a member function, so that it returns true if two lines are perpendicular; false otherwise.
*/
//Main program
  
#include <iostream>

#include "lineType.h"
 
using namespace std;

int main()
{
    lineType line1(2, 3, 4);
    lineType line2(3, 5, 7);
    lineType line3(2, 3, -2);
    lineType line4(3, -2, 1);
    lineType line5(2, 0, 3);   //vertical line
    lineType line6(0, -1, 2);  //horizontal line
    lineType line7(4, 6, 8);
    lineType line8;

    cout << "line1: " << line1 << endl;
     
    if (!(+line1))
        cout << "The slope of line1: " << line1.slope() << endl;
    else
        cout << "line1 is a vertial line. Its slope is undefined." << endl;

    cout << "line2: " << line2 << endl;
    cout << "line3: " << line3 << endl;
    cout << "line4: " << line4 << endl;
    cout << "line5: " << line5 << endl;
    cout << "line6: " << line6 << endl;
    cout << "line7: " << line7 << endl;

    if (line1 || line2)
        cout << "line1 and line2 are parallel." << endl;
    else
        cout << "line1 and line2 are not parallel." << endl;

    line1.pointOfIntersection(line2);

    if (line1 || line3)
        cout << "line1 and line3 are parallel." << endl;
    else
        cout << "line1 and line3 are not parallel." << endl;

    if (line1 && line4)
        cout << "line1 and line4 are perpendicular." << endl;
    else
        cout << "line1 and line4 are not perpendicular." << endl;

    if (+line5)
        cout << "line5 is a vertical line." << endl;
    else
        cout << "line5 is not a vertical line." << endl;

    if (-line6)
        cout << "line6 is a horizontal line." << endl;
    else
        cout << "line6 is not a horizontal line." << endl;

    line5.pointOfIntersection(line6);

    if (line1 == line7)
        cout << "line1 and line 7 are equal." << endl;
    else
        cout << "line1 and line 7 are not equal." << endl;

    line1.pointOfIntersection(line7);

    cout << "Input line8 in the form (a, b, c): ";
    cin >> line8;
    cout << line8 << endl;

    if (line1 || line8)
        cout << "line1 and line8 are parallel." << endl;
    else
        cout << "line1 and line8 are not parallel." << endl;

     return 0;
}
