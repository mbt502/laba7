#include "node.h"
#include "list.h"
#include <functional>

template<class T>
List<T>::List()
{
    this->head = nullptr;
    this->temp = nullptr;
}

template <class T>
void List<T>::begin()
{
    return head;
}

template <class T>
void List<T>::end()
{
    return temp;
}

template<class T>
void List<T>::pop_front()
{
    if (head)
    {
        Node<T>* tmp = head;
        tmp = tmp->getNext();
        delete head;
        head = tmp;
    }
}

template<class T>
void List<T>::pop_back()
{
    if (temp)
    {
        Node<T>* current = temp;
        current = current->getPrevious();
        delete current->getNext();
    }
}

template<class T>
void List<T>::push_front(T data)
{
    Node<T>* nd = new Node<T>(data);
    temp = nd;

    if (head)
    {
        Node<T>* tmp = head;
        head = nd;
        nd->setNext(tmp);
    }

    else
    {
        head = nd;
        nd->setNext(nullptr);
    }
}

template<class T>
void List<T>::push_back(T& data)
{
    auto* nd = new Node<T>(data, nullptr, temp);
    temp = nd;

    if (head)
    {
        Node<T>* current = head;
        while (current->getNext())
            current = current->getNext();

        current->setNext(nd);
    }

    else
        head = nd;
}

template<class T>
void List<T>::erase(int index)
{
    size_t i = 0;

    Node<T>* node = head;

    while (node != nullptr && i != index)
    {
        i++;
        node = node->getNext();
    }

    if (i != index)
        return;

    Node<T>* previous = node->getPrevious(), * next = node->getNext();

    if (next == nullptr)
        next->setPrevious(previous);

    previous->setNext(next);

    delete node;
}

template<class T>
size_t List<T>::size() const
{
    size_t counter = 0;

    Node<T>* node = this->head;

    while (node != nullptr)
    {
        counter++;
        node = node->getNext();
    }

    return counter;
}

template<class T>
bool List<T>::empty() const
{
    return head == nullptr;
}

template <class T>
T& List<T>::operator[](int index) const
{
    size_t i = 0;

    Node<T>* node = head;

    while (node != nullptr && i != index)
    {
        i++;
        node = node->getNext();
    }

    if (i != index)
        throw invalid_argument("index is out of range");

    return node->getData();
}