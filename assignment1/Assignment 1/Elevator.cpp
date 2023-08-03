//
//  Elevator.cpp
//  Created by Sherine Antoun on 4/21/20.
//  Copyright © 2020 Sherine Antoun. All rights reserved.
   
#include "Elevator.h"
#include <iostream>

using namespace std;

// constructor for number of floors - no default constructor
Elevator::Elevator(int floors)
{
    maxfloor = floors;    // highest numbered floor in the building

    currentfloor = 0;   //initializing current floor to be the bottom floor

    currentdirection = STOPPED;   //initializing current direction to be stopped

    dooropen = 0;   //initializing door to be shut

    floorup = new bool[floors+1];  //allocating space for outside up buttons and initializing them to false
    if(floorup == 0)
        exit(1);

    floordown = new bool[floors+1];   //allocating space for outside down buttons and initializing them to false
    if(floorup == 0)
        exit(1);

    button = new bool[floors+1];    //allocating space for internal buttons and initializing them to false
    if(floorup == 0)
        exit(1);
    //i need to allocate space for floor up, floor down, and button
}

//Destructor
Elevator::~Elevator()   
{
    delete[] floorup;
    delete[] floordown;
    delete[] button;
}

// report current status: floor, direction, door status
void Elevator::Move() 
{
    dooropen = 0; //close doors if they are open
    bool isRequestAbove = false; 
    bool isRequestBelow = false;

    for(int i = 0; i < maxfloor+1; i++)
    {
        if(button[i] || floorup[i] || floordown[i]) //checking for requests
        {
            if(currentfloor >= i)
                isRequestBelow = true; //there is at least one request below current floor
            else if(currentfloor <= i)
                isRequestAbove = true; //there is at least one request above current floor
        }
    }

    if(currentdirection == STOPPED)//previously no requests were made
    {
        if(isRequestAbove)
            currentdirection = UP; //however, if there are requests on this round then change direction accordingly
        if(isRequestBelow)
            currentdirection = DOWN;
    }
    if((currentdirection == UP && isRequestAbove) || (currentdirection == DOWN && !isRequestBelow && isRequestAbove))//
    {
        //if there are requests in the currentdirection or change direction if there are no requests below but some above
        currentdirection = UP;
        currentfloor++;//move floor up
        
        if(button[currentfloor] || floorup[currentfloor]){ //check for request on current floor
            dooropen = 1;
            button[currentfloor] = false; //erasing requests
            floorup[currentfloor] = false;
            if(currentfloor == maxfloor) //if maxfloor is reached then the elevator must move down on the next round
                currentdirection = DOWN;
        }        
        else if(floordown[currentfloor]){
            //if there are no requests above this one than we can stop and pick this person up
            int floorAbove = maxfloor;
            currentdirection = DOWN; //initiallizing to pick this person up
            dooropen = 1;
            floordown[currentfloor] = false;
        
            while(floorAbove > currentfloor){ //but if there are requests above, then do not pick this person up
                if(button[floorAbove] || floorup[floorAbove] || floordown[floorAbove])
                {
                    currentdirection = UP;
                    dooropen = 0;
                    floordown[currentfloor] = true;
                    floorAbove = currentfloor+1;
                }
                floorAbove--; 
            }
        }
    }
    else if ((currentdirection == DOWN && isRequestBelow) || (currentdirection == UP && !isRequestAbove && isRequestBelow))
    {
        //if there are requests in the direction of travel or change the direction if there were no requests in the up direction
        currentdirection = DOWN;
        currentfloor--;
        if(button[currentfloor] || floordown[currentfloor]){ //request on current floor
            // currentdirection = STOPPED;
            dooropen = 1;
            button[currentfloor] = false;
            floordown[currentfloor] = false;
            if(currentfloor == 0)
                currentdirection = UP;
        }
        else if(floorup[currentfloor]){
            //if there are no requests below this one than we can stop and pick this person up
            int floorBelow = 0;
            currentdirection = UP;
            dooropen = 1;
            floorup[currentfloor] = false;
        
            while(floorBelow < currentfloor){
                if(button[floorBelow] || floorup[floorBelow] || floordown[floorBelow])
                {
                    currentdirection = DOWN;
                    dooropen = 0;
                    floorup[currentfloor] = true;
                    floorBelow = currentfloor-1;
                }
                floorBelow++;
            }
        }
    }
    else //if all the previous failed then there must be no current requests currently
    {
        currentdirection = STOPPED;
    }
}

//talk to the driver program
void Elevator::Status(int& currentFloor, int& currDir,int& doorIsOpen)//FIXED
{
    currentFloor = currentfloor;
    currDir = currentdirection;
    doorIsOpen = dooropen;
}

// handle rider request outside elevator
void Elevator::DirectionSelect(int floorNum, int direction)
{
    if (direction == DOWN)
        floordown[floorNum] = true;
    else
        floorup[floorNum] = true;

    
}
// handle rider request inside elevator
void Elevator::ChooseFloor(int floorchosen)
{
    button[floorchosen] = true;
}



