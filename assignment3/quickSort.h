#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <chrono>
#include <iostream>
#include <cassert>
#include <stdexcept>
#include "linkedList.h"
#include "insertionSort.h"

using namespace std;

class quicksort
{
    unsigned long long numComparisons = 0;
    // unsigned long long execTime = 0; //in nanoseconds
    unsigned long long numSwaps = 0;
    // int pivot = 0;
public:
    quicksort();

    void quicksortMiddle(LinkedList<double> &, int low, int high, bool switchPivot); //best way to do it
    void quicksortMedian(LinkedList<double> &, int low, int high, bool switchPivot);
    void quicksortMiddleAndInsertion(LinkedList<double> &, int low, int high, bool switchPivot);
    void quicksortMedianAndInsertion(LinkedList<double> &, int low, int high, bool switchPivot);

    int partitionMiddle(LinkedList<double> &, int low, int high, bool switchPivot); //done
    int partitionMedian(LinkedList<double> &, int low, int high, bool switchPivot);
    int partitionMiddleAndInsertion(LinkedList<double> &, int low, int high, bool switchPivot);
    int partitionMedianAndInsertion(LinkedList<double> &, int low, int high, bool switchPivot);

    void insertionsortOnIntv(LinkedList<double> &, int low, int high); //sort starting at index low up to index high

    unsigned long long getNumComparisons();//getters
    // unsigned long long getExecTime();
    unsigned long long getNumSwaps();

    bool comparison(const double &, const double &);//counters
    void exchange(LinkedList<double> & list, int i, int j);
};

quicksort::quicksort()//simply just exists. Its methods do all the work
{
    // auto start = chrono::high_resolution_clock::now(); //start timer

    //algorithm

    // auto stop = chrono::high_resolution_clock::now();//end timer
    // auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start); //find difference 
    // execTime = duration.count();
}

unsigned long long quicksort::getNumSwaps()
{
    return numSwaps;
}

unsigned long long quicksort::getNumComparisons()
{
    return numComparisons;
}

void quicksort::exchange(LinkedList<double> & list, int i, int j)
{
    try{
    double temp = list.get(i);
    list.set(i, list.get(j));
    list.set(j, temp);
    numSwaps++;
    }
    catch(std::out_of_range& ba)
    {
        cout << ba.what() << "index 1: " <<  i << "index2: " << j << endl;
    }
}

bool quicksort::comparison(const double & num1, const double & num2)
{
    numComparisons++;
    return (num1 <= num2);
}

//quicksort with middle element as pivot
void quicksort::quicksortMiddle(LinkedList<double> & list, int low, int high, bool switchPivot)
{
    if (low >= high)
        return;
 
    // partitioning the array
    int p;
    if(switchPivot)
        p = partitionMiddle(list, low, high, true);
    else
        p = partitionMiddle(list, low, high, false);
 
    // Sorting the left part
    quicksortMiddle(list, low, p - 1, false);
 
    // Sorting the right part
    quicksortMiddle(list, p + 1, high, false);
}

int quicksort::partitionMiddle(LinkedList<double> & list, int low, int high, bool switchPivot)
{
    if(switchPivot)
        exchange(list, (high/2), low); //to use middle element as pivot by switching middle element with high element
    
    double pivot = list.get(low);
 
    int count = 0;
    for (int i = low + 1; i <= high; i++) {
        if (comparison(list.get(i), pivot))
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = low + count;
    exchange(list, pivotIndex, low);
 
    // Sorting left and right parts of the pivot element
    int i = low, j = high;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (comparison(list.get(i), pivot)) {
            i++;
        }
 
        while (!comparison(list.get(j), pivot)) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            exchange(list, i++, j--);
        }
    }
 
    return pivotIndex;
}

//sort starting at index low up to index high
void quicksort::insertionsortOnIntv(LinkedList<double> & list, int low, int high)//works
{
    for(int i = low + 1; i < high+1; i++)
    {
        int j = i;
        while(j > 0 && comparison(list.get(j), list.get(j-1)))
        {
            exchange(list, j-1, j);
            // temp = list.get(j-1);
            // list.set(j-1, list.get(j));
            // list.set(j, temp);
            j--;
        }
    }
}

void quicksort::quicksortMiddleAndInsertion(LinkedList<double> & list, int low, int high, bool switchPivot)
{
    while (low < high)
    {
        // switch to insertion sort if the size is 10 or smaller
        if (high - low < 20)
        {
            insertionsortOnIntv(list, low, high);
            break;
        }
        else {
            int p;
            if(switchPivot)
                p = partitionMiddleAndInsertion(list, low, high, true);
            else
                p = partitionMiddleAndInsertion(list, low, high, false);
 
            // tail call optimizations – recur on the smaller subarray
            if (p - low < high - p)
            {
                quicksortMiddleAndInsertion(list, low, p - 1, false);
                low = p + 1;
            }
            else {
                quicksortMiddleAndInsertion(list, p + 1, high, false);
                high = p - 1;
            }
        }
    }
}

int quicksort::partitionMiddleAndInsertion(LinkedList<double> & list, int low, int high, bool switchPivot)
{
    if(switchPivot)
    {
        exchange(list, (high/2), low); 
    }

    double pivot = list.get(low);
 
    int count = 0;
    for (int i = low + 1; i <= high; i++) {
        if (comparison(list.get(i), pivot))
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = low + count;
    exchange(list, pivotIndex, low);
 
    // Sorting left and right parts of the pivot element
    int i = low, j = high;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (comparison(list.get(i), pivot)) {
            i++;
        }
 
        while (!comparison(list.get(j), pivot)) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            exchange(list, i++, j--);
        }
    }
 
    return pivotIndex;
}

//quicksort with median(low, middle, high) as pivot
void quicksort::quicksortMedian(LinkedList<double> & list, int low, int high, bool switchPivot)
{
    if (low >= high)
        return;
 
    // partitioning the array
    int p;
    if(switchPivot)
        p = partitionMedian(list, low, high, true);
    else
        p = partitionMedian(list, low, high, false);
 
    // Sorting the left part
    quicksortMedian(list, low, p - 1, false);
 
    // Sorting the right part
    quicksortMedian(list, p + 1, high, false);
}

int quicksort::partitionMedian(LinkedList<double> & list, int low, int high, bool switchPivot)
{
    //to use the median of low middle and high we have to swap their places such that the median is in the high position
    if(switchPivot)
    {
        if(list.get(high) > list.get(high/2))
            exchange(list, high, high/2);
        if(list.get(low) > list.get(high/2))
            exchange(list, low, high/2);
        if(list.get(high) > list.get(low))
            exchange(list, low, high);
    }
    double pivot = list.get(low);
 
    int count = 0;
    for (int i = low + 1; i <= high; i++) {
        if (comparison(list.get(i), pivot))
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = low + count;
    exchange(list, pivotIndex, low);
 
    // Sorting left and right parts of the pivot element
    int i = low, j = high;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (comparison(list.get(i), pivot)) {
            i++;
        }
 
        while (!comparison(list.get(j), pivot)) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            exchange(list, i++, j--);
        }
    }
 
    return pivotIndex;
}

void quicksort::quicksortMedianAndInsertion(LinkedList<double> & list, int low, int high, bool switchPivot)
{
    while (low < high)
    {
        // switch to insertion sort if the size is 10 or smaller
        if (high - low < 20)
        {
            insertionsortOnIntv(list, low, high);
            break;
        }
        else {
            int p;
            if(switchPivot)
                p = partitionMedianAndInsertion(list, low, high, true);
            else
                p = partitionMedianAndInsertion(list, low, high, false);
 
            // tail call optimizations – recur on the smaller subarray
            if (p - low < high - p)
            {
                quicksortMedianAndInsertion(list, low, p - 1, false);
                low = p + 1;
            }
            else {
                quicksortMedianAndInsertion(list, p + 1, high, false);
                high = p - 1;
            }
        }
    }
}

int quicksort::partitionMedianAndInsertion(LinkedList<double> & list, int low, int high, bool switchPivot)
{
    //to use the median of low middle and high we have to swap their places such that the median is in the high position
    if(switchPivot)
    {
        if(list.get(high) > list.get(high/2))
            exchange(list, high, high/2);
        if(list.get(low) > list.get(high/2))
            exchange(list, low, high/2);
        if(list.get(high) > list.get(low))
            exchange(list, low, high);
    }

    double pivot = list.get(low);
 
    int count = 0;
    for (int i = low + 1; i <= high; i++) {
        if (comparison(list.get(i), pivot))
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = low + count;
    exchange(list, pivotIndex, low);
 
    // Sorting left and right parts of the pivot element
    int i = low, j = high;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (comparison(list.get(i), pivot)) {
            i++;
        }
 
        while (!comparison(list.get(j), pivot)) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            exchange(list, i++, j--);
        }
    }
 
    return pivotIndex;
}

#endif