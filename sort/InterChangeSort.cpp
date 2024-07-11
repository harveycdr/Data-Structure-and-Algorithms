#include "mylist.h"

void InterChangeSort(mylist<int> &arr)
{
    for (int i = 0; i < arr.length() - 1; ++i)
    {
        for (int j = i + 1; j < arr.length(); ++j)
        {
            if (arr[j] < arr[i])
            {
                swap(arr[j], arr[i]);
            }
        }
    }
}