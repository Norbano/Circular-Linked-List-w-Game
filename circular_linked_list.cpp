#include "circular_linked_list.h"
#include <iostream>
#include <string.h>

using namespace std;

template<typename T>
CircularLinkedList<T>::CircularLinkedList() :head(nullptr), tail(nullptr), size(0) {}


template<typename T>
CircularLinkedList<T>::CircularLinkedList(const CircularLinkedList<T>& other) : head(nullptr), tail(nullptr), size(0)
{
	if (other.size == 0)  
	{
		return;
	}
	Node* current1 = head;
	Node* current2 = other.head;
	for (int i = 0; i < size; i++)
	{
		current1 = current2;
		current2 = other.head->next;

	}
}


template<typename T>
CircularLinkedList<T>::Node::Node(const T& data) : data(data), next(nullptr) {}


template<typename T>
CircularLinkedList<T>::~CircularLinkedList()
{
	if (head == nullptr) 
	{
		return;
	}

	Node* curr = head->next;
	
	while (curr != head)
	{
		Node* temp = curr;
		curr = curr->next;
		delete temp;
	}
}

template<typename T>
int CircularLinkedList<T>::GetSize()
{
	return size;
}

template<typename T>
bool CircularLinkedList<T>::InList(const T& data)
{
	Node* temp = head;
	for (int i = 0; i < size; i++)
	{
		if (temp->data == data)
		{
			return true;
		}
		temp = temp->next;
	}
	return false;

}


template<typename T>
void CircularLinkedList<T>::AddFront(const T& data)
{
	Node* newNode = new Node(data);

	if (size == 0)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode->next = tail->next;
		head = newNode;
	}

	tail->next = head;
	size++;
}

template<typename T>
void CircularLinkedList<T>::AddBack(const T& data)
{
	Node* newNode = new Node(data);

	if (size == 0)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
	tail->next = head;
	size++;
}
template<typename T>
void CircularLinkedList<T>::AddBeforeX(const T& data, const T& x)
{
	Node* newNode = new Node(data);
	Node* current = head;
	Node* temp = current;
	int count = 0;
	while (current->data != x && count != size)
	{

		temp = current;
		current = current->next;
		count++;
	}
	if (count != size)
	{
		newNode->next = temp->next;
		temp->next = newNode;
		size++;

	}
}

template<typename T>
void CircularLinkedList<T>::AddAfterX(const T& data, const T& x)
{
	Node* newNode = new Node(data);
	Node* current = head;
	Node* temp = current;
	int count = 0;

	while (current->data != x && count != size)
	{
		current = current->next;
		temp = current;
		count++;
	}

	if (count != size)
	{
		newNode->next = current->next;
		current->next = newNode;
		size++;
	}
}

template<typename T>
void CircularLinkedList<T>::Remove(const T& data)
{

	Node* current = head;
	Node* previous = nullptr;
	bool found = false;
	do
	{
		if (current->data == data)
		{
			found = true;
			break;
		}
		previous = current;
		current = current->next;

	} while (current != head);

	if (found)
	{
		if (current == head)
		{
			head = head->next;
			tail->next = head;
		}
		else if (current == tail)
		{
			tail = previous;
			tail->next = head;
		}
		else
		{
			previous->next = current->next;
		}

		delete current;
		size--;
	}

}

template<typename T>
void CircularLinkedList<T>::Kiir()
{
	Node* current = head;
	for (int i = 0; i < size; i++)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}



template<typename T>
T CircularLinkedList<T>::GoThrough()
{
	head = tail->next;
	tail = tail->next;
	return head->data;
}
