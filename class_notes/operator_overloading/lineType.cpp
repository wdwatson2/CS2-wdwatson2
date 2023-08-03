//
//  lineType.cpp
//  LineTypeDemo
//
//  Created by Antoun, Sherine on 2/13/23.
//  Copyright © 2023 Antoun, Sherine. All rights reserved.
//
/*
 
 
 //Function to set the line.
 
 
 
 
 
 
 
 
 
 
 */
#include "lineType.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
lineType::lineType(double a, double b, double c)
//Constructor
{
    setLine(a, b, c);
}

const lineType& lineType::operator=(const lineType& otherLine)
{
    if(this != &otherLine)
    {
        xCoeff = otherLine.xCoeff;
        yCoeff = otherLine.yCoeff;
        constTerm = otherLine.constTerm;
    }
    return *this;
}

void lineType::setLine(double a, double b, double c)
{
    xCoeff = a;
    yCoeff = b;
    
    if(a==0 && b == 0)
        constTerm = 0;
    else
        constTerm = c;
}

double lineType::getXCoefficient() const
{
    return  xCoeff;
}
double lineType::getYCoefficient() const
{
    return yCoeff;
}
double lineType::getCOnstantTerm() const
{
    return constTerm;
}

void lineType::setXCoefficient(double coeff)
{
    xCoeff=coeff;
}
void lineType::setYCoefficient(double coeff)
{
    yCoeff=coeff;
}
void lineType::setConstantTerm(double c)
{
    constTerm = c;
}

double lineType::slope() const
{
    //Return the slope. This function does not check if the
    //line is vartical. Because the slope of a vertical line
    //is undefined.
    return  - xCoeff/yCoeff;
}

//vertical line
bool lineType::operator+() const
{//Returns true if this line is vertical; false otherwise.
    if(yCoeff == 0)
        return  true;
    else
        return false;
}

//Horizontal line
bool lineType::operator-() const
{//Returns true if this line is horizontal; false otherwise.
    if(xCoeff == 0)
        return true;
    else
        return false;
}

//Equal lines
bool lineType::operator==(const lineType& otherLine) const
{//Returns true if both lines are the same.
    //2x + 3y = 1 and 4x = 6y = 2 are equal lines
    double factor = 1;
    if (xCoeff !=0)
        factor = otherLine.xCoeff/xCoeff;
    else
        factor = otherLine.yCoeff/yCoeff;
    
    if(xCoeff*factor == otherLine.xCoeff &&
       yCoeff*factor==otherLine.yCoeff &&
       constTerm * factor == otherLine.constTerm)
        return true;
    else
        return false;
}

//parallel lines
bool lineType::operator||(const lineType& otherLine) const
{//Returns true if this line is parallel to otherLine.
    if(yCoeff ==0 && otherLine.yCoeff==0)
        return true;
    else if((yCoeff!= 0 && otherLine.yCoeff==0) || (yCoeff==0 &&otherLine.yCoeff!= 0 ))
        return false;
    else if((xCoeff/yCoeff)==(otherLine.xCoeff/otherLine.yCoeff))
        return true;
    else
        return false;
}

//orthogonal lines
bool lineType::operator&&(const lineType& otherLine) const
{//Returns true if this line is perperdicular to otherLine.
    if(yCoeff!=0 && otherLine.yCoeff!=0)
    {
        // if((xCoeff/yCoeff)*(otherLine.xCoeff/otherLine.yCoeff)==-1)
        //     return true;
        if(otherLine.xCoeff == yCoeff && otherLine.yCoeff == xCoeff) //correct comparison
          return true;
        else
            return false;
    }
    // else if((xCoeff==0 && otherLine.xCoeff==0)||(yCoeff ==0 && otherLine.yCoeff==0))
    //   return true;

    else if((xCoeff == 0 && otherLine.yCoeff == 0) || (yCoeff == 0 && otherLine.xCoeff == 0)) //correct comparison
      return true;
    else
        return false;
}


//Overload the stream insertion and extraction operators
ostream& operator<<(ostream& osObject, const lineType& line)
{
    if(line.xCoeff != 0)
    {
        osObject<<line.xCoeff <<"x ";
        if(line.yCoeff !=0)
            osObject<<"- ";
        else
            osObject<<"+ ";
        osObject<< fabs(line.yCoeff)<<"y ";
    }
    osObject<<" = "<<line.constTerm;
    return osObject;
}

//2do 2moro
istream& operator>>(istream& isObject, lineType& line)
{
    char ch;
    isObject >> ch;
    isObject >> line.xCoeff;
    isObject >> ch;
    isObject >>line.yCoeff;
    isObject >> ch;
    isObject >>line.constTerm;
    isObject >>ch;
    return isObject;
}

void lineType::pointOfIntersection(lineType otherLine)
//If lines intersect, then this function finds the point
//of intersection.
{
    if(*this == otherLine)
        cout<<"Both lines are equal and have infinite points of intersections"<<endl;
    else if(*this || otherLine)
        cout<<"Lines do not intersect, no point of ntersection can be found"<<endl;
    else
        cout<<"The point of intesection is: ("<<(constTerm*otherLine.yCoeff - yCoeff*otherLine.constTerm)/
        (xCoeff *otherLine.yCoeff - yCoeff*otherLine.xCoeff)<<", "<<(constTerm*otherLine.xCoeff-xCoeff*otherLine.constTerm)/(yCoeff*otherLine.xCoeff-xCoeff*otherLine.yCoeff)<<")"<<endl;
    
}
