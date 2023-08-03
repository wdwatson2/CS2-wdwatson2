/*
They actually seem to be performing about the same.
Your heap sort sorts the list sometimes quicker and sometimes slower than STL.
If anything, your sort executes faster most of the time.
The disparity between execution times could be revelead by making the lists larger probably.
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>

using namespace std;

// #define DEBUG

//Sherine's Heap Sort
void makeMeAHeap(vector<int> &list, int len, int x)
{
    int largest = x, left = 2 * x + 1, right = 2 * x + 2;
    if (left < len && list[left] > list[largest])
        largest = left;
    if (right < len && list[right] > list[largest])
        largest = right;
    if (largest != x)
    {
        iter_swap(list.begin()+x, list.begin()+largest);
        makeMeAHeap(list, len, largest);
    }
}
void heapSort(vector<int> &list, int len)
{
    for (int i = len / 2 - 1; i >= 0; i--)
        makeMeAHeap(list, len, i);
    for (int i = len - 1; i >= 0; i--)
    {
        iter_swap(list.begin(), list.begin()+i);
        makeMeAHeap(list, i, 0);
    }
}
void display(vector<int> &list, int len)
{
    cout << "After sorting, the array is: \n";
    for (int i = 0; i < len; ++i)
       cout << list[i] << " "<< endl;
}

int main()
{
    //writing results to an output file
    fstream fout;
    fout.open("HeapSort_Results.txt", ios::out);
    if(fout.fail())
            exit(1);

    //two vectors to sort
    vector<int> list1;
    vector<int> list2;

    //populating two identical vectors with 2000 random numbers inserted.
    long num;
    srand(9352); //seeding rand with last 4 of 700 number so its reproducible
    for(int i = 0; i < 2000; i++)
    {
        num = rand();
        list1.push_back(num);
        list2.push_back(num);
    }

    int len = 2000;
    fout << "SHERINES RESULTS\n" << "-------------------------------------------------------------------------\n";
    fout << "Before Sorted:\n";
    for(int i=1; i <= len; i++)
    {
        fout << list1[i-1] << '\t';
        if(i%5==0)
            fout << '\n';
    }

    auto start = chrono::high_resolution_clock::now(); //start timer

    heapSort(list1, len); //Sherine's Heap sort sorting list1

    auto stop = chrono::high_resolution_clock::now();//end timer
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start); //find difference 
    long executionTime = duration.count();

    fout << "After Sorted: " << '\n';
    for(int i=1; i <= len; i++)
    {
        fout << list1[i-1] << '\t';
        if(i%5==0)
            fout << '\n';
    }
    fout << "\n\n\nSherines Heap Sort: " << executionTime << " microseconds." <<"\n\n\n";


    fout << "STL RESULTS\n" << "-------------------------------------------------------------------------\n";
    fout << "Before Sorted:\n";
    for(int i=1; i <= len; i++)
    {
        fout << list2[i-1] << '\t';
        if(i%5==0)
            fout << '\n';
    }

    start = chrono::high_resolution_clock::now();

    make_heap(list2.begin(), list2.end());
    sort_heap(list2.begin(), list2.end());

    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop-start);
    executionTime = duration.count();

    fout << "After Sorted: " << '\n';
    for(int i=1; i <= len; i++)
    {
        fout << list1[i-1] << '\t';
        if(i%5==0)
            fout << '\n';
    }
    fout << "\n\n\nSTL Heap Sort: " << executionTime << " microseconds." <<"\n\n\n";


#ifdef DEBUG
    display(list1, len);

    for(int i=0; i < len; i++)
        cout << list2[i] << '\n';
#endif
}
