//
//  lineType.hpp
//  FriendTest
//
//  Created by Antoun, Sherine on 9/14/21.
//  Copyright © 2021 Antoun, Sherine. All rights reserved.
//

#ifndef lineType_h
#define lineType_h

#include <stdio.h>
#include <iostream>
using namespace std;
 
class lineType
{
    //Overload the stream insertion and extraction operators
    friend ostream& operator<<(ostream&, const lineType&);
    friend istream& operator>>(istream&, lineType&);

public:
    const lineType& operator=(const lineType&); //overload the assignment operator

    void setLine(double a = 0, double b = 0, double c = 0); //Function to set the line.

    double getXCoefficient() const;
    double getYCoefficient() const;
    double getCOnstantTerm() const;

    void setXCoefficient(double coeff);
    void setYCoefficient(double coeff);
    void setConstantTerm(double c);

    double slope() const;
      //Return the slope. This function does not check if the
      //line is vartical. Because the slope of a vertical line
      //is undefined, before calling this function check if the 
      //line is nonvertial.

    bool operator+() const;
       //Returns true if this line is vertical; false otherwise.
    bool operator-() const;
       //Returns true if this line is horizontal; false otherwise.

    bool operator==(const lineType& otherLine) const; 
      //Returns true if both lines are the same.

    bool operator||(const lineType& otherLine) const;
      //Returns true if this line is parallel to otherLine.

    bool operator&&(const lineType& otherLine) const;
       //Returns true if this line is perperdicular to otherLine.

    void pointOfIntersection(lineType otherLine);
      //If lines intersect, then this function finds the point
      //of intersection.

    lineType(double a = 0, double b = 0, double c = 0);
       //Constructor

private:
    double xCoeff;
    double yCoeff;
    double constTerm;
};


#endif /* lineType_h */
