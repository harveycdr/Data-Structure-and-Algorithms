#pragma once
#include "sinhvien.cpp"
#include "bangsv.cpp"

void SuaThongTinSV(Node *&p)
{
    printf("[!] Danh sach sinh vien\n");
    BangDanhSachSV(p, "\t");
    printf("\t(?) Nhap stt sv muon sua: ");
    char *index = new char[10];
    fflush(stdin);
    std::cin.getline(index, 10);
    fflush(stdin);
    int i = (int)my_ctof(index);

    Node *a = p;
    int j = 1;
    for (j = 1; a != NULL && j < i; ++j){
        a = a->head;
    }

    if (i <= 0 || i > j ){
        printf("\t(!) Nhap stt sai!\n");
        return;
    }else{
        printf(
            "\t   (!) Sua thong tin sv:\n"
            "\t   (?) 1-Ten: %s\n"
            "\t   (?) 2-Tuoi: %d\n"
            "\t   (?) 3-Diem: %0.2f\n"
            "\t   (?) 4-Gioi tinh: %s\n"
            "\t   (?) 5-Hoan tat sua doi\n",
            a->item->tenSV->c_str(), (int)a->item->tuoiSV, a->item->diemTB,
            gt(a->item->gioitinh).c_str()
        );
        char b = '0';
        while (b != '5')
        {
            printf("\t   (?) Lua chon: ");
            std::cin>>b;
            // b = getch();
            // printf("%c\n", b);
            fflush(stdin);
            switch (b)
            {
            case '1':
                printf("\t\t(?) Nhap ten moi: ");
                std::getline(std::cin, *a->item->tenSV);
                printf("\t\t(!) Da sua thanh cong sv!\n");
                break;
            case '2':
                printf("\t\t(?) Nhap tuoi moi: ");
                char c[10];
                std::cin.getline(c, 10);
                a->item->tuoiSV = my_ctof(c);
                printf("\t\t(!) Da sua thanh cong sv!\n");
                break;
            case '3':
                printf("\t\t(?) Nhap diem moi: ");
                char d[10];
                std::cin.getline(d, 10);
                a->item->diemTB = my_ctof(d);
                printf("\t\t(!) Da sua thanh cong sv!\n");
                break;
            case '4':
                if(a->item->gioitinh == 1) a->item->gioitinh = 0;
                else a->item->gioitinh = 1;
                printf("\t\t(!) Da thay doi gioi tinh!\n");
                break;
            case '5':
                printf(
                "\t\t(!) Da sua thanh cong sv!\n"
                "\t\t(!) Ten: %s, Tuoi: %d, Diem TB: %0.2f\n",
                a->item->tenSV->c_str(), (int)a->item->tuoiSV, a->item->diemTB,
                gt(a->item->gioitinh)
                );
                return;
                break;
            }
        }
    }
}