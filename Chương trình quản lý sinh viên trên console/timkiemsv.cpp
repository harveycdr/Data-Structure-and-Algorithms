#pragma once
#include <iostream>
#include "sinhvien.cpp"
#include "bangsv.cpp"
#include "stringsupport.cpp"

void TimKiemSV(Node *&p)
{
    char index = '0';
    printf(
        "\t(!) Tim kiem theo:\n"
        "\t(?) 1-Ten\n"
        "\t(?) 2-Tuoi\n"
        "\t(?) 3-Diem\n"
        "\t(?) 4-Gioi tinh\n"
        "\t(?) 5-Ket thuc tim kiem\n"
    );
    while (index != '5')
    {
        printf("\t(?) Lua chon: ");
        fflush(stdin);
        std::cin>>index;
        fflush(stdin);
        str c = "";
        Node *a = NULL;
        float vl;
        switch (index)
        {
        case '1':
            printf("\t   (?) Nhap ki tu: ");
            std::getline(std::cin, c);
            for (Node *i = p;i != NULL; i = i->head)
            {
                if (substr_in_str(c, *(i->item->tenSV) )){
                    InsLastNode(a, *(i->item));
                }
            }
            printf("\t   (!) Sinh vien co ki tu %s trong ten la:\n", c.c_str());
            BangDanhSachSV(a, "\t");
            break;
        case '2':
            printf("\t   (?) Nhap tuoi: ");
            std::getline(std::cin, c);
            vl = my_ctof(c.c_str());
            for (Node *i = p;i != NULL; i = i->head)
            {
                if ((int)vl == (int)i->item->tuoiSV ){
                    InsLastNode(a, *(i->item));
                }
            }
            printf("\t   (!) Sinh vien co tuoi %s la:\n", c.c_str());
            BangDanhSachSV(a, "\t");
            break;
        case '3':
            printf("\t   (?) Nhap diem: ");
            std::getline(std::cin, c);
            vl = (float)my_ctof(c.c_str());
            for (Node *i = p;i != NULL; i = i->head)
            {
                if ((float)vl == (float)i->item->diemTB ){
                    InsLastNode(a, *(i->item));
                }
            }
            printf("\t   (!) Sinh vien co diem TB %s la:\n", c.c_str());
            BangDanhSachSV(a, "\t");
            break;
        case '4':
            vl = 0;
            if (Ok_Cancel("Nam", "Nu")) vl = 1;
            c = gt((int)vl);
            for (Node *i = p;i != NULL; i = i->head)
            {
                if (vl == i->item->gioitinh ){
                    InsLastNode(a, *(i->item));
                }
            }
            printf("\t   (!) Sinh vien %s la:\n", c.c_str());
            BangDanhSachSV(a, "\t");
            break;
        case '5':
            printf("\t(!) Thoat tim kiem\n");
            break;
        }
    }
}