#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class LinkedQueue {
    Node<T>* backPtr;
    Node<T>* frontPtr;
    int count;
public:
    LinkedQueue() : backPtr(nullptr), frontPtr(nullptr), count(0) {}
    bool isEmpty() const { return frontPtr == nullptr; }
    int getCount() const { return count; }
    bool enqueue(const T& newEntry) {
        Node<T>* newNodePtr = new Node<T>(newEntry);
        if (isEmpty()) frontPtr = newNodePtr;
        else backPtr->setNext(newNodePtr);
        backPtr = newNodePtr;
        count++;
        return true;
    }
    bool dequeue(T& frntEntry) {
        if (isEmpty()) return false;
        Node<T>* nodeToDeletePtr = frontPtr;
        frntEntry = frontPtr->getItem();
        frontPtr = frontPtr->getNext();
        if (nodeToDeletePtr == backPtr) backPtr = nullptr;
        delete nodeToDeletePtr;
        count--;
        return true;
    }
    void print() const {
        Node<T>* current = frontPtr;
        while (current) {
            cout << current->getItem();
            current = current->getNext();
            if (current) cout << ", ";
        }
    }
    ~LinkedQueue() { T temp; while (dequeue(temp)); }
};