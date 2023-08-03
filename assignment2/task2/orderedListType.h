#include "listType.h"
#include <iostream>
#include <fstream>

using namespace std;

template <typename T>
class orderedListType : public listType<T>
{
public:
    void print();//It will sort before printing.
    void insert(T newElement); //not defined
    void deleteItem(T deleteElement);  //not defined

    //no idea what else to add, besides sorting, which listType already has, what is is special about making this ordered?

    orderedListType();
    orderedListType(int size);
};

template <typename T> 
orderedListType<T>::orderedListType():listType<T>::listType()
{
}

template <typename T> 
orderedListType<T>::orderedListType(int size) : listType<T>::listType(size)
{
}

template <typename T>
void orderedListType<T>::print()
{
    listType<T>::sort();
    listType<T>::print();
}

template <typename T>
void orderedListType<T>::insert(T newElement) //not defined
{
    listType<T>::insert(newElement);
    listType<T>::sort();
}

template <typename T>
void orderedListType<T>::deleteItem(T deleteElement)  //not defined
{
    listType<T>::deleteItem(deleteElement);
    listType<T>::sort();
}
