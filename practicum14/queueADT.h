//
//
//  InfixPostfix
//
//  Created by Antoun, Sherine on 11/11/21.
//  Copyright © 2021 Antoun, Sherine. All rights reserved.
//
//  Header file: queueADT.h

#ifndef H_QUEUEADT 
#define H_QUEUEADT
  
template <class Type>
class queueADT 
{
public:
    virtual void initializeQueue() = 0;
       //Method to initialize the queue to an empty state.
       //Postcondition: queue is empty

    virtual bool isEmptyQueue() const = 0;
      //Function to determine whether the queue is empty.
      //Postcondition: Returns true if the queue is empty,
      //               otherwise returns false.

    virtual bool isFullQueue() const = 0;
      //Function to determine whether the queue is full.
      //Postcondition: Returns true if the queue is full,
      //               otherwise returns false.

    virtual void push(const Type& newItem) = 0;
      //Function to add newItem to the queue.
      //Precondition: The queue exists and is not full.
      //Postcondition: The queue is changed and newItem 
      //               is added to the top of the queue.

    virtual Type bottom() const = 0;
      //Function to return the bottom element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: If the queue is empty, the program 
      //               terminates; otherwise, the bottom element
      //               of the queue is returned.

    virtual void pop() = 0;
      //Function to remove the bottom element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: The queue is changed and the top 
      //               element is removed from the queue.
};
        
#endif
