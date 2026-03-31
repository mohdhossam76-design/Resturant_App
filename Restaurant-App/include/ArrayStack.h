#pragma once
#include "StackADT.h"
#include <iostream>
using namespace std;

template<typename T>
class ArrayStack : public StackADT<T>
{
	enum { MAX_SIZE = 100 };
protected:
	T items[MAX_SIZE];
	int top;

public:
	ArrayStack() {
		top = -1;
	}

	bool isEmpty() const {
		return top == -1;
	}

	bool push(const T& newEntry) {
		if (top == MAX_SIZE - 1) return false;
		top++;
		items[top] = newEntry;
		return true;
	}

	bool pop(T& TopEntry) {
		if (isEmpty()) return false;
		TopEntry = items[top];
		top--;
		return true;
	}

	bool peek(T& TopEntry) const {
		if (isEmpty()) return false;
		TopEntry = items[top];
		return true;
	}

	int getCount() const {
		return top + 1;
	}

	void print() const {
		for (int i = top; i >= 0; i--) {
			cout << items[i];
			if (i > 0) cout << ", ";
		}
	}
};