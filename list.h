#pragma once

#include "node.h"
#include <functional>

using namespace std;

template <class T>
class List
{
    public:

        List();

        void begin();

        void end();

        void pop_front();

        void pop_back();

        void push_front(T data); 

        void push_back(T& data); 

        void erase(int index); 

        size_t size() const; 

        bool empty() const;

        T& operator[](int index) const;

    private:
        Node<T>* head; //голова списка

        Node<T>* temp; //последний узел
};
