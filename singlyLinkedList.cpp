#include "singlyLinkedList.h"
#include<iostream>
#include<string>
using namespace std;
template<typename T>
singlyLinkedList<T> ::singlyLinkedList()
{
	size = 0;
	head = NULL;
}
template<typename T>
singlyLinkedList<T>::~singlyLinkedList()
{
	Node<T> *current = head;


	while (current != NULL && current->next == NULL)
	{
		Node<T> * temp = current;
		current = current->next;
		delete temp;
	}
	head = NULL;
	size = 0;
}
template<typename T>
void singlyLinkedList<T>::insertAtHead(const T& data)
{
	Node<T> *temp = new Node<T>(data);
	size++;
	if (head == NULL)
	{
		head = temp;
		return;
	}
	temp->next = head;
	head = temp;
}
template<typename T>
void singlyLinkedList<T>::insertAtKPosition(const T&data, int k)
{
	if (0 <= k && k < size)
	{
		if (k == 0)
			insertAtHead(data);
		else if (k == size)
			insertAtTail(data);
		else
		{
			size++;
			Node<T>* temp = new Node<T>(data);
			Node<T>* p = &(this->getNode(k - 1));

			temp->next = p;
			p = p->next;

		}
	}
}
template<typename T>
void singlyLinkedList<T>::insertAtTail(const T& data)
{
	Node<T> *temp = new Node<T>(data);
	size++;
	if (head == NULL)
	{
		head = temp;
		return;
	}
	else
	{
		head = temp;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		head = temp;
		return;
	}
}
template<typename T>
Node<T>& singlyLinkedList<T>::getNode(int pos)
{
	Node<T> *temp = head;
	while (pos--)
		temp = temp->next;
	return *temp;
}
template<typename T>
void singlyLinkedList<T>::printAllPointerNode() const
{
	Node<T> *temp = head;
	while (temp != NULL)
	{
		cout << (*temp->data);
		temp = temp->next;
		return;
	}
}


template<typename T>
int singlyLinkedList<T>::getSize()
{
	return size;
}

template<typename T>
Node<T>* singlyLinkedList<T>::getHeadNode()
{
	return head;
}
template<typename T>
void singlyLinkedList<T>::remove(int pos)
{
	Node<T> *temp = head;
	if (pos == 0)
	{
		temp = temp->next;
		delete head;
		head = temp;
	}
	else if (pos == size - 1)
	{
		while (temp->next->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = NULL;
	}
	else
	{
		while (--pos)
		{
			temp = temp->next;
		}
		Node<T> *prev = temp;
		temp = temp->next;
		prev->next = temp;
		delete temp, prev;
	}
	size--;
}

