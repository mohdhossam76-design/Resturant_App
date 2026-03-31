#include "Table.h"

Table::Table(int id) {
    this->id = id;
}

int Table::getId() const {
    return id;
}

void Table::setId(int newId) {
    this->id = newId;
}

ostream& operator<<(ostream& os, const Table& table) {
    os << table.id;
    return os;
}

bool Table::operator==(const Table& other) const {
    return this->id == other.id;
}