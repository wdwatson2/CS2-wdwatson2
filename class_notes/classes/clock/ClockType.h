#ifndef CLOCKTYPE_H
#define CLOCKTYPE_H
// #include <iostream>

class ClockType
{
        friend std::ostream& operator<<(std::ostream& osObject, const ClockType& );
        //friends are placed outside the scopes of private, protected and public
    public:
        ClockType();
        ClockType(int, int, int);
        void setTime(int hours, int minutes, int seconds); 
        void setHours(int hours);
        void setMinutes(int minutes);
        void setSeconds(int seconds);
        void getTime(int& hours, int&minutes, int& seconds) const;
        int getHours() const;
        int getMinutes() const;
        int getSeconds() const;
        void printTime()const;//dont want my own object changing when user calls this function
        ClockType operator++();
        //operator-- will call ++ and use the inverse
        //copy constructor - needs to take an instance of clocktype and return 
        bool operator==(const ClockType& otherClock) const;//current instance should not change and clocktype object should not change that is being passed ins
        bool operator<=(const ClockType& otherClock) const;//current instance should not change and clocktype object should not change that is being passed ins
        // ostream& operator<<(ostream& osObject, const ClockType& );//creating output stream     
    
    private:
        int hr, min, sec;
};

#endif // CLOCKTYPE_H
