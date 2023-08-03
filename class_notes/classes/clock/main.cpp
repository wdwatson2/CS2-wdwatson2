#include <iostream>
#include "ClockType.h"

using namespace std;

int main()
{
    ClockType myClock(9, 30, 45);
    ClockType yourClock(12, 45, 18);
    ClockType tempClock; 

    //tempClock = myClock;
    cout<<"Temp data:" ;
    myClock.printTime();

    myClock++;
    myClock.printTime();

    cout << (myClock == tempClock) << endl;



    cout << "Hello world!" << endl;
    return 0;
}
