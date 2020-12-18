#pragma once
#include <iostream> 
#include <locale.h> 

using namespace std;

template <class T>
class Tran
{
    T* that;
    T* prev;
public:
    Tran() :prev(NULL), that(new T) {}
    Tran(const Tran& obj) :
        that(new T(*(obj.that))), prev(NULL) {}
    ~Tran() { delete that;  delete prev; }
    Tran& operator=(const Tran& obj);
    void Show(int);

    bool Begin();
    void Commit();
    void Back();
    T* operator->();
};