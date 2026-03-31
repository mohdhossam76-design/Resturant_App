#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
private:
	Node<T>* Head;
	int count;

public:
	LinkedList()
	{
		Head = nullptr;
		count = 0;
	}

	~LinkedList()
	{
		DeleteAll();
	}

	int getCount() const
	{
		return count;
	}

	void print() const
	{
		if (!Head) return;
		Node<T>* p = Head;
		while (p)
		{
			cout << p->getItem();
			p = p->getNext();
			if (p) cout << ", ";
		}
	}

	void PrintList() const
	{
		Node<T>* p = Head;
		while (p)
		{
			cout << "[ " << p->getItem() << " ]" << "--->";
			p = p->getNext();
		}
		cout << "NULL\n";
	}

	void InsertBeg(const T& data)
	{
		Node<T>* R = new Node<T>(data);
		R->setNext(Head);
		Head = R;
		count++;
	}

	void DeleteAll()
	{
		Node<T>* P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
		count = 0;
	}

	void InsertEnd(const T& data)
	{
		if (!Head) {
			InsertBeg(data);
			return;
		}
		Node<T>* p = Head;
		while (p->getNext()) {
			p = p->getNext();
		}
		Node<T>* newNode = new Node<T>(data);
		p->setNext(newNode);
		count++;
	}

	bool Find(const T& Key)
	{
		Node<T>* p = Head;
		while (p) {
			if (p->getItem() == Key) return true;
			p = p->getNext();
		}
		return false;
	}

	int CountOccurance(const T& value)
	{
		int occ = 0;
		Node<T>* p = Head;
		while (p) {
			if (p->getItem() == value) occ++;
			p = p->getNext();
		}
		return occ;
	}

	void DeleteFirst()
	{
		if (!Head) return;
		Node<T>* p = Head;
		Head = Head->getNext();
		delete p;
		count--;
	}

	void DeleteLast()
	{
		if (!Head) return;
		if (!Head->getNext()) {
			delete Head;
			Head = nullptr;
			count--;
			return;
		}
		Node<T>* p = Head;
		while (p->getNext()->getNext()) {
			p = p->getNext();
		}
		delete p->getNext();
		p->setNext(nullptr);
		count--;
	}

	bool DeleteNode(const T& value)
	{
		if (!Head) return false;
		if (Head->getItem() == value) {
			DeleteFirst();
			return true;
		}
		Node<T>* p = Head;
		while (p->getNext()) {
			if (p->getNext()->getItem() == value) {
				Node<T>* temp = p->getNext();
				p->setNext(temp->getNext());
				delete temp;
				count--;
				return true;
			}
			p = p->getNext();
		}
		return false;
	}

	bool DeleteNodes(const T& value)
	{
		bool deleted = false;
		while (Head && Head->getItem() == value) {
			DeleteFirst();
			deleted = true;
		}
		if (!Head) return deleted;
		Node<T>* p = Head;
		while (p->getNext()) {
			if (p->getNext()->getItem() == value) {
				Node<T>* temp = p->getNext();
				p->setNext(temp->getNext());
				delete temp;
				count--;
				deleted = true;
			}
			else {
				p = p->getNext();
			}
		}
		return deleted;
	}

	void Merge(const LinkedList& L)
	{
		if (!Head) {
			Head = L.Head;
		}
		else {
			Node<T>* p = Head;
			while (p->getNext()) {
				p = p->getNext();
			}
			p->setNext(L.Head);
		}
	}

	void Reverse()
	{
		Node<T>* prev = nullptr;
		Node<T>* current = Head;
		Node<T>* next = nullptr;
		while (current) {
			next = current->getNext();
			current->setNext(prev);
			prev = current;
			current = next;
		}
		Head = prev;
	}
};