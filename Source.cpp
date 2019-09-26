#include<iostream>
#include"HashTable.h"
#include"CreateWord.h"
using namespace std;
int Frequency[26];
int N = 26;
/*int HashFunc(char c)
{
	return (c - 'a');
}
int countFre(string tu)
{
	int Count;
	for (int i = 0; i < tu.length(); i++)
	{
		int index = HashFunc(tu[i]);
		Frequency[index]++;
	}
	for (int i = 0; i < 26; i++)
	{
		 Count = Frequency[i];
		//cout << (char)(i + 'a') << ' ' << Frequency[i] << endl;
	}
	return Count;
} */
int hash(const string&k, int N)
{
	int x = 0;
	for (int i = 0; i < k.length(); i++)
	{
		x = 37 * x + k[i];

	}
	return (x%N);
}
//Intializing the Hash Table
void initArray()
{
	for (int i = 0; i < N; i++)
	{
		arrayItem[i].head = NULL;
		arrayItem[i].tail = NULL;
	}
}
//

