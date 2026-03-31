#ifndef SCOOTER_H
#define SCOOTER_H

#include <iostream>
using namespace std;

class Scooter {
private:
    int id;

public:
    Scooter(int id = 0);
    int getId() const;
    void setId(int newId);

    friend ostream& operator<<(ostream& os, const Scooter& scooter);
    bool operator==(const Scooter& other) const;
};

#endif