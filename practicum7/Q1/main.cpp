#include <iostream>
#include <random>
#include <time.h>

using namespace std;

// #define TEST
// #define TEST2
// #define TEST3

/*
Write a program that creates three identical arrays, list1, list2, and list3, of
5000 elements, populate all lists with identical data sets of random longs
you generate using the random library. The program then sorts list1 using
bubble sort, list2 using selection sort, and list3 using insertion sort and
outputs the number of comparisons and item assignments made by each
sorting algorithm. All data should be stored in dynamically allocated
arrays, and cleaned up at the end not leaked.
*/

void bubbleSort(long * list, int size, long & numComparisons);

void selectionSort(long * list, int size, long & numComparisons); 

void insertionSort(long * list, int size, long & numComparisons);

int main()
{
    long * list1 = new long[5000];
    long * list2 = new long[5000];
    long * list3 = new long[5000];

    for(int i = 0; i < 5000; i++)
    {
        srand(i*time(NULL)); //seeding the random number generator with index so I can have new number each iteration
        list1[i] = rand();
        list2[i] = rand();
        list3[i] = rand();
    }

    for(int i = 0; i < 5000; i++)
    {
        cout << list1[i] << " ";
    }
    cout << endl;

    //bubble sort list1
    //initiallizing variables for bubble sort
    long numComparisons = 0;

    bubbleSort(list1, 5000, numComparisons);
    cout << "List sorted in " << numComparisons << " with Bubble Sort." << endl;

    for(int i = 0; i < 5000; i++)
    {
        cout << list1[i] << " ";
    }
    cout << endl;

#ifdef TEST
    long testComparisons = 0;
    long * test = new long[3]{1, 3, 2};
    bubbleSort(test, 3, testComparisons);
    for(int i = 0; i < 3; i++)
    {
        cout << test[i] << endl;
    }
    cout << "In " << testComparisons << " comparisons." << endl;
    delete [] test;
#endif

    //selection sort list2
    numComparisons = 0;
    selectionSort(list2, 5000, numComparisons);
    cout << "List sorted in " << numComparisons << " with Selection Sort." << endl;

#ifdef TEST2
    long testComparisons = 0;
    long * test = new long[]{1, 3, 2, 7, 2, 1};
    selectionSort(test, 6, testComparisons);
    for(int i = 0; i < 6; i++)
    {
        cout << test[i] << endl;
    }
    cout << "In " << testComparisons << " comparisons." << endl;
    delete [] test;
#endif

    //insertion sort list3
    numComparisons = 0;
    insertionSort(list3, 5000, numComparisons);
    cout << "List sorted in " << numComparisons << " with Insertion Sort." << endl;

#ifdef TEST3
    long testComparisons = 0;
    long * test = new long[]{1, 3, 2, 7, 2, 1};
    insertionSort(test, 6, testComparisons);
    for(int i = 0; i < 6; i++)
    {
        cout << test[i] << endl;
    }
    cout << "In " << testComparisons << " comparisons." << endl;
    delete [] test;
#endif
    delete[] list1;
    delete[] list2;
    delete[] list3;
    
    return 0;
}

void bubbleSort(long * list, int size, long & numComparisons)
{
    long temp;
    bool noSwaps = false;
    while(!noSwaps)
    {
        noSwaps = true;
        for(int i = 1; i < size; i++)
        {
            numComparisons++;
            if(list[i] < list[i-1])
            {
                noSwaps = false;
                //swap
                temp = list[i];
                list[i] = list[i-1];
                list[i-1] = temp;
            }
        }
    }
}

void selectionSort(long * list, int size, long & numComparisons)
{
    int i, j, min_idx; 
    long temp;

    // One by one move boundary of 
    // unsorted subarray 
    for (i = 0; i < size-1; i++)
    {
        // Find the minimum element in 
        // unsorted array 
        min_idx = i; 
        for (j = i+1; j < size; j++)
        {
            numComparisons++;
            if (list[j] < list[min_idx]) 
              min_idx = j;
        }
        // Swap the found minimum element 
        // with the first element 
        if (min_idx!=i)
        {
            temp = list[min_idx];
            list[min_idx] = list[i];
            list[i] = temp;
        }

    }
}

void insertionSort(long * list, int size, long & numComparisons)
{
    long temp;
    for(int i = 1; i <size; i++)
    {
        int j = i;
        while(j > 0 && list[j-1] > list[j])
        {
            numComparisons++;
            temp = list[j-1];
            list[j-1] = list[j];
            list[j] = temp;
            j = j-1;
        }
        numComparisons++;
    }
}
