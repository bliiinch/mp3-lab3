#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Stack
{
    int top;
    int size;
    T* arr;
public:
    Stack(int _size){
        if (_size <= 0){
            throw exception();
        }
        top = -1;
        size = _size;
        arr = new T[size];
    }

    void Push(const T& value){
        if (top == IsFull()){
            T* tmp = new T[size * 2];
            copy(arr, size + arr, tmp);
            delete[] arr;
            arr = tmp;
            size *= 2;
        }
        arr[++top] = value;
    }

    T Pop(){
        if (IsEmpty())
        {
            throw exception();
        }
        T v = arr[top];
        top--;
        return v;
    }

    bool IsEmpty(){
        return top == -1;
    }

    bool IsFull(){
        return top == size - 1;
    }

    ~Stack(){delete[] arr;}
};
