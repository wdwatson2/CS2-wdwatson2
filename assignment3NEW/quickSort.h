#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "insertionSort.h"

using namespace std;

long numComparisonsQuickSort = 0;
long numExchangesQuickSort = 0;

void exchangeQuickSort(double list[], int index1, int index2);
bool comparisonQuickSort(const double num1, const double num2);

int partitionMiddle(double list[], int low, int high, bool switchPivot);
void quickSortMiddle(double list[], int low, int high, bool switchPivot);

void quickSortMedian(double list[], int low, int high, bool switchPivot);
int partitionMedian(double list[], int low, int high, bool switchPivot);

void quickSortMiddleInsertionSort(double list[], int low, int high, bool switchPivot);
int partitionMiddleInsertionSort(double list[], int low, int high, bool switchPivot);

void quickSortMedianInsertionSort(double list[], int low, int high, bool switchPivot);
int partitionMedianInsertionSort(double list[], int low, int high, bool switchPivot);



void exchangeQuickSort(double list[], int index1, int index2)
{
    double temp = list[index1];
    list[index1] = list[index2];
    list[index2] = temp;

    numExchangesQuickSort++;
}

bool comparisonQuickSort(const double num1, const double num2)
{
    numComparisonsQuickSort++;
    return(num1 <= num2);
}

void quickSortMiddle(double list[], int low, int high, bool switchPivot)
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
    quickSortMiddle(list, low, p - 1, false);
 
    // Sorting the right part
    quickSortMiddle(list, p + 1, high, false);

}

int partitionMiddle(double list[], int low, int high, bool switchPivot)
{
    if(switchPivot)
        exchangeQuickSort(list, (high/2), low); //to use middle element as pivot by switching middle element with low element
    
    double pivot = list[low];
 
    int count = 0;
    for (int i = low + 1; i <= high; i++) {
        if (comparisonQuickSort(list[i], pivot))
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = low + count;
    exchangeQuickSort(list, pivotIndex, low);
 
    // Sorting left and right parts of the pivot element
    int i = low, j = high;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (comparisonQuickSort(list[i], pivot)) {
            i++;
        }
 
        while (!comparisonQuickSort(list[j], pivot)) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            exchangeQuickSort(list, i++, j--);
        }
    }
 
    return pivotIndex;

}

void quickSortMedian(double list[], int low, int high, bool switchPivot)
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
    quickSortMedian(list, low, p - 1, false);
 
    // Sorting the right part
    quickSortMedian(list, p + 1, high, false);

}

int partitionMedian(double list[], int low, int high, bool switchPivot)
{
    if(switchPivot)
    {
        if(list[high] > list[high/2])
            exchangeQuickSort(list, high, high/2);
        if(list[low] > list[high/2])
            exchangeQuickSort(list, low, high/2);
        if(list[high] > list[low])
            exchangeQuickSort(list, low, high);
    }
    
    double pivot = list[low];
 
    int count = 0;
    for (int i = low + 1; i <= high; i++) {
        if (comparisonQuickSort(list[i], pivot))
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = low + count;
    exchangeQuickSort(list, pivotIndex, low);
 
    // Sorting left and right parts of the pivot element
    int i = low, j = high;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (comparisonQuickSort(list[i], pivot)) {
            i++;
        }
 
        while (!comparisonQuickSort(list[j], pivot)) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            exchangeQuickSort(list, i++, j--);
        }
    }
 
    return pivotIndex;

}

void quickSortMiddleInsertionSort(double list[], int low, int high, bool switchPivot)
{
    while (low < high)
    {
        // switch to insertion sort if the size is 10 or smaller
        if (high - low < 20)
        {
            insertionSort(list, low, high);
            break;
        }
        else {
            int p;
            if(switchPivot)
                p = partitionMiddleInsertionSort(list, low, high, true);
            else
                p = partitionMiddleInsertionSort(list, low, high, false);
 
            // tail call optimizations – recur on the smaller subarray
            if (p - low < high - p)
            {
                quickSortMiddleInsertionSort(list, low, p - 1, false);
                low = p + 1;
            }
            else {
                quickSortMiddleInsertionSort(list, p + 1, high, false);
                high = p - 1;
            }
        }
    }

}

int partitionMiddleInsertionSort(double list[], int low, int high, bool switchPivot)
{
    if(switchPivot)
        exchangeQuickSort(list, (high/2), low); 

    
    double pivot = list[low];
 
    int count = 0;
    for (int i = low + 1; i <= high; i++) {
        if (comparisonQuickSort(list[i], pivot))
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = low + count;
    exchangeQuickSort(list, pivotIndex, low);
 
    // Sorting left and right parts of the pivot element
    int i = low, j = high;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (comparisonQuickSort(list[i], pivot)) {
            i++;
        }
 
        while (!comparisonQuickSort(list[j], pivot)) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            exchangeQuickSort(list, i++, j--);
        }
    }
 
    return pivotIndex;

}

void quickSortMedianInsertionSort(double list[], int low, int high, bool switchPivot)
{
    while (low < high)
    {
        // switch to insertion sort if the size is 10 or smaller
        if (high - low < 20)
        {
            insertionSort(list, low, high);
            break;
        }
        else {
            int p;
            if(switchPivot)
                p = partitionMedianInsertionSort(list, low, high, true);
            else
                p = partitionMedianInsertionSort(list, low, high, false);
 
            // tail call optimizations – recur on the smaller subarray
            if (p - low < high - p)
            {
                quickSortMedianInsertionSort(list, low, p - 1, false);
                low = p + 1;
            }
            else {
                quickSortMedianInsertionSort(list, p + 1, high, false);
                high = p - 1;
            }
        }
    }

}

int partitionMedianInsertionSort(double list[], int low, int high, bool switchPivot)
{
    if(switchPivot)
    {
        if(list[high] > list[high/2])
            exchangeQuickSort(list, high, high/2);
        if(list[low] > list[high/2])
            exchangeQuickSort(list, low, high/2);
        if(list[high] > list[low])
            exchangeQuickSort(list, low, high);
    }

    
    double pivot = list[low];
 
    int count = 0;
    for (int i = low + 1; i <= high; i++) {
        if (comparisonQuickSort(list[i], pivot))
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = low + count;
    exchangeQuickSort(list, pivotIndex, low);
 
    // Sorting left and right parts of the pivot element
    int i = low, j = high;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (comparisonQuickSort(list[i], pivot)) {
            i++;
        }
 
        while (!comparisonQuickSort(list[j], pivot)) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            exchangeQuickSort(list, i++, j--);
        }
    }
 
    return pivotIndex;

}


#endif