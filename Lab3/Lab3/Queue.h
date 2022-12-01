#pragma once
#include <iostream>

using namespace std;

template<class T>
class Queue {
    int size;//размер очереди
    int start;//первый элемент в queue
    int end;//последний элемент в queue
    T* arr;
    int count; //колличество элементов в queue
public:
    Queue(int _size = 1) {
        size = _size;
        start = 0;
        end = -1;      
        arr = new T[size];
        count = 0;
    }

    bool isEmpty(){
        return (count == 0);
    }

    bool isFull() {
        return (count == size);
    }

    void Push(T value) {
        if (Is_Full())
        {
            T* arr2 = new T[size * 2];
            end = 0;
            for (int i = 1; i < size; i++)
            {
                arr2[i] = arr[(end + 1) % size];
                end = (end + 1) % size;
            }
            delete[] arr;
            arr = arr2;
            size *= 2;
        }
        end = (end + 1) % size;
        arr[end] = value;
    }

    T Pop() {
        if (Is_Empty())
        {
            throw exception();
        }
        T arr2 = arr[start];
        start = (start + 1) % size;
        return arr2;
    }


    ~Queue(){delete[] arr;}
};