#ifndef MYSTACK_H_
#define MYSTACK_H_
#include<iostream>
using namespace std;

const int MAXLEN = 100;
enum error_code{success,overflow,underflow};

template<typename T>
class mystack
{
public:
    mystack();
    bool empty() const;
    bool full() const;
    error_code get_top(T &x) const;
    error_code push(const T x);
    error_code pop();

private:
    int count;
    T data[MAXLEN];
};

template <typename T>
mystack<T>::mystack()
{
    count = 0;
}

template <typename T>
bool mystack<T>::empty() const
{
    if(count == 0)
        return true;
    else
        return false;
}

template <typename T>
bool mystack<T>::full() const
{
    return count == MAXLEN;
}
template <typename T>
error_code mystack<T>::get_top(T &x) const
{
    if (empty())
    {
        return underflow;
        cout << "error" << endl;
    }
    else
    {
        x = data[count-1];
        return success;
    }

}

template <typename T>
error_code mystack<T>::push(const T x)
{
    if (full())
    {
        return overflow;
        cout << "overflow" << endl;
    }
    data[count] = x;
    count++;
    return success;

}

template <typename T>
error_code mystack<T>::pop()
{
    if (empty())
    {
        return underflow;
        cout << "error" << endl;
    }
    count--;
    return success;

}












#endif // MYSTACK_H_INCLUDED
