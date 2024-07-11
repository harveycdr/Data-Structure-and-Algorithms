#include "list.h"

void InsertionSort(list<int> &arr)
{
    int pos, i, x;
    for (i = 1; i < arr.length(); i++)
    {
        x = arr[i];
        pos = i - 1;
        while (pos >= 0 && arr[pos] > x)
        {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = x;
    }
}