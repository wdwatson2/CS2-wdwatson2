#include "listType.h"
#include <iostream>

using namespace std;

template <typename T>
class unorderedListType : public listType<T>
{
public:
    void sort();//overwriting sort to not do anything
    void sequentialSeacrh(T searchItem,int& found, int& index) const; 
    void search(T searchItem) const;
    unorderedListType();
    unorderedListType(int size);
    ~unorderedListType();
};

template<typename T>
unorderedListType<T>::unorderedListType()
{
}

template<typename T>
unorderedListType<T>::unorderedListType(int size): listType<T>::listType(size)
{
}

template<typename T>
unorderedListType<T>::~unorderedListType()
{
}

template<typename T>
void unorderedListType<T>::sort()
{
    //nothing. I really am not understanding what the point of this class is
}

template<typename T>
void unorderedListType<T>::sequentialSeacrh(T searchItem,int& found, int& index) const
{
    //inherited binarysearch will not work since the list must be sorted to work
    found = 0;
    index = 0;

    for(int i = 0; i < this->showLength(); i++)
    {
        if(this->elements[i] == searchItem)
        {
            found = 1;
            index = i;
            break;
        }
    }
}

template <typename T>
void unorderedListType<T>::search(T searchItem) const
{
    int found;
    int index;
    
    sequentialSeacrh(searchItem,found,index);
    
    if (found)
        cout << "Item is in the list" << endl;
    else
        cout << "Item is not in the list" << endl;
}
