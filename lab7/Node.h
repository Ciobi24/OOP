#pragma once

template<typename T>
class Node {
public:
	T value;
	Node* precedent;
	Node* next;
	Node(T info) {
		value = info;
		precedent = nullptr;
		next = nullptr;
	}
	Node() {
		precedent = nullptr;
		next = nullptr;
	}
};