#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class PriorityQueue {
    Node<T>* head;
    int count;
public:
    PriorityQueue() : head(nullptr), count(0) {}
    bool isEmpty() const { return head == nullptr; }
    int getCount() const { return count; }
    void enqueue(const T& newEntry, int priority) {
        Node<T>* newNode = new Node<T>(newEntry);
        newNode->setPriority(priority);
        if (isEmpty() || priority > head->getPriority()) {
            newNode->setNext(head);
            head = newNode;
        }
        else {
            Node<T>* current = head;
            while (current->getNext() && current->getNext()->getPriority() >= priority)
                current = current->getNext();
            newNode->setNext(current->getNext());
            current->setNext(newNode);
        }
        count++;
    }
    bool dequeue(T& topEntry) {
        if (isEmpty()) return false;
        Node<T>* nodeToDelete = head;
        topEntry = head->getItem();
        head = head->getNext();
        delete nodeToDelete;
        count--;
        return true;
    }
    void print() const {
        Node<T>* temp = head;
        while (temp) {
            cout << temp->getItem();
            temp = temp->getNext();
            if (temp) cout << ", ";
        }
    }
    ~PriorityQueue() { T temp; while (dequeue(temp)); }
};