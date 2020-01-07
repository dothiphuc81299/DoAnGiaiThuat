#pragma once 
#include<iostream>
#include"Word.h"
using namespace std;

template<typename T>
class Node
{
public:
	T data;
	Node<T>* next;
	Node(const T& x);
	virtual ~Node<T>();
	friend ostream& operator<<(ostream&o, const Node<T>& node);
};