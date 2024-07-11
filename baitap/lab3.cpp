// Bài tập về danh sách liên kết
// Viết chương trình gồm các hàm sau:
// - Tạo và nhập tự động các số ngẫu nhiên tử 1-99 vào 1 sách liên kết cài bằng con trỏ// - Sử dụng giải thuật sắp xếp để sắp xếp sao cho thứ tự tăng dần
// - Chèn thêm một phần tử (nhập từ bàn phím) vào d/s sao cho giữ nguyên thứ tự.
// - Loại bỏ các pt trùng nhau (giữ lại duy nhất 1 pt) trong danh sách
// - Lưu d/s vào file
// - Đọc d/s từ file
#include <iostream>
#include <fstream>
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
void PrintList(List &list)
{
    cout << "[ ";
    for (Node *P = list; P != NULL; P = P->next)
    {
        cout << P->data << " ";
    }
    cout << "]" << endl;
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
void merge(List &la, List &lb, List &lc)
{
    Node *pA = la, *pB = lb, *pC = lc;
    while (pB != NULL && pC != NULL)
    {
        if (pB->data > pC->data)
        {
            pA->data = pC->data;
            pA = pA->next;
            pC = pC->next;
        }
        else
        {
            pA->data = pB->data;
            pA = pA->next;
            pB = pB->next;
        }
    }
    while (pB != NULL)
    {
        pA->data = pB->data;
        pA = pA->next;
        pB = pB->next;
        ;
    }
    while (pC != NULL)
    {
        pA->data = pC->data;
        pA = pA->next;
        pC = pC->next;
    }
    delete pB, pC;
}
// Ham Natural Merge Sort danh sach lien ket
void NaturalmergeSort(List &la)
{
    int r = 1; /*Tạo đường chạy*/
    List lb, lc;
    InitList(lb);
    InitList(lc);
    for (Node *P = la; P != NULL; P = P->next)
    {
        if (r % 2 == 1)
        {
            InsertLast(lb, P->data);
        }
        else
        {
            InsertLast(lc, P->data);
        }
        if (P->next != NULL && (P->data) > (P->next->data))
        {
            r++;
        }
    }
    merge(la, lb, lc);
    if (r > 1)
    {
        NaturalmergeSort(la);
    }
}
/*Nhap them phan tu vao danh sach giu nguyen thu tu*/
void ChenThemGiuViTri(List &list)
{
    item them;
    cout << "Hay nhap so muon them vao danh sach: ";
    cin >> them;
    Node *P = list;
    Node *Ins = MakeNode(them);
    if (Ins->data < P->data)
    { /*insert vao dau danh sach*/
        Ins->next = P;
        list = Ins;
    }
    else
    {
        while (P->next != NULL && (Ins->data) > (P->next->data))
        {
            P = P->next;
        }
        if (P->next == NULL)
        {
            P->next = Ins;
        }
        else
        {
            Ins->next = P->next;
            P->next = Ins;
        }
    }
}
void DeletePos(List &list, int &pos)
{
    int i = 1;
    Node *P = list;
    if (pos == 1)
    {
        item x = P->data;
        list = P->next;
    }
    else
    {
        while (i != pos - 1)
        {
            i++;
            P = P->next;
        }
        Node *Q = P->next;
        P->next = Q->next;
        item x = Q->data; // lay phan tu de in ra neu can
        delete Q;
    }
}
void XoaPtTrung(List &list)
{
    bool kt = false;

    while (kt == false)
    {
        kt = true;
        Node *P = list;
        for (int pos = 1; P != NULL; pos++)
        {
            if (P->next != NULL && ((P->data) == (P->next->data)))
            {
                DeletePos(list, pos);
                kt = false;
                break;
            }
            P = P->next;
        }
    }
}
void LuuListFile(char *file_name, List list)
{
    fstream fo(file_name, ios::out | ios::app);
    if (!fo)
    {
        cout << "Khong mo duoc file!" << endl;
        exit(1);
    }
    else
    {
        Node *P = list;
        while (P != NULL)
        {
            fo << P->data << " ";
            P = P->next;
        }
    }
    fo.close();
}
// Doc du lieu tu file va luu vao Danh sach lien ket
void DocListFile(char *file_name, List &list)
{
    ifstream fi(file_name, ios::binary);
    if (!fi)
    {
        cout << "File rong!" << endl;
        exit(1);
    }
    else
    {
        List l;
        InitList(l);
        item so;
        while (fi >> so)
        {
            InsertLast(l, so);
        }
        list = l;
    }
    fi.close();
}
int main()
{
    char file_name[20];
    cout << "Nhap ten file: ";
    cin.getline(file_name, 20);
    List list;
    InitList(list);
    CreateList(list);
    PrintList(list);
    NaturalmergeSort(list);
    cout << "Danh sach sao khi sap xep la: " << endl;
    PrintList(list);
    // ChenThemGiuViTri(list);
    // cout<<"Danh sach sao khi chen them la"<<endl;
    // PrintList(list);
    XoaPtTrung(list);
    cout << "danh sach sao khi xoa phan tu trung la: " << endl;
    PrintList(list);
    LuuListFile(file_name, list);
    DocListFile(file_name, list);
    PrintList(list);
    return 0;
}