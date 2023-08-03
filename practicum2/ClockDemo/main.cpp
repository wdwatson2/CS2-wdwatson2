#include <iostream>
#include "ClockType.h"

using namespace std;

int main()
{
    ClockType myClock(9, 30, 45);
    ClockType yourClock(12, 45, 18);
    ClockType tempClock;
/*
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
    ClockType operator++();
    ClockType operator--();//to do - FIXED
    bool operator==(const ClockType& otherClock)const;
    bool operator<=(const ClockType& otherClock)const;
    bool operator>=(const ClockType& otherClock)const;//to do - FIXED
    bool operator!=(const ClockType& otherClock)const;//to do - FIXED
*/
    tempClock.setTime(5,5,5);
    cout << "After setting time: " << tempClock << endl;

    tempClock.setHours(6);
    cout << "After changing hour: " << tempClock << endl;

    tempClock.setMinutes(6);
    cout << "After changing min: " << tempClock << endl;

    tempClock.setSeconds(6);
    cout << "After changing sec: " << tempClock << endl;

    ++tempClock;
    cout << "After incrementing: " << tempClock << endl;

    --tempClock;
    cout << "After decrementing: " << tempClock << endl;

    if(tempClock == myClock)
        cout << tempClock << " == " << myClock << " - YES" << endl;
    else   
        cout << tempClock << " == " << myClock << " - NO" << endl;

    if(tempClock <= myClock)
        cout << tempClock << " <= " << myClock << " - YES" << endl;
    else   
        cout << tempClock << " <= " << myClock << " - NO" << endl;

    if(tempClock >= myClock)
        cout << tempClock << " >= " << myClock << " - YES" << endl;
    else   
        cout << tempClock << " >= " << myClock << " - NO" << endl;

    if(tempClock != myClock)
        cout << tempClock << " != " << myClock << " - YES" << endl;
    else   
        cout << tempClock << " != " << myClock << " - NO" << endl;



    return 0;
}//
