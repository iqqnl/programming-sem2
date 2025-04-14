#pragma once

template <typename T>

struct Node
{
    T data;
    Node* next;
    Node(T data, Node* next = nullptr)
    {
        this->data = data;
        this->next = next;
    }

};

