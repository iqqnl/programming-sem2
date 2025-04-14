#pragma once

#include <stdexcept>
#include "node.h"

using namespace std;

template <typename T>
class Queue
{
    private:
    Node<T>* head;
    Node<T>* tail;
    int elementsCount;

    public:
    Queue() : head(nullptr), tail(nullptr), elementsCount(0) {}

    ~Queue()
        {
            this->clear();
        }
    
        void queue(T);
        T unqueue();
        int count();
        void clear();
};

template <typename T>
void Queue<T>::queue(T data)
{
    Node<T>* newNode = new Node(data);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        elementsCount++;
}

template <typename T>
T Queue<T>::unqueue()
{
    if (!head) throw runtime_error("Пусто");
        
        Node<T>* temp = head;
        T data = temp->data;
        head = head->next;
        if (!head) tail = nullptr;
        
        delete temp;
        elementsCount--;
        return data;
}

template<typename T>
int Queue<T>::count()
{
    return elementsCount;
}

template<typename T>
void Queue<T>:: clear()
{
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        elementsCount = 0;
}
