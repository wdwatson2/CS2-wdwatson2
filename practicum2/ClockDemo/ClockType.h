#ifndef CLOCKTYPE_H
#define CLOCKTYPE_H
#include <iostream>

class ClockType
{
       friend std::ostream& operator <<(std::ostream& osObject, const ClockType&);
        //friends are placed outside the scopes of private, protected, & public
    public:
        ClockType();
        ClockType(int, int, int);
        ClockType(const ClockType&);//copy constructor
        void setTime(int hours, int minutes, int seconds);
        void setHours(int hours);
        void setMinutes(int minutes);
        void setSeconds(int seconds);
        void getTime(int& hours, int&minutes, int& seconds) const;
        int getHours() const;
        int getMinutes() const;
        int getSeconds() const;
        void printTime()const;
        ClockType& operator++();
        ClockType& operator--();//to do - FIXED
        bool operator==(const ClockType& otherClock)const;
        bool operator<=(const ClockType& otherClock)const;
        bool operator>=(const ClockType& otherClock)const;//to do - FIXED
        bool operator!=(const ClockType& otherClock)const;//to do - FIXED
    private:
        int hr, min, sec;
};

#endif // CLOCKTYPE_H
