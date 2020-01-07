#pragma once
#include<iostream>
#include<string>
#include"Node.h"
#include"Word.h"
#include"Node.cpp"
using namespace std;
template<typename T>
class singlyLinkedList
{
	int size;
	Node<T>  *head;
public:
	singlyLinkedList();
	virtual ~singlyLinkedList();
	void insertAtHead(const T& data);
	void insertAtKPosition(const T& data, int k);
	void insertAtTail(const T& data);
	void printAllPointerNode() const;
	void remove(int);
	int getSize();
	Node<T> & getNode(int pos);
	Node<T>* getHeadNode();


};
