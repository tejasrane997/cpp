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

	void PrintList();

	void ClearList();

	void Add(T data);

	void Delete(T data);

private:
	LinkedList* head = nullptr;
};
