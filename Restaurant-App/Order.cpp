#include "Order.h"

// Constructor
Order::Order(int id) {
    this->id = id;
}

// Getter
int Order::getId() const {
    return id;
}

// Setter
void Order::setId(int newId) {
    this->id = newId;
}

// تنفيذ طباعة الكائن (cout << order)
ostream& operator<<(ostream& os, const Order& order) {
    os << order.id;
    return os;
}

// تنفيذ طباعة المؤشر (cout << pOrder)
// هذا يمنع ظهور أرقام الـ Memory Address في الـ Console
ostream& operator<<(ostream& os, const Order* order) {
    if (order)
        os << order->id;
    else
        os << "NULL";
    return os;
}

// تنفيذ المقارنة (order1 == order2)
bool Order::operator==(const Order& other) const {
    return this->id == other.id;
}