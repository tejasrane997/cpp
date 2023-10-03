#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list)
{
	//shallow copy
	this->head = list->head;

	//deep copy

}

template <typename T>
void LinkedList<T>::PrintList()
{
	if (head == nullptr) {
		std::cout << "List is empty!" << std::endl;
	}

	LinkedList* trav = head;
	while (trav) {
		std::cout << trav->data << std::endl;
		trav = trav->next;
	}
}

template<typename T>
void LinkedList<T>::ClearList()
{
	while (head) {
		LinkedList* temp = head;
		head = head->next;
		delete temp;
	}
	head = nullptr;
}

template <typename T>
void LinkedList<T>::Add(T data)
{
	if(head == nullptr)
		head = new LinkedList(data);
	else {
		LinkedList* trav = head;
		while (trav->next) {
			trav = trav->next;
		}

		trav->next = new LinkedList(data);
	}
}

template <typename T>
void LinkedList<T>::Delete(T data)
{
	if (head->data = data) {
		LinkedList* temp = head;
		head = head->next;
		delete temp;
	}

	LinkedList* trav = head;
	while (trav->next && trav->next->data != data) {
		trav = trav->next;
	}

	if (!trav)
		std::cout << "Data not found!" << std::endl;
	else if (trav->next->data == data) {
		if (trav->next->next) {
			LinkedList* temp = trav->next;
			trav->next = temp->next;
			delete temp;
		}
		else {
			LinkedList* temp = trav->next;
			trav->next = nullptr;
			delete temp;
		}
	}
}