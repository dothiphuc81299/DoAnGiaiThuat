#pragma once
#include<iostream>
#include"singlyLinkedList.cpp"
#include"Word.h"
#include"Node.h"
using namespace std;
class HashTable
{
private:
	singlyLinkedList<Word*> *list;
	static int size;
	
	int key;
public:
	HashTable();
	virtual ~HashTable();
	int hashFunc(string);
	void addOneWord();
	void hienThiTatCa();
	void chinhSuaThongTinMotTu();
	void xoaMotTu();
	int timKiemMotTu(string tu);
	void xoaMotTuTrongFileText(Word* tmp);
	void hienThiChiTietMotTu(string tu);
	void loadFileIntoHashTable();
	void ghiDuLieuVaoFile(Word *tmp);
	void themMotTu(Word*);
	int getRanDom();
	int getSize();
	string hamRamdomTuTrongBangBam();
	char hamRanDomTrongKiTu();
	int nhapKiTuConThieu();
	void trochoi();

};
