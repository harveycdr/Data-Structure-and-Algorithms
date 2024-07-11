#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#define size 100
struct SV
{
    char maSV[10];
    char ho[20];
    char ten[10];
    int diemTB;
};
SV Nhap() // Ham nhap sinh vien vao file SV.dat
{
    SV sinhvien;
    cout << "Nhap ma Sinh vien: ";
    fflush(stdin);
    cin.getline(sinhvien.maSV, 10);
    cout << "Nhap ho cua sinh vien: ";
    fflush(stdin);
    cin.getline(sinhvien.ho, 20);
    cout << "Nhap ten sinh vien: ";
    cin.getline(sinhvien.ten, 10);
    cout << "Nhap diem trung binh cua sinh vien: ";
    cin >> sinhvien.diemTB;
    return sinhvien;
}
void Xuat(SV &sinhvien) // ham xuat tung sinh vien ra man hinh
{
    cout << sinhvien.maSV << "\t" << sinhvien.ho << "\t" << sinhvien.ten << "\t" << sinhvien.diemTB << endl;
}
void NhapListSV() // Nhap them sinh vien vao file SV.dat
{
    int soluong;
    cout << "Nhap so luong sinh vien muon them vao file SV.dat:";
    cin >> soluong;
    fstream fo("SV.dat", ios::app | ios::out | ios::binary);
    for (int i = 0; i < soluong; i++)
    {
        SV a;
        a = Nhap();
        fo << a.maSV << endl;
        fo << a.ho << endl;
        fo << a.ten << endl;
        fo << a.diemTB << endl;
    }
    fo.close();
}
void DocListSV(SV a[], int &i) // doc ra mang sinh vien tu file SV.dat
{
    ifstream fi("SV.dat", ios::binary);
    if (!fi)
    {
        cout << "Khong mo duoc file SV.dat" << endl;
        exit(1);
    }
    else
    {
        while (fi) // luu sinh vien vao mang
        {
            string endline;
            fi.getline(a[i].maSV, 10);
            fi.getline(a[i].ho, 20);
            fi.getline(a[i].ten, 10);
            fi >> a[i].diemTB;
            getline(fi, endline);
            i++;
        }
        i--;
    }
    fi.close();
}
void XuatListSV(SV sinhvien[], int count) // ham xuat danh sach sinh vien ra man hinh{
    cout
    << "Ma SV:\tHo \t\tTen \tDiem" << endl;
for (int i = 0; i < count; i++)
{
    Xuat(sinhvien[i]);
    cout;
}
}
void INDEX() // xuat danh sach sinh vien theo dieu kien bai so 2
{
    SV a[size];
    int count = 0;
    DocListSV(a, count);
    int chuc_nang = 0;
    while (chuc_nang != 4)
    {
        cout << "Chuc nang sap xep:" << endl;
        cout << "\t1. Sap xep theo ma sinh vien." << endl;
        cout << "\t2. Sap xep theo ten sinh vien." << endl;
        cout << "\t3. Sap xep theo diem." << endl;
        cout << "\t4. Thoat muc sap xep." << endl;
        cin >> chuc_nang;
        system("cls");
        if (chuc_nang == 1) // Sap xep theo ma sinh vien
        {
            cout << "==============================================" << endl;
            for (int i = 0; i < count - 1; i++)
                for (int j = i; j < count; j++)
                    if (strcmp(a[i].maSV, a[j].maSV) > 0)
                    {
                        SV temp = a[i];
                        a[i] = a[j];
                        a[j] = temp;
                    }
            XuatListSV(a, count);
            cout << "==============================================" << endl;
        }
        if (chuc_nang == 2) // Sap xep theo ten sinh vien
        {
            cout << "==============================================" << endl;
            for (int i = 0; i < count - 1; i++)
                for (int j = i; j < count; j++)

                    if (strcmp(a[i].ten, a[j].ten) > 0 || strcmp(a[i].ho, a[j].ho) > 0 && strcmp(a[i].ten, a[j].ten) == 0)
                    {
                        SV temp = a[i];
                        a[i] = a[j];
                        a[j] = temp;
                    }
            XuatListSV(a, count);
            cout << "==============================================" << endl;
        }
        if (chuc_nang == 3) // Sap xep theo diemTB
        {
            cout << "==============================================" << endl;
            for (int i = 0; i < count - 1; i++)
                for (int j = i; j < count; j++)
                    if (a[i].diemTB > a[j].diemTB)
                    {
                        SV temp = a[i];
                        a[i] = a[j];
                        a[j] = temp;
                    }
            XuatListSV(a, count);
            cout << "==============================================" << endl;
        }
    }
}
void XoaSinhVien()
{
    char MaSVcanXoa[10];
    cout << "Nhap ma sinh vien can xoa: ";
    fflush(stdin);
    cin.getline(MaSVcanXoa, 10);
    SV a[size];
    int count = 0;
    bool xoa = false;
    DocListSV(a, count);
    fstream fo("SV.dat", ios::out | ios::binary); // mo file de write vao (Khong co ios::app) for(int i=0; i<count; i++)
    {
        if (strcmp(a[i].maSV, MaSVcanXoa) == 0)
        {
            xoa = true;
        }
        else
        {
            fo << a[i].maSV << endl;
            fo << a[i].ho << endl;
            fo << a[i].ten << endl;
            fo << a[i].diemTB << endl;
        }
    }
    if (xoa == true)
    {
        cout << "Xoa du lieu thanh cong !" << endl;
    }
    else
    {
        cout << "Khong co Ma sinh vien can xoa" << endl;
    }
    fo.close();
}
void SuaSinhVien()
{
    char MaSVcanSua[10];
    cout << "Nhap ma sinh vien can sua: ";
    fflush(stdin);
    cin.getline(MaSVcanSua, 10);
    SV a[size];
    int count = 0;
    bool sua = false;
    DocListSV(a, count);
    fstream fo("SV.dat", ios::out | ios::binary); // mo file de write vao (Khong co ios::app) for(int i=0; i<count; i++)
    {
        if (strcmp(a[i].maSV, MaSVcanSua) == 0)
        {
            cout << "Du lieu cu cua sinh vien." << endl;
            Xuat(a[i]);
            cout << "Nhap du lieu moi cho sinh vien." << endl;
            a[i] = Nhap();
            sua = true;
        }
        fo << a[i].maSV << endl;
        fo << a[i].ho << endl;
        fo << a[i].ten << endl;
        fo << a[i].diemTB << endl;
    }
    if (sua == true)
    {
        cout << "Sua thong tin thanh cong !" << endl;
    }
    else
    {
        cout << "Khong tim thay ma sinh vien can sua." << endl;
    }
    fo.close();
}
void TimSinhVien()
{
    char MaSVcanTim[10];
    cout << "Nhap ma sinh vien can tim: ";
    fflush(stdin);
    cin.getline(MaSVcanTim, 10);
    SV a[size];
    int count = 0;
    bool Tim = false;
    DocListSV(a, count);
    for (int i = 0; i < count; i++)
    {
        if (strcmp(a[i].maSV, MaSVcanTim) == 0)
        {
            cout << "Tim thay sinh vien." << endl;
            Xuat(a[i]);
            Tim = true;
        }
    }
    if (Tim == false)
    {
        cout << "Khong tim thay sinh vien." << endl;
    }
}
void TimSVcungTen()
{
    char TenCanTim[10];
    cout << "Nhap ten sinh vien can tim: ";
    fflush(stdin);
    cin.getline(TenCanTim, 10);
    SV a[size];
    int count = 0, b = 0;
    bool Tim = false;
    DocListSV(a, count);
    SV CungTen[count];
    for (int i = 0; i < count; i++)
        if (strcmp(a[i].ten, TenCanTim) == 0)
        {
            CungTen[b] = a[i];
            Tim = true;
            b++;
        }
    if (Tim == false)
    {
        cout << "Khong tim thay sinh vien." << endl;
    }
    else
    {
        cout << "==============================================" << endl;
        for (int i = 0; i < b - 1; i++)
            for (int j = i; j < b; j++)
                if (CungTen[i].diemTB > CungTen[j].diemTB)
                {
                    SV temp = CungTen[i];
                    CungTen[i] = CungTen[j];
                    CungTen[j] = temp;
                }
        XuatListSV(CungTen, b);
        cout << "==============================================" << endl;
    }
}
int main()
{
    int Menu = 0;
    while (Menu != 7)
    {
        cout << "Chuc nang chuong trinh:" << endl;
        cout << "\t1. Them Sinh vien vao file." << endl;
        cout << "\t2. Xuat danh sach theo dieu kien." << endl;
        cout << "\t3. Xoa mot sinh vien theo ma Sinh vien." << endl;
        cout << "\t4. Sua Thong tin sinh vien bang ma Sinh vien." << endl;
        cout << "\t5. Tim sinh vien theo ma sinh vien." << endl;
        cout << "\t6. Tim sinh vien co ten la..." << endl;
        cout << "\t7. Thoat chuong trinh." << endl;
        cin >> Menu;
        system("cls");
        if (Menu == 1)
        {
            NhapListSV();
        }
        if (Menu == 2)
        {
            INDEX();
        }
        if (Menu == 3)
        {
            XoaSinhVien();
        }
        if (Menu == 4)
        {
            SuaSinhVien();
        }
        if (Menu == 5)
        {
            TimSinhVien();
        }
        if (Menu == 6)
        {
            TimSVcungTen();
        }
    }
    return 0;
}