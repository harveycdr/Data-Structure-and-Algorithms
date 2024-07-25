#pragma once
#include <iostream>
#include <fstream>
#include "stringsupport.cpp"

bool Ok_Cancel(str t = "Tiep tuc", str f = "Thoat")
{
    char a = 'a';
    printf("\t   (?) 0 - %s\n", f.c_str());
    printf("\t   (?) 1 - %s\n", t.c_str());
    while (!(a == '0' || a == '1'))
    {
        printf("\t   (?) Lua Chon: ");
        fflush(stdin);
        std::cin>>a;
    }
    return a == '0' ? false : true;
}

str gt(const int &i){
    return (i == 1) ? "Nam": "Nu";
}

struct SinhVien
{
    str *tenSV;
    float tuoiSV;
    float diemTB;
    int gioitinh;
    SinhVien(const str &ten, const float &tuoi, const float &diem, const int &i = 1)
    {
        this->tenSV = new str(ten);
        this->tuoiSV = tuoi;
        this->diemTB = diem;
        this->gioitinh = i;
    }
    SinhVien()
        :SinhVien("null", 0.0, 0.0)
    {}
    ~SinhVien()
    {}
    SinhVien operator =(const SinhVien &other){
        this->tenSV = other.tenSV;
        this->tuoiSV = other.tuoiSV;
        this->diemTB = other.diemTB;
        this->gioitinh = other.gioitinh;
        return *this;
    }
};

SinhVien *TachDataSV(const str &s, const char &delim)
{
    str *a = new str[4];
    int b = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        char c = s[i];
        if (c == delim) b = b + 1;
        else{
            a[b].push_back(c);
        }
    }
    str ten = a[0].c_str();
    float tuoi = my_ctof(a[1].c_str());
    float diem = my_ctof(a[2].c_str());
    int gt = (int)my_ctof(a[3].c_str());
    delete[] a;
    SinhVien *p = new SinhVien(ten, tuoi, diem, gt);
    return p;
}

struct Node
{
    SinhVien *item;
    Node *head;
    Node *tail;
    Node(const SinhVien &i){
        SinhVien *sv = new SinhVien(i);
        this->item = sv;
        this->tail = NULL;
        this->head = tail;
    }
    Node():Node( SinhVien() )
    {}
    ~Node(){
        delete item;
        delete head;
        delete tail;
    }
};
void InsLastNode(Node *&p, SinhVien &i)
{
    if(p == NULL)
    {
        p = new Node(i);
        return;
    }
    else if (p->head == NULL)
    {
        p->head = new Node(i);
        p->tail = p->head;
        return;
    }else{
        Node *a = p->tail;
        a->head = new Node(i);
        p->tail = a->head;
    }
    return;
}
Node *DocFile(const char* file_name)
{
    std::fstream f_in;
    f_in.open(file_name, std::ios::in);
    if(!f_in.is_open())
    {
        printf("\t\tMo file %s that bai!\n");
        exit(0);
    }

    Node *p = NULL;
    while(!f_in.eof())
    {
        fflush(stdin);
        str a;
        std::getline(f_in, a);
        if(a.size() > 1){
            SinhVien *data = TachDataSV(a, ';');
            InsLastNode(p, *data);
        }
    }
    f_in.close();
    return p;
}

int SizeNode(Node *&p){
    int i=0;
    for(Node *a = p; a != NULL; a = a->head)
    {
        i = i+1;
    }
    return i;
}