#pragma once
#include <iostream>
#include "sinhvien.cpp"

void gach(int w_stt, int w_ten, int w_tuoi, int w_diem, const str tab = " "){
    printf("%s+", tab.c_str());
    for(int i=0; i < w_stt; ++i) printf("-");
    printf("+");
    for(int i=0; i < w_ten; ++i) printf("-");
    printf("+");
    for(int i=0; i < w_tuoi; ++i) printf("-");
    printf("+");
    for(int i=0; i < w_diem; ++i) printf("-");
    printf("+\n");
};

void BangDanhSachSV(Node *&p, const str tab = " "){
    if(p == NULL){
        printf("%s(!) Khong co sinh vien nao!\n", tab.c_str());
        return;
    }
    char title[4][8] = {"STT", "Ho Ten", "Tuoi", "Diem"};
    int w_stt = 5;
    int w_ten = 8;
    int w_tuoi = 8;
    int w_diem = 8;
    int countsv = 0;
    for (Node *a = p; a != NULL; a = a->head){
        if(a->item->tenSV->size() > w_ten - 5) {
            w_ten = a->item->tenSV->size() + 5;
        }
        countsv = countsv + 1;
    }
    while (countsv >= 1000)
    {
        countsv = countsv * 0.1;
        w_stt = w_stt + 1;
    }
    gach(w_stt, w_ten, w_tuoi, w_diem, tab);

    printf("%s", tab.c_str());
    printf("| %-*s", w_stt-1, title[0]);
    printf("| %-*s", w_ten-1, title[1]);
    printf("| %-*s", w_tuoi-1, title[2]);
    printf("| %-*s|\n", w_diem-1, title[3]);

    gach(w_stt, w_ten, w_tuoi, w_diem, tab);
    int count = 1;
    for (Node *i = p; i != NULL; i = i->head)
    {
        printf("%s", tab.c_str());
        printf("| %-*d", w_stt-1, count);
        printf("| %-*s", w_ten-1, i->item->tenSV->c_str());
        printf("| %-*.0f", w_tuoi-1, i->item->tuoiSV);
        printf("| %-*.2f|\n", w_diem-1, i->item->diemTB);
        count = count + 1;
    }

    gach(w_stt, w_ten, w_tuoi, w_diem, tab);

}
