#ifndef BUBBLESORT_H
#define BUBBLESORT_H

using namespace std;

long numSwapsBubbleSort = 0;
long numComparisonsBubbleSort = 0;

void swapBubbleSort(double list[], int index1, int index2)
{
    double temp = list[index1];
    list[index1] = list[index2];
    list[index2] = temp;
    numSwapsBubbleSort++;
}

bool comparisonBubbleSort(const double num1, const double num2)
{
    numComparisonsBubbleSort++;
    return (num1 < num2);
}

void bubbleSort(double list[], int size)
{
    bool noSwaps = false;
    while(!noSwaps)
    {
        noSwaps = true;
        for(int i = 1; i < size; i++)
        {
            if(comparisonBubbleSort(list[i], list[i-1]))
            {
                noSwaps = false;
                swapBubbleSort(list, i, i-1);
            }
        }
    }

}

#endif