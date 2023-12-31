#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list)
{
	//shallow copy
	this->head = list->head;

	//deep copy

}

template <typename T>
void LinkedList<T>::printList()
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
void LinkedList<T>::clearList()
{
	while (head) {
		LinkedList* temp = head;
		head = head->next;
		delete temp;
	}
	head = nullptr;
}

template <typename T>
void LinkedList<T>::add(T data)
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
void LinkedList<T>::remove(T data)
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

template<typename T>
void LinkedList<T>::reverseList()
{
	LinkedList* prev = nullptr;
	while (head != nullptr) {
		LinkedList* temp = head;
		head = head->next;

		temp->next = prev;
		prev = temp;
	}
	head = prev;
}