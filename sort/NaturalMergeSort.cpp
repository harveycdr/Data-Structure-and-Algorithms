#include "mylist.h"

void NaturalMerge(mylist<int> &a, mylist<int> b, mylist<int> c)
{
    int i = 0, ib = 0, ic = 0;
    int endb = b.length()-1, endc = c.length()-1;
    while (ib <= endb && ic <= endc)
    {
        /*So sánh và lưu theo kiểu merge vào mảng a*/
        if (b[ib] > c[ic])
            a[i++] = c[ic++];
        else
            a[i++] = b[ib++];
    }
    while (ib <= endb)
    { /*Lưu toàn bộ phần tử còn lại vào mảng a (nếu b còn )*/
        a[i++] = b[ib++];
    }
    while (ic <= endc)
    { /*Lưu toàn bộ phần tử còn lại vào mảng a (nếu c còn )*/
        a[i++] = c[ic++];
    }
}
void NaturalMergeSort(mylist<int> &arr)
{
    int last = arr.length() - 1;
    int r = 1;/*Tạo đường chạy*/
    int i = 0, ib = 0, ic = 0; /*i sẽ chạy*/
    mylist<int> b, c;/* Tạo 2 mảng để lưu giá trị*/
    while (i <= last)
    {
        /*Nếu đường chạy là lẻ thì thêm vào mảng b*/
        if (r % 2 == 1){ b.append(arr[i]);}
        /*Nếu đường chạy không lẻ thì thêm vào mảng c*/
        else {c.append(arr[i]);}
        /*Nếu phần tử tiếp theo mảng a bé hơn thì r cộng thêm 1*/
        if (i + 1 <= last && arr[i] > arr[i + 1]) r++;
        i++;
    }
    NaturalMerge(arr, b, c); /*Lưu giá trị 2 mảng b,c theo trật tự vào mảng a*/
    b.~mylist();
    c.~mylist();
    if (r == 1){
        return;
    }
    NaturalMergeSort(arr);
    /*Kiểm tra đường chạy nếu lớn hơn 1 thì tiếp tục đệ qui*/
}

void NaturalMerge(int *&a, int sz_a, int b[], int endb, int c[], int endc)
{
    int i = 0, ib = 0, ic = 0;
    while (ib <= endb && ic <= endc)
    {
        /*So sánh và lưu theo kiểu merge vào mảng a*/
        if (b[ib] > c[ic])
            a[i++] = c[ic++];
        else
            a[i++] = b[ib++];
    }
    while (ib <= endb)
    { /*Lưu toàn bộ phần tử còn lại vào mảng a (nếu b còn )*/
        a[i++] = b[ib++];
    }
    while (ic <= endc)
    { /*Lưu toàn bộ phần tử còn lại vào mảng a (nếu c còn )*/
        a[i++] = c[ic++];
    }
}
void NaturalMergeSort(int *&a, int sz_a)
{
    int last = sz_a - 1;
    int r = 1;/*Tạo đường chạy*/
    do{
        r = 1;
        int i = 0, ib = 0, ic = 0; /*i sẽ chạy*/
        int b[sz_a], c[sz_a];/* Tạo 2 mảng để lưu giá trị*/
        while (i <= last)
        {
            /*Nếu đường chạy là lẻ thì thêm vào mảng b*/
            if (r % 2 == 1)
            {
                b[ib++] = a[i];
            }
            /*Nếu đường chạy không lẻ thì thêm vào mảng c*/
            else
            {
                c[ic++] = a[i];
            }
            /*Nếu phần tử tiếp theo mảng a bé hơn thì r cộng thêm 1*/
            if (i + 1 <= last && a[i] > a[i + 1]){
                r++;
            }
            i++;
        }
        if (r > 1)
            NaturalMerge(a, sz_a, b, ib-1, c, ic-1);
    }while (r > 1);
}