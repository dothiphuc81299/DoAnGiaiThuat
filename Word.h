#pragma once
#include<iostream>
#include<string>
using namespace std;
class Word
{
private:
	string tu, loai, nghia, viDu;
public:
	Word();
	Word(const Word &w);
	virtual ~Word();
	string getTu();
	string getLoai();
	string getNghia();
	string getViDu();
	void setTu(string);
	void setNghia(string);
	void setLoai(string);
	void setVidu(string);
	friend ostream& operator<<(ostream&, const Word &w);
	friend istream& operator>>(istream&, Word &w);
};