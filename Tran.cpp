#include "Tran.h"

template <class T>
Tran<T>& Tran<T>::operator=(const Tran<T>& obj)
{
    if (this != &obj)
    {
        delete that;
        that = new T(*(obj.that));
    }
    return *this;
}

template <class T>
T* Tran<T>::operator->()
{
    return that;
}

template <class T>
void Tran<T>::Show(int fl)
{
    cout << "\t\tБанковский счёт ";
    if (!fl)
        cout << "до начала транзакции " << endl;
    else
        cout << "после выполнения транзакции: " << endl;

    if (prev)
        cout << "\t\tДо операции: " << prev->get() << endl;
    else
        cout << "\t\tДо операции: данные отсутсвуют" << endl;
    cout << "\t\tВ данный момент " << that->get() << endl;
}

template <class T>
bool Tran<T>::Begin()
{
    delete prev;
    prev = that;
    that = new T(*prev);
    if (!that)
        return false;
    return true;
}

template <class T>
void Tran<T>::Commit()
{
    delete prev;
    prev = NULL;
}

template <class T>
void Tran<T>::Back()
{
    if (prev != NULL)
    {
        delete that;
        that = prev;
        prev = NULL;
    }
}