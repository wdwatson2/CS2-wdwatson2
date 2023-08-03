#include <iostream>

using namespace std;


int summ(int nums[], int size)
{
    if(size == 0)
        return 0;
    else
        return nums[size-1] + summ(nums, size-1);
}

int main()
{
    int nums[] = {1,2,3,4,5};

    cout << summ(nums, 5) << endl;


    return 0;
}