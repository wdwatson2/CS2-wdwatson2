#include <iostream>
#include <cstdlib>
#include "Elevator.h"

using namespace std;


int main(){
    int floor, direction, door;

    Elevator e(10);
    e.Move();

    e.Status(floor, direction, door);
        cout << "Elevator is on floor " << floor << " with the doors ";
        if (door)
            cout << "open.";
        else
            cout << "closed.";
        if (direction == UP)
            cout << " Going up.";
        else if (direction == DOWN)
            cout << " Going down.";
        else
            cout << " Stopped.";
        cout << endl;

    e.DirectionSelect(2, UP);

    e.Move();

    e.Status(floor, direction, door);

        cout << "Elevator is on floor " << floor << " with the doors ";
        if (door)
            cout << "open.";
        else
            cout << "closed.";
        if (direction == UP)
            cout << " Going up.";
        else if (direction == DOWN)
            cout << " Going down.";
        else
            cout << " Stopped.";
        cout << endl;


    e.DirectionSelect(3, DOWN);

    e.Move();

    e.Status(floor, direction, door);
        cout << "Elevator is on floor " << floor << " with the doors ";
        if (door)
            cout << "open.";
        else
            cout << "closed.";
        if (direction == UP)
            cout << " Going up.";
        else if (direction == DOWN)
            cout << " Going down.";
        else
            cout << " Stopped.";
        cout << endl;



    return 0;
}