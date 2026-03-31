#include "Scooter.h"

Scooter::Scooter(int id) {
    this->id = id;
}

int Scooter::getId() const {
    return id;
}

void Scooter::setId(int newId) {
    this->id = newId;
}

ostream& operator<<(ostream& os, const Scooter& scooter) {
    os << scooter.id;
    return os;
}

bool Scooter::operator==(const Scooter& other) const {
    return this->id == other.id;
}