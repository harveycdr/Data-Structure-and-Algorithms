#pragma once
#include <iostream>
#include "sinhvien.cpp"
#include "stringsupport.cpp"

void ThongKeTuoi(Node *&p)
{
    str t[5] = {"> 65", "45-65", "31-44", "18-30", "<18"};
    int CountTuoi[5] = {0};
    int ss = 0;
    for(Node *a = p; a!=NULL; a = a->head)
    {
        ss += 1;
        int d = a->item->tuoiSV;
        int i = 0;
        if (d > 65) i = 0;
        else if (d >= 45) i = 1;
        else if (d >= 31) i = 2;
        else if (d >= 18) i = 3;
        else if (d >= 0) i = 4;
        else return;
        CountTuoi[i] += 1;
    }
    for(int i=0; i < 5; ++i)
    {
        if (CountTuoi[i] > 0)
        {
            float pt = (float)CountTuoi[i]*100/ss;
            printf("\t   (!) Hoc vien co tuoi %s la %.2f %\n", t[i].c_str(), (float)pt);
        }
    }
    return;
}

void ThongKeHocLuc(Node *&p)
{
    str h[5] = {"Gioi", "Kha", "Trung Binh", "Yeu", "Kem"};
    int CountHL[5] = {0};
    int ss = 0;
    for(Node *a = p; a!=NULL; a = a->head)
    {
        ss += 1;
        float d = (float)a->item->diemTB;
        int i = 0;
        if (d <= 10 && d >= 8.0) i = 0;//Gioi
        else if (d >= 6.5) i = 1; //Kha
        else if (d >= 5.0) i = 2; //Trung Binh
        else if (d >= 3.5) i = 3; //Yeu
        else if (d >= 0) i = 4; //Kem
        else return;
        CountHL[i] += 1;
    }
    for(int i=0; i < 5; ++i)
    {
        if (CountHL[i] > 0)
        {
            float pt = (float)CountHL[i]*100/ss;
            printf("\t   (!) Hoc vien %s la %.2f %\n", h[i].c_str(), (float)pt);
        }
    }
    return;
}

void ThongKeGioiTinh(Node *&p)
{
    str h[2] = {"Nam", "Nu"};
    int CountHL[2] = {0};
    int ss = 0;
    for(Node *a = p; a!=NULL; a = a->head)
    {
        ss += 1;
        int d = a->item->gioitinh;
        int i = 0;
        if (d == 1) i = 0;
        else i = 1;
        CountHL[i] += 1;
    }
    for(int i=0; i < 2; ++i)
    {
        if (CountHL[i] > 0)
        {
            float pt = (float)CountHL[i]*100/ss;
            printf("\t   (!) Hoc vien %s la %.2f %\n", h[i].c_str(), (float)pt);
        }
    }
    return;
}

void ThongKeSV(Node *&p)
{
    char index = '0';
    printf(
        "\t(!) Thong ke sinh vien theo:\n"
        "\t(?) 1-Hoc luc\n"
        "\t(?) 2-Tuoi\n"
        "\t(?) 3-Gioitinh\n"
    );
    printf("\t(?) Lua chon: ");
    fflush(stdin);
    std::cin>>index;
    fflush(stdin);
    str c = "";
    Node *a = NULL;
    switch (index)
    {
    case '1':
        printf("\t   (!) Thong ke theo hoc luc \n");
        ThongKeHocLuc(p);
        break;
    case '2':
        printf("\t   (!) Thong ke theo tuoi \n");
        ThongKeTuoi(p);
        break;
    case '3':
        printf("\t   (!) Thong ke theo gioi tinh \n");
        ThongKeGioiTinh(p);
        break;
    }
    return;
}