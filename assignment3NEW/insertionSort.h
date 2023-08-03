#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

using namespace std;

long numSwapsInsertionSort = 0;
long numComparisonsInsertionSort = 0;

void swapInsertionSort(double list[], int index1, int index2)
{
    double temp = list[index1];
    list[index1] = list[index2];
    list[index2] = temp;
    numSwapsInsertionSort++;
}

bool comparisonInsertionSort(const double num1, const double num2)
{
    numComparisonsInsertionSort++;
    return (num1 > num2);
}

void insertionSort(double list[], int low, int high)
{
    for(int i = low + 1; i < high+1; i++)
    {
        int j = i;
        while(j > 0 && comparisonInsertionSort(list[j-1], list[j]))
        {
            swapInsertionSort(list, j-1, j);
            j--;
        }
    }
}

#endif