#include "Word.h"
#include<iostream>
using namespace std;

Word::Word()
{
	tu = "";
	loai = "";
	nghia = "";
	viDu = "";
}

Word::~Word()
{
}
Word::Word(const Word&w)
{
	this->tu = w.tu;
	this->loai = w.loai;
	this->nghia = w.nghia;
	this->viDu = w.viDu;
}
string Word::getTu()
{
	return tu;
}
string Word::getNghia()
{
	return nghia;
}
string Word::getLoai()
{
	return this->loai;
}
string Word::getViDu()
{
	return viDu;
}
void Word::setTu(string tu)
{
	this->tu = tu;
}
void Word::setLoai(string loai)
{
	this->loai = loai;

}
void Word::setNghia(string nghia)
{
	this->nghia = nghia;
}
void Word::setVidu(string viDu)
{
	this->viDu = viDu;
}
istream& operator>>(istream &i, Word &w)
{
	cout << "Nhap tu ";
	i.ignore();
	getline(i, w.tu);
	cout << "Nhap loai tu ";
	i.ignore();
	getline(i, w.loai);
	cout << "Nhap nghia cua tu  ";
	i.ignore();
	getline(i, w.nghia);
	cout << "Nhap vi du cua tu  ";
	i.ignore();
	getline(i, w.viDu);
	return i;
}
ostream& operator<<(ostream& o, const Word &w)
{
	o << w.tu << "\t" << w.loai << "\t" << w.nghia << "\t" << w.viDu << endl;
	return o;
}