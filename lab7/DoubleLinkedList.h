#pragma once
#include "Node.h"
#include <iostream>
template<typename T>
class DoubleLinkedList {
	Node<T>* first;
	Node<T>* last;
public:
	DoubleLinkedList() {
		first = nullptr;
		last = nullptr;
	}
	~DoubleLinkedList() {
		while (first != nullptr) {
			Node<T>* n = first->next;
			delete first;
			first = n;
		}
	}
	void PushOnFront(const T& info) {
		Node<T>* n = new Node<T>(info);
		if (first != nullptr)
		{
			first->precedent = n;
			n->next = first;
			first = n;
		}
		else
		{
			first = n;
			last = n;
		}
	}
	void PushOnBack(const T& info) {
		Node<T>* n = new Node<T>(info);
		if (first != nullptr)
		{
			last->next = n;
			n->precedent = last;
			last = n;
		}
		else
		{
			first = n;
			last = n;
		}
	}
	int GetCount() {
		int count = 0;
		Node<T>* n = first;
		while (n != nullptr) {
			count++;
			n = n->next;
		}
		return count;
	}
	T PopFromBack() {
		if (GetCount()>1)
		{
			Node<T>* n = last;
			last = last->precedent;
			last->next = nullptr;
			T info = n->value;
			delete n;
			return info;
		}
		else if (first == last) {
			T info = last->value;
			delete last;
			first = nullptr;
			last = nullptr;
			return info;
		}
	}

	void PrintAll(void (*func)(const T&))
	{
		std::cout << "Elements: " << GetCount() << " => ";
		Node<T>* n = first;
		while (n != nullptr) {
			func(n->value);
			n = n->next;
		}
		std::cout << std::endl;
	}
};