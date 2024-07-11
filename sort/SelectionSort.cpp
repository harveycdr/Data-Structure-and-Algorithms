#include "mylist.h"

void SelectionSort(mylist<int> &arr)
{
    int min; // Lưu vị trí phần tử nhỏ nhất
    for (int i = 0; i < arr.length() - 1; ++i)
    {
        min = i;
        for (int j = i + 1; j < arr.length(); ++j)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}