// Bài tập về stack
// Cài đặt 1 stack bằng con trỏ, ứng dụng stack để
// a. Đảo ngược 1 danh sách liên kết
// b. Đổi từ thập phân sang các hệ khác.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef int item;
struct Node
{
    item data;
    Node *next;
};
typedef Node *List;
void Rndm(int a[], int n)
{
    int const l = 0, r = 99;
    srand(time(0));
    for (int i = 0; i < n; i++)
        a[i] = (l + rand() % (r - l + 1));
}
void InitList(List &list)
{
    list = NULL;
}
Node *MakeNode(item x)
{
    Node *P = new Node;
    P->next = NULL;
    P->data = x;
    return P;
}
void InsertLast(List &list, item x)
{
    Node *P = MakeNode(x);
    if (list == NULL)
    {
        list = P;
    }
    else
    {
        Node *Q = list;
        while (Q->next != NULL)
        {
            Q = Q->next;
        }
        Q->next = P;
    }
}
void CreateList(List &list)
{
    int n;
    cout << "Nhap so luong cua mang: ";
    cin >> n;
    int a[n];
    Rndm(a, n);
    for (int i = 0; i < n; i++)
    {
        InsertLast(list, a[i]);
    }
}
void PrintList(List &list)
{
    cout << "[ ";
    for (Node *P = list; P != NULL; P = P->next)
    {
        cout << P->data << " ";
    }
    cout << "]" << endl;
}
// Ung dung Stack de
typedef Node *Stack;
void InitStack(Stack &s)
{
    s = NULL;
}
bool IsEmpty(Stack s)
{
    return (s == NULL);
}
void Push(Stack &s, item data)
{
    Node *p = MakeNode(data);
    if (IsEmpty(s))
    {
        s = p;
    }
    else
    {
        p->next = s;
        s = p;
    }
}
item Pop(Stack &s)
{
    if (IsEmpty(s))
    {
        cout << "Stack rong" << endl;
        exit(1);
    }
    else
    {
        Node *p = s;
        item x = p->data;
        s = p->next;
        delete (p);
        return x;
    }
}
// Dao nguoc DSLK bang cah su dung Stack
void DaoNguocDSLK(List &l)
{
    Stack s;
    InitStack(s);
    // Dua DSLK p vao stack
    for (Node *P = l; P != NULL; P = P->next)
    {
        Push(s, P->data);
    }
    // Lay DSLK ra theo thu tu dao nguoc
    for (Node *P = l; P != NULL; P = P->next)
    {
        P->data = Pop(s);
    }
}
// Su dung Stack de doi so thap phan sang he khac
char Doi(int SoDoi)
{
    char So[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    return So[SoDoi];
}
void DoiSoTP(item SoCanDoi, int HeSo) // Heso la 2,8,10,16
{
    item n = SoCanDoi;
    Stack s;
    InitStack(s);
    while (n != 0)
    {
        Push(s, n % HeSo);
        n = n / HeSo;
    }
    cout << SoCanDoi << " = ";
    while (s != NULL)
    {
        int so = Pop(s);
        cout << Doi(so);
    }
    cout << endl;
}
int main()
{
    List l;
    InitList(l);
    CreateList(l);
    PrintList(l);
    DaoNguocDSLK(l);
    PrintList(l);
    DoiSoTP(54, 2);
}