#pragma once
#include"CreateWord.h"
struct Node
{
	int key;
	Word value;
	struct Node *next;
};
typedef struct Node *node;
struct HashTable
{
	struct node *head;
	struct node *tail;
};
struct HashTable *arrayItem;
