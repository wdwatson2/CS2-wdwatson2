//
//
//  InfixPostfix
//
//  Created by Antoun, Sherine on 11/11/21.
//  Copyright © 2021 Antoun, Sherine. All rights reserved.
//  Header file: myStack.h

#ifndef H_QueueType
#define H_QueueType
  
#include <iostream> 
#include <cassert>
 
#include "queueADT.h"

using namespace std;

template <class Type>
class queueType: public queueADT<Type>
{
public:
    const queueType<Type>& operator=(const queueType<Type>&); 
      //Overload the assignment operator.

    void initializeQueue();
       //Method to initialize the queue to an empty state.
       //Postcondition: queue is empty

    bool isEmptyQueue() const;
      //Function to determine whether the queue is empty.
      //Postcondition: Returns true if the queue is empty,
      //               otherwise returns false.

    bool isFullQueue() const;
      //Function to determine whether the queue is full.
      //Postcondition: Returns true if the queue is full,
      //               otherwise returns false.

    void push(const Type& newItem);
      //Function to add newItem to the queue.
      //Precondition: The queue exists and is not full.
      //Postcondition: The queue is changed and newItem 
      //               is added to the top of the queue.

    Type bottom() const;
      //Function to return the bottom element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: If the queue is empty, the program 
      //               terminates; otherwise, the bottom element
      //               of the queue is returned.

    void pop();
      //Function to remove the bottom element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: The queue is changed and the top 
      //               element is removed from the queue.

    queueType(int queueSize = 100); 
      //constructor
      //Create an array of the size queueSize to hold 
      //the queue elements. The default queue size is 100.

    queueType(const queueType<Type>& otherQueue); 
      //copy constructor

    ~queueType(); 
      //destructor
      //Remove all the elements from the queue.
      //Postcondition: The array (list) holding the queue 
      //               elements is deleted.

private:
    int maxQueueSize; //variable to store the maximum queue size
    int queueTop;     //variable to point to the bottom of the queue
    Type *list;       //pointer to the array that holds the
                      //queue elements

    void copyQueue(const queueType<Type>& otherQueue); 
      //Function to make a copy of otherQueue.
      //Postcondition: A copy of otherQueue is created and
      //               assigned to this queue.
};


template <class Type>
void queueType<Type>::initializeQueue()
{
    queueTop = 0;
}

template <class Type>
bool queueType<Type>::isEmptyQueue() const
{
    return(queueTop == 0);
}

template <class Type>
bool queueType<Type>::isFullQueue() const
{
    return(queueTop == maxQueueSize);
} 

template <class Type>
void queueType<Type>::push(const Type& newItem)
{
    if (!isFullQueue())
    {
        list[queueTop] = newItem;   //add newItem to the 
                                    //top of the queue
        queueTop++; //increment queueTop
    }
    else
        cout << "Cannot add to a full queue." << endl;
}//end push

template <class Type>
Type queueType<Type>::bottom() const
{
    assert(queueTop != 0);          //if queue is empty, 
                                    //terminate the program
    return list[0];      //return the element of the
                                    //stack indicated by 
                                    //stackTop - 1
}//end top

template <class Type>
void queueType<Type>::pop()
{
    if (!isEmptyQueue())
    {
      Type * listTemp = new Type[maxQueueSize];		   			   

      //copy otherStack into this stack
      for (int j = 1; j < queueTop; j++)  
        listTemp[j-1] = this->list[j];
      delete [] list;
      list = listTemp;
      queueTop--;
    }
    else
        cout << "Cannot remove from an empty queue." << endl;
}//end pop

template <class Type>
queueType<Type>::queueType(int queueSize)
{
    if (queueSize <= 0)
    {
        cout << "Size of the array to hold the queue must "
             << "be positive." << endl;
        cout << "Creating an array of size 100." << endl;

        maxQueueSize = 100;
    }
    else
        maxQueueSize = queueSize;   //set the stack size to 
                                    //the value specified by
                                    //the parameter stackSize

    queueTop = 0;                   //set stackTop to 0
    list = new Type[maxQueueSize];  //create the array to
                                    //hold the stack elements
}//end constructor

template <class Type>
queueType<Type>::~queueType() //destructor
{
    delete [] list; //deallocate the memory occupied 
                    //by the array
}

template <class Type>
void queueType<Type>::copyQueue(const queueType<Type>& otherQueue)
{ 
    delete [] list;				   
    maxQueueSize = otherQueue.maxQueueSize;	   
    queueTop = otherQueue.queueTop;			   
	  
    list = new Type[maxQueueSize];		   			   

        //copy otherStack into this stack
    for (int j = 0; j < queueTop; j++)  
        list[j] = otherQueue.list[j];
} //end copyStack


template <class Type>
queueType<Type>::queueType(const queueType<Type>& otherQueue)
{
    list = nullptr;

    copyQueue(otherQueue);
}

template <class Type>
const queueType<Type>& queueType<Type>::operator=
   					(const queueType<Type>& otherQueue)
{ 
    if (this != &otherQueue) //avoid self-copy
        copyQueue(otherQueue);

    return *this; 
} //end operator=         

#endif
