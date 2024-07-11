#include "list.h"

void QuickSortRun(int *&arr, int left, int right)
{
    // printf("%d, %d\n", left, right);
    int i, j, x;
    x = arr[(left + right) / 2];
    i = left;
    j = right;
    do
    {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } while (i < j);
    if (left < j)
        QuickSortRun(arr, left, j);
    if (i < right)
        QuickSortRun(arr, i, right);
}

void QuickSort(int *&arr, int size)
{
    int left = 0;
    int right = size - 1;
    QuickSortRun(arr, left, right);
}

void QuickSortRun(list<int> &arr, int left, int right)
{
    // printf("%d, %d\n", left, right);
    int i, j, x;
    x = arr[(left + right) / 2];
    i = left;
    j = right;
    do
    {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } while (i < j);
    if (left < j)
        QuickSortRun(arr, left, j);
    if (i < right)
        QuickSortRun(arr, i, right);
}

void QuickSort(list<int> &array)
{
    int left = 0; //chạy từ trái sang phải
    int right = array.length() - 1; //chạy từ phải sang trái
    QuickSortRun(array, left, right);
}