#pragma once
#include <iostream>
#include "sinhvien.cpp"
#include "bangsv.cpp"


void XoaSV(Node *&p)
{
    printf("[!] Danh sach sinh vien\n");
    BangDanhSachSV(p, "\t");
    while (true)
    {
        printf("\t(?) Nhap stt sv muon xoa: ");
        char *index = new char[10];
        fflush(stdin);
        std::cin.getline(index, 10);
        int i = (int)my_ctof(index);

        Node *a = p;
        int j = 1;
        for (j = 1; a != NULL && j < i-1; ++j) a = a->head;

        if (i <= 0 || i-1 > j || a == NULL){
            printf("\t(!) Nhap stt sai!\n");
            return;
        }else{
            Node *b = NULL;
            (i == j) ? b = p : b = a->head;
            printf(
                "\t(!) Xoa sv ten: %s, Tuoi: %d, Diem TB: %0.2f\n",
                b->item->tenSV->c_str(), 
                (int)b->item->tuoiSV, 
                b->item->diemTB
            );
            if (Ok_Cancel("Xac nhan xoa", "Khong xoa")){
                if (i == 1){
                    p = b->head;
                    b->head = NULL;
                }else{
                    a->head = b->head;
                    b->head = NULL;
                }
                printf("\t(!) Xoa thanh cong!\n");
            }
        }
        if (!Ok_Cancel("Tiep tuc xoa", "Thoat")) break;
    }
    
}