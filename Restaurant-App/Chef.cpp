#include "Chef.h"

Chef::Chef(int id) {
    this->id = id;
}

int Chef::getId() const {
    return id;
}

void Chef::setId(int newId) {
    this->id = newId;
}

ostream& operator<<(ostream& os, const Chef& chef) {
    os << chef.id;
    return os;
}

bool Chef::operator==(const Chef& other) const {
    return this->id == other.id;
}