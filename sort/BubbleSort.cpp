#include "mylist.h"

void BubbleSort(mylist<int> &arr)
{
    for (int i = 0; i < arr.length() - 1; ++i)
    {
        for (int j = arr.length() - 1; j > i; --j)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
}

void BubbleSort(int *&arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = size - 1; j > i; --j)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
}