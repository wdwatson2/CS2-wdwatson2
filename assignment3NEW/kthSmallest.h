#ifndef KTHSMALLEST_H
#define KTHSMALLEST_H

using namespace std;

double kthSmallestElement(double list[], int low, int high, int k);
int partition(double list[], int low, int high);
void exchange(double list[], int indx1, int indx2);

void exchange(double list[], int indx1, int indx2)
{
    double temp = list[indx1];
    list[indx1] = list[indx2];
    list[indx2] = temp;
}

int partition(double list[], int low, int high)
{    
    double pivot = list[low];
 
    int count = 0;
    for (int i = low + 1; i <= high; i++) {
        if (list[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = low + count;
    exchange(list, pivotIndex, low);
 
    // Sorting left and right parts of the pivot element
    int i = low, j = high;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (list[i] <= pivot) {
            i++;
        }
 
        while (list[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            exchange(list, i++, j--);
        }
    }
 
    return pivotIndex;
}

double kthSmallestElement(double list[], int low, int high, int k)
{
    if(k>high)
        return -1;

    int p = partition(list, low, high);

    if(p == k-1)
        return list[p];
    if(p > k-1)
        return kthSmallestElement(list, low, p, k);
    else
        return kthSmallestElement(list, p+1, high, k);
}

#endif