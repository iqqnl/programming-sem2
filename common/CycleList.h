#pragma once
#include <stdexcept>
#include "node.h"

template <typename T>
class CycleList {
private:
    Node<T>* tail;
    int size;

    Node<T>* getNode(int index) const {
        if (index < 0 || index >= size) throw std::out_of_range("Index out of range");
        Node<T>* current = tail->next;
        for (int i = 0; i < index; ++i)
            current = current->next;
        return current;
    }

public:
    CycleList() : tail(nullptr), size(0) {}

    ~CycleList() {
        clear();
    }

    void add(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
        ++size;
    }

    void insert(int index, T value) {
        if (index < 0 || index > size) throw std::out_of_range("Index out of range");
        Node<T>* newNode = new Node<T>(value);
        if (index == 0) {
            if (!tail) {
                tail = newNode;
                tail->next = tail;
            } else {
                newNode->next = tail->next;
                tail->next = newNode;
            }
        } else {
            Node<T>* prev = getNode(index - 1);
            newNode->next = prev->next;
            prev->next = newNode;
            if (prev == tail)
                tail = newNode;
        }
        ++size;
    }

    void removeAt(int index) {
        if (index < 0 || index >= size) throw std::out_of_range("Index out of range");
        Node<T>* toDelete;
        if (index == 0) {
            toDelete = tail->next;
            if (tail == tail->next) {
                tail = nullptr;
            } else {
                tail->next = toDelete->next;
            }
        } else {
            Node<T>* prev = getNode(index - 1);
            toDelete = prev->next;
            prev->next = toDelete->next;
            if (toDelete == tail)
                tail = prev;
        }
        delete toDelete;
        --size;
    }

    T& operator[](const int index) {
        return getNode(index)->data;
    }

    int count() const {
        return size;
    }

    int count(T value) const {
        int result = 0;
        if (!tail) return 0;
        Node<T>* current = tail->next;
        for (int i = 0; i < size; ++i) {
            if (current->data == value) ++result;
            current = current->next;
        }
        return result;
    }

    void clear() {
        while (size > 0) {
            removeAt(0);
        }
    }
};