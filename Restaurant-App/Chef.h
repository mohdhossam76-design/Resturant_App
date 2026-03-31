#ifndef CHEF_H
#define CHEF_H

#include <iostream>
using namespace std;

class Chef {
private:
    int id;

public:
    Chef(int id = 0);
    int getId() const;
    void setId(int newId);

    friend ostream& operator<<(ostream& os, const Chef& chef);
    bool operator==(const Chef& other) const;
};

#endif