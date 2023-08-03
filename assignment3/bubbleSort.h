#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <chrono>
#include <iostream>
#include <cassert>
#include "linkedList.h"

using namespace std;

class bubblesort
{
    unsigned long long numComparisons = 0;
    unsigned long long execTime; //in microseconds
    unsigned long long numSwaps = 0;
public:
    bubblesort(LinkedList<double> &);
    unsigned long long getNumComparisons();
    unsigned long long getExecTime();
    unsigned long long getNumSwaps();//needs to be imple

    bool comparison(const double &, const double &);
    void exchange(LinkedList<double> &, int, int);//needs to be
};

bool bubblesort::comparison(const double & num1, const double & num2)
{
    numComparisons++;
    return (num1 < num2);
}

void bubblesort::exchange(LinkedList<double> & list, int num1, int num2)
{
    double temp = list.get(num1);
    list.set(num1, list.get(num2));
    list.set(num2, temp);

    numSwaps++;
}

bubblesort::bubblesort(LinkedList<double> & list)
{
    auto start = chrono::high_resolution_clock::now(); //start timer
    double temp;
    bool noSwaps = false;
    while(!noSwaps)
    {
        noSwaps = true;
        for(int i = 1; i < list.getSize() ; i++)
        {
            if(comparison(list[i], list[i-1]))
            {
                noSwaps = false;
                //swap
                temp = list.get(i);
                list.set(i, list.get(i-1));
                list.set(i-1, temp);
            }
        }
    }
    auto stop = chrono::high_resolution_clock::now();//end timer
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start); //find difference can change second units
    execTime = duration.count();
}

unsigned long long bubblesort::getExecTime()
{
    return execTime;
}

unsigned long long bubblesort::getNumComparisons()
{
    return numComparisons;
}

unsigned long long bubblesort::getNumSwaps()
{
    return numSwaps;
}
#endif