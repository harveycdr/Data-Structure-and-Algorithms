#pragma once
#include <iostream>
#include <cstring>
typedef std::string str;
//support
//change string to float
float my_ctof(const char *ch)
{
    str a(ch);
    int b = 0;
    float c = 1;
    bool d = false;
    for (int i = 0; i < a.size(); i++)
    {
        int e = (int)a[i] / 48;
        int v = (int)a[i] % 48;
        if(v <= 9 && v >= 0 && e == 1)
        {
            b = b*10 + v;
            if (d) c = c*0.1;
        }
        if (a[i] == '.') d = true;
        if (a[i] == '-') c = c * (-1);
    }
    return (float)b * c;
}
//find substring in
bool substr_in_str(const str &con, const str &cha)
{
    for (int i = 0; i < cha.size(); ++i)
    {
        if (con[0] == cha[i])
        {
            int j = 1;
            for (j; j < con.size(); ++j)
            {
                if (con[j] != cha[i + j]) break;
            }
            if (j == con.size()) return true;
        }
    }
    return false;
}