#pragma once
#include <iostream>
using namespace std;

class Order {
private:
    int id;
    // يمكنك إضافة باقي الخصائص هنا لاحقاً (مثل النوع، المسافة، إلخ)

public:
    Order(int id = 0);           // Constructor
    int getId() const;           // Getter للـ ID
    void setId(int newId);       // Setter للـ ID

    // Overloading معامل الطباعة للكائن المباشر (Order)
    friend ostream& operator<<(ostream& os, const Order& order);

    // Overloading معامل الطباعة للمؤشر (Order*) - مهم جداً للمشروع
    friend ostream& operator<<(ostream& os, const Order* order);

    // Overloading معامل المساواة للبحث والحذف
    bool operator==(const Order& other) const;
};