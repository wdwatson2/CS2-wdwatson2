#include "ClockType.h"
#include <iostream>

using namespace std;


ClockType::ClockType()
{
    hr=min=sec=0;
}
ClockType::ClockType(int hours, int minutes, int seconds)
{
    setTime(hours,minutes,seconds);
}

void ClockType::setTime(int hours, int minutes, int seconds)
{
    if(hours >=0 && hours<24)
        hr = hours;
    else
        hr=0; 
    if(minutes >=0 && minutes<60)
        min = minutes;
    else
        min=0;
    if(seconds >=0 && seconds<60)
        sec = seconds;
    else
        sec=0;
}

void ClockType::setHours(int hours)
{
   if(hours >=0 && hours<24)
        hr = hours;
    else
        hr=0;
}
void ClockType::setMinutes(int minutes)
{
    if(minutes >=0 && minutes<60)
        min = minutes;
    else
        min=0;

}
void ClockType::setSeconds(int seconds)
{
    if(seconds >=0 && seconds<60)
        sec = seconds;
    else
        sec=0;
}

void ClockType::getTime(int& hours, int&minutes, int& seconds) const
{
	hours = hr;
	minutes = min;
	seconds = sec;
}

int ClockType::getHours() const
{
    return hr;
}
int ClockType::getMinutes() const
{
    return min;
}
int ClockType::getSeconds() const
{
    return sec;
}

void ClockType::printTime()const
{
    if(hr<10)
        cout<<"0";
    cout<<hr<<":";
    if(min <10)
        cout<<"0";
    cout<<min<<":";
    if(sec<10)
        cout<<"0";
    cout<<sec<<endl;
}

ClockType ClockType::operator++(){
    sec++;
    if(sec > 59){
        sec = 0;
        min++;

        if(min > 59){
            min = 0;
            hr++;
        }
        if(hr>23){
            hr = 0;
        }
    }
    return *this;//this is the current instance of the class that you want the member function to modify
    
}
bool ClockType::operator==(const ClockType& otherClock) const{
    return (this->hr == otherClock.hr && this->min == otherClock.min 
            && this->sec == otherClock.sec);//comparing times
}

bool ClockType::operator<=(const ClockType& otherClock) const{
    if(this->hr < otherClock.hr)//if the hour is less than we are done
        return true;
    else if(this->hr == otherClock.hr){
        if(this->min < otherClock.min)
            return true;
        else if(this->min == otherClock.min){
            if(this->sec <= otherClock.sec)
                return true;
            else  
                return false;
        }
        else
            return false;
    }
    else    
        return false;
}

// ostream& operator<<(ostream& osObject, const ClockType& timeOut){

//     if(timeOut.hr < 10)
//         osObject << '0';
//     osObject << timeOut.hr << ':';
//     if(timeOut.min < 10)
//         osObject << '0';
//     osObject << timeOut.min << ':';
//     if(timeOut.sec < 10)
//         osObject << '0';
//     osObject << timeOut.sec;

//     return osObject;
// }//allows 

