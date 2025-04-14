#pragma once
#include <stdexcept>

using namespace std;

/// <typeparam name="T">Тип данных, хранящихся в стеке </typeparam>
template<class T>

/// <summary>
/// Класс `Stack` реализует структуру данных "стек" с использованием связного списка.
/// </summary>
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

/// <summary>
/// Добавляет элемент на вершину стека.
/// </summary>
template <class T>
void Stack<T>::push(T elem)
{
    top = new Node(elem, top);
    size++;
}

/// <summary>
/// Удаляет и возвращает элемент с вершины стека.
/// </summary>
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

/// <summary>
/// Возвращает значение элемента на вершине стека без его удаления.
/// </summary>
template <class T>
T Stack<T>::peek()
{
    if (top == nullptr)
    {
        throw out_of_range("Stack is empty");
    }
    return top->data;
}

/// <summary>
/// Возвращает количество элементов в стеке.
/// </summary>
template <class T>
int Stack<T>::count()
{
    return size;
}

/// <summary>
/// Очищает стек, удаляя все элементы.
/// </summary>
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