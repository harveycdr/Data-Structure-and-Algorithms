#pragma once
#include <iostream>
#include "sinhvien.cpp"
#include "bangsv.cpp"
#include "stringsupport.cpp"

void XeptheoTen(Node *&p)
{
    for(Node *a = p; a != NULL; a = a->head)
    {
        Node *b = a;
        for(Node *c = a->head; c != NULL; c = c->head)
        {
            str i1 = b->item->tenSV->c_str();
            str i2 = c->item->tenSV->c_str();
            if (i1 > i2){
                b = c;
            }
        }
        SinhVien *temp = a->item;
        a->item = b->item;
        b->item = temp;
    }
    return;
}

void XeptheoDiem(Node *&p)
{
    for(Node *a = p; a != NULL; a = a->head)
    {
        Node *b = a;
        for(Node *c = a->head; c != NULL; c = c->head)
        {
            float i1 = (float)b->item->diemTB;
            float i2 = (float)c->item->diemTB;
            if (i1 > i2){
                b = c;
            }
        }
        SinhVien *temp = a->item;
        a->item = b->item;
        b->item = temp;
    }
    return;
}

void XeptheoTuoi(Node *&p)
{
    for(Node *a = p; a != NULL; a = a->head)
    {
        Node *b = a;
        for(Node *c = a->head; c != NULL; c = c->head)
        {
            float i1 = (float)b->item->tuoiSV;
            float i2 = (float)c->item->tuoiSV;
            if (i1 > i2){
                b = c;
            }
        }
        SinhVien *temp = a->item;
        a->item = b->item;
        b->item = temp;
    }
    return;
}

void SapxepSV(Node *&p)
{
    char index = '0';
    printf(
        "\t(!) Sap xep theo:\n"
        "\t(?) 1-Ten\n"
        "\t(?) 2-Tuoi\n"
        "\t(?) 3-Diem\n"
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
        printf("\t   (!) Sap xep theo ten \n");
        XeptheoTen(p);
        printf("\t   (!) Da sap xep theo ten! \n");
        break;
    case '2':
        printf("\t   (!) Sap xep theo tuoi \n");
        XeptheoTuoi(p);
        printf("\t   (!) Da sap xep theo tuoi! \n");
        break;
    case '3':
        printf("\t   (!) Sap xep theo diem \n");
        XeptheoDiem(p);
        printf("\t   (!) Da sap xep theo diem: \n");
        break;
    }
    return;
}