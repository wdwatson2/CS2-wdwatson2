#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <chrono>
#include <iostream>
#include <cassert>
#include "linkedList.h"

using namespace std;

class insertionsort
{
    unsigned long long numComparisons = 0;
    unsigned long long execTime; //in nanoseconds
    unsigned long long numSwaps = 0;
public:
    insertionsort(LinkedList<double> &);

    unsigned long long getNumComparisons();
    unsigned long long getExecTime();
    unsigned long long getNumSwaps();


    bool comparison(const double &, const double &);
    void exchange(LinkedList<double> &, int, int); //needs to be implemented
};

bool insertionsort::comparison(const double & num1, const double & num2)
{
    numComparisons++;
    return (num1 > num2);
}

void insertionsort::exchange(LinkedList<double> & list, int num1, int num2)
{
    double temp = list.get(num1);
    list.set(num1, list.get(num2));
    list.set(num2, temp);

    numSwaps++;
}   

insertionsort::insertionsort(LinkedList<double> & list)
{
    auto start = chrono::high_resolution_clock::now(); //start timer
    //insertion sort algorithm:
    for(int i = 1; i < list.getSize(); i++)
    {
        int j = i;
        while(j > 0 && comparison(list.get(j-1), list.get(j)))
        {
            exchange(list, j-1, j);
            j--;
        }
    }

    auto stop = chrono::high_resolution_clock::now();//end timer
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start); //find difference 
    execTime = duration.count();
}

unsigned long long insertionsort::getExecTime()
{
    return execTime;
}

unsigned long long insertionsort::getNumComparisons()
{
    return numComparisons;
}

unsigned long long insertionsort::getNumSwaps()
{
    return numSwaps;
}

#endif