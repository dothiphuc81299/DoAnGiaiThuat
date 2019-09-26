#pragma once
#include<string>
#include<iostream>
using namespace std;
struct Word
{
private:
	string tu, loai, nghia, phienAm;
	//struct Word* next;
public:
	string getTu() {
	return tu;
	}
	string getLoai()
	{
		return loai;
	}
	string getNghia()
	{
	return nghia;
	}
	string getPhienAm() {
		return phienAm;
	}
	void NhapTu() {
		std::cout << " Nhap tu moi : ";
		cin >> tu;
		cout << "\n Nhap loai  tu:  ";
		cin >> loai;
		cout << " \nNhap nghia cua tu : ";
		cin >> nghia;
		cout << " \nNhap phien am cua tu : ";
		cin >> phienAm;
	}
};


