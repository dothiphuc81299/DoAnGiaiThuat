#include"Node.h"
#include<iostream>
using namespace std;
template<typename T>
Node<T>::Node(const T&x)
{
	data = x;
	next = NULL;
}
template<typename T>
Node<T>::~Node<T>()
{

}
template<typename T>
ostream& operator<<(ostream& o, const Node<T> & node)
{
	o << node.data;
	return o;
}