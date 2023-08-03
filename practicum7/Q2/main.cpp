#include <iostream>

using namespace std;

#define INTS
// #define CHARS

template<typename T>
void sequentialSearch(T list[], unsigned size, T & key, bool & found, int & index, int & numComparisons);

int main()
{
#ifdef INTS
    //creating an initial array of ints to search through
    int nums[] = {1,2,3,4,5,6,7,90,56};
    int key;
#endif
#ifdef CHARS
    //creating an intial array of char to search through
    char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char key;
#endif

    bool found = false;
    int index = 0;
    int numComparisons = 0;

    cout << "Enter key: ";
    cin >> key;
    
#ifdef INTS
    sequentialSearch<int>(nums, sizeof(nums)/sizeof(int), key, found, index, numComparisons);
#endif
#ifdef CHARS
    sequentialSearch<char>(letters, sizeof(letters)/sizeof(char), key, found, index, numComparisons);
#endif
    if(found)
    {
        cout << key << " was found at index " << index << endl;
        cout << "It took " << numComparisons << " comparisons to find it" << endl;
    }
    else
    {
        cout << key << " was not found in the list." << endl;
    }
    return 0;
}

template<typename T>
void sequentialSearch(T list[], unsigned size, T & key, bool & found, int & index, int & numComparisons)
{
    numComparisons++;
    if(index == size)
    {
    }
    else if(list[index] == key)
    {
        found = true;
    }
    else
    {
        index++;
        sequentialSearch(list, size, key, found, index, numComparisons);
    }
}

