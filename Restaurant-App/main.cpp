#include <iostream>
#include "Order.h"
#include "include/LinkedQueue.h"
#include "include/ArrayStack.h"
#include "include/LinkedList.h"

using namespace std;

int main() {
    Order o1(101);
    Order o2(102);

    LinkedQueue<Order> q;
    q.enqueue(o1);
    q.enqueue(o2);

    cout << "Queue: ";
    q.print();
    cout << endl;


    ArrayStack<Order> s;
    s.push(o1);
    s.push(o2);

    cout << "Stack: ";
    s.print();
    cout << endl;

    return 0;
}