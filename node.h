#pragma once

template <class T>
class Node
{
    //friend class List;
    public:

        Node(T& data, Node* next, Node* last);

        Node<T>* getNext() const;

        Node<T>* getPrevious() const;

        T& getData();

        void setNext(Node<T>* node);

        void setPrevious(Node<T>* node);

    private:
        T data;
        Node* next;
        Node* last;
};
