#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
// Bai 1 sắp xếp mảng chuỗi kí tự
void input(char chuoi[])
{ /* Nhập vào một chuỗi ký tự*/
    fflush(stdin);
    cin.getline(chuoi, 30);
}
void output(char a[])
{ /*Xuất một chuỗi ký tự*/
    cout << a << endl;
}
void ArrChar(int n, char a[][30])
{ /*Nhập vào mảng chuỗi ký tự*/
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap chuoi thu " << i + 1 << ": ";
        input(a[i]);
    }
}
void Printlist(int n, char a[][30])
{ /*Xuất ra mảng chuỗi ký tự*/
    for (int i = 0; i < n; i++)
    {
        output(a[i]);
    }
}
void Sapxep(int n, char a[][30])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(a[i], a[j]) > 0)
            { /*thực hiện so sánh 2 chuỗi và hoán đổi*/
                char temp[30];
                strcpy(temp, a[j]);
                strcpy(a[j], a[i]);
                strcpy(a[i], temp);
            }
        }
    }
}
int main()
{
    int n;
    cout << "Nhap so luong mang ";
    cin >> n; /*Nhập vào số lượng phần tử trong mảng*/
    char a[n][30];
    ArrChar(n, a);
    Sapxep(n, a);
    Printlist(n, a);
    return 0;
}
// Bài 2
struct Person
{
    char Ho[30];
    char Ten[20];
};
Person input()
{ /*Nhap vao ho va ten mot nguoi*/
    Person a;
    cout << "\nNhap ho :";
    cin.ignore();
    cin.getline(a.Ho, 30);
    cout << "Nhap ten:";
    cin >> a.Ten;
    return a;
}
void output(Person a)
{ /*Xuat ra ho va ten mot nguoi*/
    cout << a.Ho << " " << a.Ten << endl;
}
void ListPerson(int n, Person a[])
{ /*Nhap list nguoi theo danh sach*/
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap nguoi thu " << i + 1;
        a[i] = input(); /*Nhap 1 nguoi*/
    }
}
void Printlist(int n, Person a[])
{ /*Xuat danh sach nguoi*/
    for (int i = 0; i < n; i++)
    {
        output(a[i]); /*Xuat 1 nguoi*/
    }
}
void Sapxep(int n, Person a[])
{ /*Ham sap xep theo ten*/
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            if (strcmp(a[i].Ten, a[j].Ten) > 0 || strcmp(a[i].Ho, a[j].Ho) > 0 && strcmp(a[i].Ten, a[j].Ten) == 0)
            { /*kiem tra va sap xep theo ten*/
                Person temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
int main()
{
    int n;
    cout << "Nhap so luong phan tu trong mang: ";
    cin >> n; /*Nhap so luong mang*/
    Person a[n];
    ListPerson(n, a);
    Sapxep(n, a);
    Printlist(n, a);
    return 0;
}
// Bai 3
// mở file và lưu mảng int vào file nguồn
void Write()
{
    int input;
    fstream fo("file_nguon", ios::app | ios::out | ios::binary);
    if (!fo)
    {
        cout << "Khong the tao duoc file";
        exit(1);
    }
    else
    {
        cout << "Nhap chu cai de ket thuc !" << endl;
        /*Dừng nhập file khi nhập chữ*/
        while (cin >> input)
        { /*Nhập vào file dữ liệu kiểu int*/
            fo << input << " ";
        }
    }

    fo.close();
}
// ham interchange sort
void InterchangeSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
}
// In mảng a ra màn hình
void Print(int a[], int n)
{
    cout << "mang trong file nguon sau khi sap sep la: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
// đọc từ file nguồn sắp xếp và lưu vào file đích
void ReadSave(int a[], int &n)
{
    fstream file_dich("file_dich", ios::out | ios::binary);
    fstream fi("file_nguon", ios::in | ios::binary);
    if (!fi || !file_dich)
    {
        cout << "Khong the mo duoc file";
        exit(1);
    }
    else
    {
        while (fi >> a[n])
            n++;
        InterchangeSort(a, n); // Sap xep bang pp interchangeSort
        for (int i = 0; i < n; i++)
        {
            file_dich << a[i] << " "; /*Ghi vào file đích*/
        }
    }
    fi.close();
    file_dich.close();
}
int main()
{
    int n = 0;
    int a[100];
    Write();
    ReadSave(a, n);
    Print(a, n);
    return 0;
}
/*Hàm random ra mảng a (từ 0-99) và số lượng phần tử n do người dùng nhập */
void RndmArr(int a[], int n)
{
    int const l = 0, r = 99;
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        a[i] = l + rand() % (r - l + 1);
    }
}
// Bai 4 Natural Merge Sort
void Naturalmerge(int a[], int b[], int lastb, int c[], int lastc, int last)
{
    int i = 0, ib = 0, ic = 0;
    while (ib <= lastb && ic <= lastc)
    { /*So sánh và lưu theo kiểu meger vào mảng a*/
        if (b[ib] > c[ic])
        {
            a[i++] = c[ic++];
        }
        else
        {
            a[i++] = b[ib++];
        }
    }
    while (ib <= lastb)
    { /*Lưu toàn bộ phần tử còn lại vào mảng a (nếu b còn )*/
        a[i++] = b[ib++];
    }

    while (ic <= lastc)
    { /*Lưu toàn bộ phần tử còn lại vào mảng a (nếu c còn )*/
        a[i++] = c[ic++];
    }
}
void NaturalmergeSort(int a[], int last)
{
    int r = 1;                 /*Tạo đường chạy*/
    int i = 0, ib = 0, ic = 0; /*i sẽ chạy*/
    int b[last], c[last];      /* Tạo 2 mảng để lưu giá trị*/
    while (i < last)
    {
        if (r % 2 == 1)
        {
            b[ib++] = a[i];
        } /*Nếu đường chạy là lẻ thì thêm vào mảng b*/
        else
        {
            c[ic++] = a[i];
        } /*Nếu đường chạy không lẻ thì thêm vào mảng c*/
        if (i != last - 1 && a[i] > a[i + 1])
        {
            r++;
        } /*Nếu phần tử tiếp theo mảng a bé hơn thì r cộng thêm 1*/
        i++;
    }
    Naturalmerge(a, b, ib - 1, c, ic - 1, last); /*Lưu giá trị 2 mảng b,c theo trật tự vào mảng a*/ /*Kiểm tra đường chạy nếu lớn hơn 1 thì tiếp tục đệ qui*/
    if (r > 1)
    {
        NaturalmergeSort(a, last);
    }
}
int main()
{
    int n;
    cout << "Nhap so luong mang: ";
    cin >> n;
    int a[n];
    RndmArr(a, n); /*Tạo mảng a random với số lượng phần tử n*/
    NaturalmergeSort(a, n);
    cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "]";
    return 0;
}
// Bài 5
// Luu mang a vao File co ten do nguoi dung nhap
void Write(char FName[])
{
    int n;
    cout << "Nhap so luong phan tu trong mang (khong qua 100): ";
    cin >> n;
    int a[n];
    RndmArr(a, n);
    fstream fo(FName, ios::out | ios::binary);
    if (!fo)
    {
        cout << "Khong the tao duoc file";
        exit(1);
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            fo << a[i] << " ";
        }
    }

    fo.close();
}
void Print(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
void MergeSortFile(char FName[])
{
    fstream f(FName, ios::in | ios::binary);
    int c, n = 0;
    if (!f)
    {
        cout << "Khong the mo duoc file";
        exit(1);
    }
    else
    {
        int a[100];
        while (f >> c)
        { /*Đọc dữ liệu kiểu int từ file và lưu vào mảng a*/
            a[n] = c;
            n++;
        }
        NaturalmergeSort(a, n);
        Print(n, a);                               /*In mảng a sau khi sắp xếp*/
        fstream fo(FName, ios::out | ios::binary); /*Luu mang a sau khi sap xep vao file*/
        for (int i = 0; i < n; i++)
        {
            fo << a[i] << " ";
        }
        f.close();
    }
    f.close();
}
int main()
{
    char FName[30];
    cout << "Nhap ten file: ";
    cin.get(FName, 30);
    Write(FName);         /*tao mang a luu vao file*/
    MergeSortFile(FName); /*Mở file có sẳn hoặc file một nhập từ hàm Write()*/
    return 0;
}