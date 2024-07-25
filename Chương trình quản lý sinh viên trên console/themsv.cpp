#pragma once
#include "sinhvien.cpp"


void ThemSV(Node *&p)
{
    str *a = new str[3];
    printf("\t(?) Nhap ten: ");
    fflush(stdin);
    std::getline(std::cin, a[0]);
    fflush(stdin);
    printf("\t(?) Nhap tuoi: ");
    fflush(stdin);
    std::getline(std::cin, a[1]);
    printf("\t(?) Nhap diem: ");
    fflush(stdin);
    std::getline(std::cin, a[2]);
    printf("\t(?) Gioi tinh: \n");
    int gth = (Ok_Cancel("Nam", "Nu") ? 1 : 0);
    float tuoi = my_ctof(a[1].c_str());
    float diem = my_ctof(a[2].c_str());
    SinhVien *i = new SinhVien(a[0], tuoi, diem, gth);
    InsLastNode(p, *i);
    printf(
        "\t   (!) Da them sinh vien moi co:\n"
        "\t   (!) Ten: %s, Tuoi: %d, Diem: %0.2f\n",
        a[0].c_str(), (int)tuoi, diem
    );
    return;
}