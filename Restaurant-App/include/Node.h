#pragma once

template <typename T>
class Node {
private:
    T item;
    Node<T>* next;
    int priority; // تأكد من وجود هذا المتغير

public:
    Node() : next(nullptr), priority(0) {}
    Node(const T& r_Item) : item(r_Item), next(nullptr), priority(0) {}

    void setItem(const T& r_Item) { item = r_Item; }
    void setNext(Node<T>* nextNodePtr) { next = nextNodePtr; }
    T getItem() const { return item; }
    Node<T>* getNext() const { return next; }

    // تأكد من وجود هاتين الدالتين
    void setPriority(int p) { priority = p; }
    int getPriority() const { return priority; }
};