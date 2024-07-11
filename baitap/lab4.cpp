// Bài tập về danh sách liên kết
// Viết chương trình quản lý hàng hóa của cửa hàng sử dụng DSLK đơn, mỗi nút của nó gồm các thông tin về mã số, tên mặt hàng, giá bán, số lượng.
// - Nhập/xuất dữ liệu cho n mặt hàng.
// - Tìm thông tin của mặt hàng có giá bán đắt nhất.
// - Thay đổi số lượng của 1 mặt hàng nào đó dựa vào mã số mặt hàng.
// - Xóa 1 mặt hàng ra khỏi danh sách dựa vào tên.
// - Lưu vào file
// - Đọc từ file
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct HH
{
    char MaSo[10];
    char TenHang[20];
    float GiaBan;
    int SL;
};
typedef HH item;
struct Node
{
    item data;
    Node *pNext;
};
typedef Node *List;
void InitList(List &l)
{
    l = NULL;
}
Node *MakeNode(item x)
{
    Node *p = new Node;
    p->data = x;
    p->pNext = NULL;
    return p;
}
void InsLast(List &l, item x)
{
    Node *p = MakeNode(x);
    if (l == NULL)
    {
        l = p;
    }
    else
    {
        Node *Q = l;
        while (Q->pNext != NULL)
            Q = Q->pNext;
        Q->pNext = p;
    }
}
HH Nhap()
{
    item Hang_hoa;
    cout << "Nhap ma cua mat hang: ";
    fflush(stdin);
    cin.get(Hang_hoa.MaSo, 10);
    fflush(stdin);
    cout << "Nhap ten cua mat hang: ";
    cin.getline(Hang_hoa.TenHang, 20);
    cout << "Nhap gia ban cua mat hang: ";
    cin >> Hang_hoa.GiaBan;
    cout << "Nhap so luong mat hang: ";
    cin >> Hang_hoa.SL;
    return Hang_hoa;
}
void Xuat(item x)
{
    cout << x.MaSo << "\t" << x.TenHang << "\t\t" << x.GiaBan << "\t\t" << x.SL << endl;
}
void CreateList(List &l)
{
    item Hang_hoa;
    int n;
    cout << "Nhap so luong mat hang muon them: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        item x = Nhap();
        InsLast(l, x);
    }
}
void PrintList(List &l)
{
    cout << "Ma hang\tTen Hang\t\tDon gia\tSo luong." << endl;
    for (Node *p = l; p != NULL; p = p->pNext)
    {
        Xuat(p->data);
    }
}
void TimGiaLonNhat(List &l)
{
    float Max = 0;
    for (Node *p = l; p != NULL; p = p->pNext)
    {
        if (p->data.GiaBan > Max)
        {
            Max = p->data.GiaBan;
        }
    }
    Node *Q = l;
    while (Q->data.GiaBan != Max)
    {
        Q = Q->pNext;
    }
    cout << "Mat hang co gia ban lon nhat la." << endl;
    Xuat(Q->data);
}
void ThayDoiSL(List &l)
{
    char MaSua[10];
    cout << "Nhap ma ban muon sua doi so luong: ";
    fflush(stdin);
    cin.get(MaSua, 10);
    Node *p = l;
    while (p != NULL && strcmp(p->data.MaSo, MaSua) != 0)
    {
        p = p->pNext;
    }
    if (p != NULL)
    {
        int SuaSL;
        cout << "So luong cu cua ma hang la " << p->data.SL << endl;
        cout << "Nhap so luong moi: ";
        cin >> SuaSL;
        p->data.SL = SuaSL;
    }
    else
    {
        cout << "Khong tim thay ma can sua." << endl;
    }
}
void XoaBangTen(List &l)
{
    char TenSua[20];
    cout << "Nhap ten ban muon xoa: ";
    fflush(stdin);
    cin.getline(TenSua, 20);
    item x;
    Node *p = l;
    if (strcmp(p->data.TenHang, TenSua) == 0)
    {
        x = p->data; // lay data ra de xuat neu can
        l = p->pNext;
    }
    else
    {
        while (p->pNext != NULL && strcmp(p->pNext->data.TenHang, TenSua) != 0)
        {
            p = p->pNext;
        }
        if (p->pNext != NULL)
        {
            Node *Q = p->pNext;
            p->pNext = Q->pNext;
            x = Q->data;
            delete Q;
        }
        else
        {
            cout << "Khong tim thay ten hang can sua." << endl;
        }
    }
}
void LuuListFile(List &l)
{
    fstream fo("mahang.dat", ios::out);
    if (!fo)
    {
        cout << "Khong mo duoc file!" << endl;
        exit(1);
    }
    else
    {

        for (Node *p = l; p != NULL; p = p->pNext)
        {
            fo << p->data.MaSo << ";" << p->data.TenHang << ";" << p->data.GiaBan << ";" << p -
                > data.SL << ";" << endl;
            ;
        }
    }
    fo.close();
}
// Doc du lieu tu file va luu vao Danh sach lien ket
void DocListFile(List &l)
{
    ifstream fi("mahang.dat", ios::binary | ios::app);
    if (!fi)
    {
        cout << "File rong!" << endl;
        exit(1);
    }
    else
    {
        List list;
        InitList(list);
        item x;
        while (fi.getline(x.MaSo, 10, ';') && x.MaSo != "")
        {
            char endline[10];
            fi.getline(x.TenHang, 20, ';');
            fi >> x.GiaBan;
            fi.getline(endline, 10, ';');
            fi >> x.SL;
            fi.getline(endline, 10, ';');
            fi.getline(endline, 10);
            InsLast(list, x);
        }
        l = list;
    }
    fi.close();
}
int main()
{
    List list;
    InitList(list);
    // CreateList(list);
    // LuuListFile(list);
    DocListFile(list);
    // ThayDoiSL(list);
    // LuuListFile(list);
    PrintList(list);
    XoaBangTen(list);
    PrintList(list);
    // TimGiaLonNhat(list);
}
// g++ .\CTDLvaGTbt4.cpp -o hi.exe