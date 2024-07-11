// Bài tập về queue
// Xây dựng CTDL queue cài đặt bằng DSLK để mô phỏng qui trình cho thuê máy ở một phòng NET với các yêu cầu:
// - Danh sách các máy trống A – Dùng kiểu queue, mỗi nút chứa số máy;
// - Danh sách khách đang chờ nhận máy Q – Dùng kiểu queue, mỗi nút chứa họ tên người thuê.// - Danh sách khách đang thuê máy H - Dùng kiểu DSLK đơn, mỗi nút có họ tên khách, giờ bắt đầu thuê máy, số máy.
// Các chức năng cần phải có:
// - Đăng ký thuê máy: Còn máy trong A thì thêm khách vào H và lấy máy vừa cho thuê ra khỏi queue A. Nếu A trống thì thêm khách vào queue Q.
// - Trả máy: Thêm máy trả vào queue A, bỏ người đó khỏi danh sách thuê H.
// - Phục vụ: Kiểm tra A và Q để phục vụ và cập nhật lại A, Q, H.
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
using namespace std;
void Time_Now(int &gio, int &phut)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    gio = 1 + ltm->tm_hour;
    phut = 1 + ltm->tm_min;
}
struct Time
{
    int gio;
    int phut;
};
struct Thue_May
{
    char Ten_khach_thue[30];
    int So_May;
    Time tg_thue;
};
struct Node
{
    Thue_May data;
    Node *next;
};
typedef Node *H;
void InitH(H &h)
{
    h = NULL;
}
void Xuat(Thue_May data)
{

    cout << data.So_May << "\t" << data.Ten_khach_thue << "\t\t\t" << data.tg_thue.gio << ":" << data.tg_thue.phut << endl;
}
Node *MakeH(Thue_May data)
{
    Node *p = new Node;
    p->data = data;
    p->next = NULL;
    ;
    return p;
}
void InsertLast(H &h, Thue_May data)
{
    Node *P = MakeH(data);
    if (h == NULL)
    {
        h = P;
    }
    else
    {
        Node *Q = h;
        while (Q->next != NULL)
        {
            Q = Q->next;
        }
        Q->next = P;
    }
}
void PrintH(H &h)
{
    cout << "Thong tin cac may da duoc thue: " << endl;
    cout << "So may" << "\t" << "Ten khach hang" << "\t\t" << "Thoi gian bat dau thue" << endl;
    for (Node *p = h; p != NULL; p = p->next)
    {
        Xuat(p->data);
    }
}
// Danh sach may trong A
struct Node_A
{
    int So_May;
    Node_A *pA_next;
};
typedef Node_A *Queue_A;
void InitQueueA(Queue_A &A)
{
    A = NULL;
}
bool IsEmptyA(Queue_A A) { return (A == NULL); }
Node_A *MakeQueueA(int so)
{
    Node_A *p = new Node_A;
    p->pA_next = NULL;
    p->So_May = so;
    return p;
}
void Put_A(Queue_A &A, int so)
{
    Node_A *p = MakeQueueA(so);
    if (IsEmptyA(A))
    {
        A = p;
    }
    else
    {
        Node_A *Q = A;
        while (Q->pA_next != NULL)
        {
            Q = Q->pA_next;
        }
        Q->pA_next = p;
    }
}
int Get_A(Queue_A &A)
{
    if (IsEmptyA(A))
    {
        cout << "Het may tinh!" << endl;
        exit(1);
    }
    else
    {
        Node_A *p = A;
        int x;
        x = p->So_May;
        A = p->pA_next;
        return x;
    }
}
void Nhap_A(Queue_A &A)
{
    cout << "Nhap so luong may trong quan:";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Put_A(A, i + 1);
    }
}
// Danh sach khach dang cho doi Q
struct Node_Q
{
    char Ten_khach_thue[30];
    Node_Q *pQ_next;
};
typedef Node_Q *Queue_Q;
void InitQueueQ(Queue_Q &Q)
{
    Q = NULL;
}
bool IsEmptyQ(Queue_Q Q) { return (Q == NULL); }
Node_Q *MakeQueueQ(char *ten)
{
    Node_Q *p = new Node_Q;
    p->pQ_next = NULL;
    strcpy(p->Ten_khach_thue, ten);
    return p;
}
void Put_Q(Queue_Q &Q, char *ten)
{
    Node_Q *p = MakeQueueQ(ten);
    if (IsEmptyQ(Q))
    {
        Q = p;
    }
    else
    {
        Node_Q *P = Q;
        while (P->pQ_next != NULL)
        {
            P = P->pQ_next;
        }
        P->pQ_next = p;
    }
}
char *Get_Q(Queue_Q &Q)
{
    if (IsEmptyQ(Q))
    {
        cout << "Khong co khach doi!" << endl;
        exit(1);
    }
    else
    {
        Node_Q *p = Q;
        char *x = new char;
        strcpy(x, p->Ten_khach_thue);
        Q = p->pQ_next;
        return x;
    }
}
void PrintQ(Queue_Q Q)
{
    int kt = 0;
    cout << "Danh sach khach hang dang doi la:" << endl;
    while (Q != NULL)
    {
        kt = 1;
        cout << Q->Ten_khach_thue << endl;
        Q = Q->pQ_next;
    }
    if (kt == 0)
    {
        cout << "Khong co." << endl;
    }
}
void DK_Thue_May(H &h, Queue_Q &Q, Queue_A &A, char *ten_khach)
{
    if (IsEmptyA(A))
    {
        cout << "Tiem net da het may roi! " << endl;
        cout << "Co muon doi hay khong: 1.Co, 2.Khong. " << endl;
        ;
        int lua_chon;
        cin >> lua_chon;
        if (lua_chon == 1)
        {
            Put_Q(Q, ten_khach);
        }
    }
    else
    {
        Thue_May data;
        data.So_May = Get_A(A);
        strcpy(data.Ten_khach_thue, ten_khach);
        Time_Now(data.tg_thue.gio, data.tg_thue.phut);
        InsertLast(h, data);
    }
}
void Phuc_vu(H &h, Queue_Q &Q, Queue_A &A)
{
    if (!IsEmptyA(A) && !IsEmptyQ(Q))
    {
        DK_Thue_May(h, Q, A, Get_Q(Q));
    }
}
void Tra_May(H &h, Queue_Q &Q, Queue_A &A)
{
    cout << "Nhap so may khach muon tra:";
    int May_tra;
    cin >> May_tra;
    Node *P = h;
    Thue_May x;
    if (P->data.So_May == May_tra)
    {
        cout << "Khach tra may la:" << endl;
        x = P->data;
        Put_A(A, x.So_May);
        Xuat(x);
        h = P->next;
    }
    else
    {
        while (P->next != NULL && P->next->data.So_May != May_tra)
        {
            P = P->next;
        }
        if (P->next != NULL)
        {
            Node *Q = P->next;
            P->next = Q->next;
            x = Q->data;
            Put_A(A, x.So_May);
            cout << "Khach tra may la:" << endl;
            Xuat(x);
            delete Q;
        }
        else
        {
            cout << "Khong tim thay may co so nhu vay." << endl;
        }
    }
    Phuc_vu(h, Q, A);
}
int main()
{
    H h;
    Queue_A A;
    Queue_Q Q;
    InitH(h);
    InitQueueA(A);
    InitQueueQ(Q);
    Nhap_A(A);
    int kt_thue = 1;
    char ten_khach[30];
    while (kt_thue == 1)
    {
        cout << "Nhap ten khach hang:";
        fflush(stdin);
        cin.getline(ten_khach, 30);
        DK_Thue_May(h, Q, A, ten_khach);
        cout << "Co muon them khach hang khong: 1.Co 2. Khong. " << endl;
        ;
        cin >> kt_thue;
    }

    PrintH(h);
    PrintQ(Q);
    int kt_tra = 1;
    while (kt_tra == 1)
    {
        cout << "Tra may!" << endl;
        Tra_May(h, Q, A);
        PrintH(h);
        PrintQ(Q);
        cout << "Muon tra may khong: 1.Co, 2.Khong" << endl;
        cin >> kt_tra;
    }
    return 0;
}