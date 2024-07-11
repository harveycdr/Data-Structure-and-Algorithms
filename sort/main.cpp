#include "list.h"
// #include "InterChangeSort.cpp"
// #include "SelectionSort.cpp"
#include "InsertionSort.cpp"
// #include "BubbleSort.cpp"
#include "QuickSort.cpp"
// #include "MergeSort.cpp"
// #include "NaturalMergeSort.cpp"
#include <iostream>
#include <ctime>

// Hàm tạo mylist ngẫu nhiên
list<int> randListTnt(int len)
{
    srand(time(NULL));
    list<int> arr;
    for (int i = 0; i < len; ++i)
    {
        int numRandom = rand() % (len * 2) + 1;
        arr.append(numRandom);
    }
    return arr;
}

int main()
{
    std::clock_t start1 = std::clock();
    list<int> ls1 = randListTnt(50000);
    InsertionSort(ls1);
    std::clock_t end1 = std::clock() - start1;

    std::clock_t start2 = std::clock();
    list<int> ls2 = randListTnt(200000);
    QuickSort(ls2);
    std::clock_t end2 = std::clock() - start2;

    printf("insertion sort time: %0.3f\n", (float)(end1));
    printf("quick sort time: %0.3f\n", (float)(end2));
    
    return 0;
}
