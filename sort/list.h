#pragma once
#include <iostream>

void swap(int &a, int &b)
{
    int val = a;
    a = b;
    b = val;
}

template <typename T>
class list 
{
private:
    T *data;
    size_t size;
    size_t max_size;
public:
    list(): data(nullptr), size(0), max_size(0) {}
    // Constructor
    list(std::initializer_list<T> values) : list() {
        for (T element : values) {
            this->append(element);
        }
    }

    void append(const T& item)
    {
        if (max_size == 0)
        {
            max_size = 2;
            data = new T[max_size];
        }

        if (size >= max_size)
        {
            max_size *= 2;
            T *p = data;
            data = new T[max_size];
            for (int i = 0; i < size; ++i)
            {
                data[i] = *(p+i);
                
            }
        }
        data[size] = item;
        size += 1;
    }
    
    T &operator[](const size_t &index){ return data[index];}

    T &operator=(const list<T> &other)
    {
        max_size = other.max_size;
        size = other.size;
        data = other.data;
    }

    size_t length() {return size;}
};

template<class T> std::ostream &operator<<(std::ostream &out, list<T> &other){
    out<<"(";
    for(int i=0; i < other.length(); ++i)
    {
        out<<other[i]<<" ";
    }
    out<<")\n";
    return out;
} 
