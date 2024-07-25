#include <iostream>
#include <fstream>
#include "stringsupport.cpp"
#include "bangsv.cpp"
#include "sinhvien.cpp"
#include "themsv.cpp"
#include "xoasv.cpp"
#include "suasv.cpp"
#include "timkiemsv.cpp"
#include "sapxepsv.cpp"
#include "thongke.cpp"

bool SaoLuuFile(const char* file_name, Node *&p)
{
    std::fstream f_out;
    f_out.open(file_name, std::ios::out);
    if(!f_out.is_open())
    {
        printf("\t\tMo file %s that bai!\n");
        return false;
    }

    for (Node *i = p;i != NULL;i = i->head)
    {
        f_out << i->item->tenSV->c_str()<<"; ";
        f_out << i->item->tuoiSV<<"; ";
        f_out << i->item->diemTB<<"; ";
        f_out << i->item->gioitinh;
        if (i->head != NULL){f_out<<"\n";}
    }

    f_out.close();
    return true;
}

int main(){
    system("cls");
    const char *file_name = "qlsv.txt";
    Node *p = DocFile(file_name);
    char index = '0';
    while (index != '9')
    {
        printf(
            "Danh sach thao tac: \n"
            "1 - In danh sach SV\n"
            "2 - Them\n"
            "3 - Sua\n"
            "4 - Xoa\n"
            "5 - Tim Kiem\n"
            "6 - Sap Xep\n"
            "7 - Thong Ke\n"
            "8 - Sao Luu\n"
            "9 - Thoat\n"
        );
        printf("Nhap lenh: ");
        fflush(stdin);
        std::cin>>index;
        // index = getch();
        // printf("%c\n", index);

        switch (index)
        {
        case '1':
            system("cls");
            printf("[1] In danh sach sinh vien:\n");
            BangDanhSachSV(p, "\t");
            system("pause");
            break;
        case '2':
            system("cls");
            printf("[2] Them sinh vien moi\n");
            ThemSV(p);
            system("pause");
            break;
        case '3':
            system("cls");
            printf("[3] Sua thong tin sinh vien\n");
            SuaThongTinSV(p);
            system("pause");
            break;
        case '4':
            system("cls");
            printf("[4] Xoa sinh vien\n");
            XoaSV(p);
            system("pause");
            break;
        case '5':
            system("cls");
            printf("[5] Tim Kiem sinh vien\n");
            TimKiemSV(p);
            system("pause");
            break;
        case '6':
            system("cls");
            printf("[6] Sap xep sinh vien\n");
            SapxepSV(p);
            system("pause");
            break;
        case '7':
            system("cls");
            printf("[7] Thong ke sinh vien\n");
            ThongKeSV(p);
            system("pause");
            break;
        case '8':
            printf("[8] Sao luu vao file %s\n", file_name);
            bool a = SaoLuuFile(file_name, p);
            a ? printf("[!] Sao luu thanh cong!\n"): printf("[!] Sao luu bi loi!\n");
            system("pause");
            break;
        }
        system("cls");
    }
    printf("Thoat!\n");
    delete p;
    return 0;
}
