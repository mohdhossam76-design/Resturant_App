#ifndef TABLE_H
#define TABLE_H

#include <iostream>
using namespace std;

class Table {
private:
    int id;

public:
    Table(int id = 0);
    int getId() const;
    void setId(int newId);

    friend ostream& operator<<(ostream& os, const Table& table);
    bool operator==(const Table& other) const;
};

#endif