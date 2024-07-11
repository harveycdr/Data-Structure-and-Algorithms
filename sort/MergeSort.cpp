#include "mylist.h"

// void merge(mylist<int> &arr, int start, int mid, int end)
// {
//     mylist<int> a;
//     int start1 = start;
//     int end1 = mid;
//     int start2 = mid + 1;
//     int end2 = end;
//     while ((start1 <= end1) && (start2 <= end2))
//     {
//         if (arr[start1] < arr[start2])
//         {
//             a.append(arr[start1]);
//             ++start1;
//         }
//         else
//         {
//             a.append(arr[start2]);
//             ++start2;
//         }
//     }
//     while (start1 <= end1){
//         a.append(arr[start1]);
//         ++start1;
//     }
//     while (start2 <= end2){
//         a.append(arr[start2]);
//         ++start2;
//     }
//     int j = start;
//     for (int i=0; i < a.length();++i){
//         arr[j++] = a[i];
//     }
// }

// void MergeSortAlgo(mylist<int> &arr, int start, int end)
// {
//     if (start < end)
//     {
//         int mid = int((start + end) / 2);
//         MergeSortAlgo(arr, start, mid);
//         MergeSortAlgo(arr, mid + 1, end);
//         merge(arr, start, mid, end);
//     }
// }

// void MergeSort(mylist<int> &arr)
// {
//     int start = 0;
//     int end = arr.length() - 1;
//     MergeSortAlgo(arr, start, end);
// }

void merge(int *&arr, int start, int mid, int end)
{
    int a[end - start + 1], i=0;
    int start1 = start;
    int end1 = mid;
    int start2 = mid + 1;
    int end2 = end;
    while ((start1 <= end1) && (start2 <= end2))
    {
        if (arr[start1] < arr[start2])
            a[i++] = arr[start1++];
        else
            a[i++] = arr[start2++];
    }
    while (start1 <= end1) a[i++] = arr[start1++];
    while (start2 <= end2) a[i++] = arr[start2++];

    int j = start;
    for (int k = 0; k < i; ++k)
    {
        arr[j++] = a[k];
    }
}

void MergeSortAlgo(int *&arr, int start, int end)
{
    if (start < end)
    {
        int mid = int((start + end) / 2);
        MergeSortAlgo(arr, start, mid);
        MergeSortAlgo(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void MergeSort(int *&arr, int size)
{
    int start = 0;
    MergeSortAlgo(arr, start, size - 1);
}