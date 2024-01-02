#pragma once
#include <iostream>

template <typename T>
class LinkedList {

public:
	T data;
	LinkedList* next;

public:
	LinkedList() :
		data(NULL), next(nullptr) {}

	LinkedList(T data) :
		data(data), next(nullptr) {}

	LinkedList(T data, LinkedList* node) :
		data(data), next(node) {}

	LinkedList(const LinkedList<T>& list);

	void printList();

	void clearList();

	void add(T data);

	void remove(T data);

	void reverseList();

private:
	LinkedList* head = nullptr;
};
