// Viết chương trình cài đặt 1 bảng băm bằng pp kết nối trực tiếp
// Trong đó M={0,1,2,...,9} hàm băm h(key)=k%10
// và các chức năng sau:
// a. Thêm 1 phần tử vào bảng băm (có kiểm tra trùng)
// b. Tìm 1 pt trong bảng băm
// c. Xoá 1 pt ra khỏi bảng băm
#include <iostream>
#include <cstdlib>
#include <ctime>
typedef int item;
using namespace std;
struct Node
{
    item key;
    Node *next;
};
#define M 10
typedef Node *HashTable[10];
void Initialize(HashTable &H)
{
    for (int i = 0; i < M; i++)
    {
        H[i] = NULL;
    }
}
bool IsEmpty(HashTable &H, int i)
{
    return (H[i] == NULL);
}
Node *MakeNode(item k)
{
    Node *p = new Node;
    p->key = k;
    p->next = NULL;
    return p;
}
void InsLast(HashTable &H, int i, item key)
{
    Node *p = MakeNode(key);
    if (IsEmpty(H, i))
    {
        H[i] = p;
    }
    else
    {
        Node *Q = H[i];
        while (Q->next != NULL)
        {
            Q = Q->next;
        }
        Q->next = p;
    }
}
void Insert(HashTable &H, item h[])
{
    int k = 0;
    while (k < M)
    {
        int i;
        i = h[k] % 10;
        InsLast(H, i, h[k]);
        k++;
    }
}
void Xuat(HashTable &H)
{
    for (int i = 0; i < M; i++)
    {
        cout << i << ": ";
        Node *P = H[i];
        while (P != NULL)
        {
            if (P != NULL)
            {
                cout << P->key << " ";
            }
            P = P->next;
        }
        cout << endl;
    }
}
void Search(HashTable &H)
{
    cout << "Nhap key can tim: ";
    item tim;
    cin >> tim;
    int i = tim % 10;
    Node *P = H[i];
    while (P != NULL && P->key != tim)
    {
        P = P->next;
    }
    if (P == NULL)
    {
        cout << "Khong tim thay key can tim !" << endl;
    }
    else
    {
        cout << "Tim thay key! " << endl;
    }
}
void Remove(HashTable &H)
{
    cout << "Nhap key can xoa: ";
    item xoa, key;
    cin >> xoa;
    int i = xoa % 10;
    Node *P = H[i];
    if (P->key == xoa)
    {
        key = P->key;
        cout << "Da xoa key " << key << endl;
        H[i] = P->next;
    }
    else
    {
        while (P->next != NULL && P->next->key != xoa)
        {
            P = P->next;
        }
        if (P->next == NULL)
        {
            cout << "Khong tim thay key can xoa !" << endl;
        }
        else
        {
            Node *Q = P->next;
            key = Q->key;
            cout << "Da xoa key " << key << endl;
            P->next = Q->next;
        }
    }
}
int main()
{
    item h[M] = {26, 7, 9, 11, 16, 17, 12, 1, 31, 21};
    HashTable H;
    Initialize(H);
    Insert(H, h);
    int i = 0;
    while (i < 2)
    {
        Search(H);
        i++;
    }
    while (i < 9)
    {
        Remove(H);
        i++;
    }
    Xuat(H);
    return 0;
}