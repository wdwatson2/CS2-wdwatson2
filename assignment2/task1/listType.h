//Header file listType.h
#ifndef H_listType
#define H_listType 

#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class listType
{
public:
    bool isEmptyList() const;  
    // Function returns a nonzero value (TRUE)if list is empty,
    // otherwise it returns the value 0 (False)
    bool isFullList() const;  
    // Function returns a nonzero value (TRUE)if list is full,
    // otherwise it returns the value 0 (False)
    void setLength(int len);
    int showLength() const;
    void search(T searchItem) const; 
    // Search the list for searchItem
    // Postcondition: found is set to a nonzero value (TRUE)if     
    //    searchItem is found in the list, 
    //    otherwise found is set to 0(False)
    void insert(T newElement); //not defined
    // Inserte newElement in the list
    // Prior to insertion list must not be full
    // Postcondition: list is old list plus the newElement 
    void deleteItem(T deleteElement);  //not defined
    // if deleteElement is found in the list it is deleted
    // If list is empty output the message "Cannot delete from the
    // empty list"
    // Postcondition: list is old list minus the deleteItem if 
    //   deleteItem is found in the list 
    void sort();  
    // sort the list
    // Precondition: list must exist
    // Postcondition: list elements are in ascending order
    void print() const; 
    // Output the elements of the list
    void getList(ifstream&);   
    // read and store elements in the list
    // Postcondition: length = number of elements in the list
    //    elements = array holding the input data
    void destroyList(); //not defined
    // Postcondition: length = 0
    void printList() const; //not defined
    // Output the elements of the list
    listType(int listSize); 
    // constructor with parameters
    // Create an array of size specified by the parameter listSize
    //  Postcondition: elements contains the base address 
    //    of the array, length = 0 and maxsize = listSize
    listType(); 
    // default constructor
    // Create an array of 50 components 
    //  Postcondition: elements contains the base address 
    //    of the array, length = 0 and maxsize = 50
    ~listType(); 
    // destructor
    // delete all elements of the list
    // Postcondition: array elements is deleted
protected:
    void binarySeacrh(T searchItem,
                      int& found, int& index) const;
    
    int maxSize; // maximum number that can be stored in the list
    int length;  // number of elements in the list
    T *elements; //pointer to the array that holds list elements
};

template <class T>
void listType<T>::insert(T newElement) //not defined
{
    if(!(this->isFullList()))
    {
        elements[length] = newElement;
        length++;
    }
    else //list is full
    {
        cout << "List is full. Cannot insert new element" << endl;
    }
}
// Inserte newElement in the list
// Prior to insertion list must not be full
// Postcondition: list is old list plus the newElement 
template <class T>
void listType<T>::deleteItem(T deleteElement)  //not defined
{
    int found;
    int index;
    
    binarySeacrh(deleteElement,found,index);
    
    if (found)
    {
        for(int i = index; i < length; i++)
        {
            elements[i] = elements[i+1];
        }
        length--;
    }
    else
        cout << "Cannot delete from the empty list" << endl;
}
// if deleteElement is found in the list it is deleted
// If list is empty output the message "Cannot delete from the
// empty list"
// Postcondition: list is old list minus the deleteItem if 
//   deleteItem is found in the list 

template <class T>
listType<T>::listType(int listSize) 
{
    maxSize = listSize;
    length = 0;
    elements = new T[maxSize];
}

template <class T>
listType<T>::listType()  // default constructor
{
    maxSize = 50;
    length = 0;
    elements = new T[50];
}

template <class T>
listType<T>::~listType()  //destructor
{
    delete [] elements;
}


template <class T>
bool listType<T>::isEmptyList() const
{
    return (length == 0);
}

template <class T>
bool listType<T>::isFullList() const
{
    return (length == maxSize );
}

template <class T>
void listType<T>::sort()   //selection sort
{
    int i, j;
    int min;
    T temp;
    
    for (i = 0; i <length; i++)
    {
        min = i;
        for (j = i+1; j < length; ++j)
            if (elements[j] < elements[min])
                min = j;
        
        temp = elements[i];
        elements[i] = elements[min];
        elements[min] = temp;
    }//end for
}//end sort

template <class T>
void listType<T>::print() const
{
    int i;
    
    for (i = 0; i < length; i++)
        cout << elements[i] << endl;
}//end print

template <class T>
void listType<T>::getList(ifstream& infile)
{
    int i;
    
    for (i = 0; i < length; i++)
        infile >> elements[i];	
}

template <class T>
void listType<T>::search(T searchItem) const
{
    int found;
    int index;
    
    binarySeacrh(searchItem,found,index);
    
    if (found)
        cout << "Item is in the list" << endl;
    else
        cout << "Item is not in the list" << endl;
}

template <class T>
void listType<T>::binarySeacrh(T searchItem,
                               int& found, int& index) const
{
    int first = 0;
    int last = length -1;
    int mid;
    
    found = 0;
    
    while( !found && (first <= last))
    {
        mid = (first + last) / 2;
        
        if (elements[mid] == searchItem)
            found = 1;
        else if (elements[mid] > searchItem)
            last = mid - 1;
        else
            first = mid + 1;
    }
    
    index = mid;
}

template <class T>
void listType<T>::setLength(int len)
{
    length = len;
}

template <class T>
int listType<T>::showLength() const
{
    return length;
}


#endif 
