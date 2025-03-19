#pragma once
#include <stdexcept>

using namespace std;

template<class T>
class Stack
{
    public:
        ~Stack()
        {
            this->clear();
        }
        void push(T elem);
        T pop();
        T peek();
        int count();
        void clear();

    private:
        struct Node
        {
            T data;
            Node* next;

            Node(T data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
            
        };

        Node* top;
        int size;
};

template <class T>
void Stack<T>::push(T elem)
{
    top = new Node(elem, top);
    size++;
}

template <class T>
T Stack<T>::pop()
{
    if (top == nullptr)
    {
        throw out_of_range("Stack is empty");
    }
    Node* temp = top;
    T elem = temp->data;
    top = top->next;
    delete temp;
    size--;
    return elem;
}

template <class T>
T Stack<T>::peek()
{
    if (top == nullptr)
    {
        throw out_of_range("Stack is empty");
    }
    return top->data;
}

template <class T>
int Stack<T>::count()
{
    return size;
}

template <class T>
void Stack<T>::clear()
{
    while(top)
    {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    size = 0;
}