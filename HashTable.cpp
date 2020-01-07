#include "HashTable.h"
#include"singlyLinkedList.h"
#include"Word.h"
#include"Node.h"
#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
using namespace std;
int HashTable::size = 0;
void loadFileIntoHashTable();
void addOneWord();
void chinhSuaThongTinMotTu();
HashTable::HashTable()
{
	list = new singlyLinkedList<Word *>[180];
}

HashTable::~HashTable()
{
	if (list != NULL)
		delete[] list;
}
int HashTable::hashFunc(string tu)
{
	int index = (int)tu[0];
	int t = tu.length();

	for (int i = 0; i < t; i++)
	{
		index += (int)tu[i];
	}
	return index % 167;
}
void HashTable::hienThiTatCa()
{
	for (int i = 0; i < 180; i++) {
		if (list[i].getSize() > 0) {
			list[i].printAllPointerNode();
		}
	}
}
void HashTable::themMotTu(Word* word)
{
	size++;
	key = hashFunc(word->getTu());
	list[key].insertAtHead(word);
}

int HashTable::getSize()
{
	return size;
}
void HashTable::hienThiChiTietMotTu(string tu)
{

	key = hashFunc(tu);
	if (list[key].getSize() == 0)
	{
		cout << "Word does not exist";
	}
	else
	{

		Node<Word*> *tmp = list[key].getHeadNode();
		if ((tmp->data)->getTu() == tu)
		{
			cout << "Tu ban muon xem la : " << endl;
			cout << ((tmp->data)->getTu()) << "\t" << ((tmp->data)->getLoai()) << "\t" << ((tmp->data)->getNghia()) << "\t" << ((tmp->data)->getViDu()) << endl;
			return;
		}
		int i = 0;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
			i++;

			if ((tmp->data)->getTu() == tu)
			{
				cout << "Tu ban muon xem la : " << endl;
				cout << ((tmp->data)->getTu()) << "\t" << ((tmp->data)->getLoai()) << "\t" << ((tmp->data)->getNghia()) << "\t" << ((tmp->data)->getViDu()) << endl;
				return;
			}

		}
		cout << "Word does not exist" << endl;
	}
}


void HashTable::loadFileIntoHashTable()
{
	string line;
	ifstream inFile;
	inFile.open("text.txt");
	if (!inFile) {
		cout << "Unable to open file";
		exit(1); 
	}
	string tach;
	while (getline(inFile, line))
	{
		Word* tmp = new Word;


		string tach;
		int i = 0;

		while (line[i] != '@')
		{
			tach += line[i++];
		}
		tmp->setTu(tach);
		i++;

		tach = "";

		// Lay loai
		while (line[i] != '@') {
			tach += line[i++];
		}
		tmp->setLoai(tach);
		i++;

		tach = "";


		while (line[i] != '@') {
			tach += line[i++];
		}
		tmp->setNghia(tach);
		i++;

		tach = "";


		while (line[i] != '@') {
			tach += line[i++];
		}
		tmp->setVidu(tach);
		i++;

		{
			themMotTu(tmp);
		}

	}

	inFile.close();
	return;
}

void HashTable::ghiDuLieuVaoFile(Word *tmp)
{
	ofstream file;
	file.open("text.txt", ios_base::app);
	file << tmp->getTu() << "@";
	file << tmp->getLoai() << "@";
	file << tmp->getNghia() << "@";
	file << tmp->getViDu() << "@" << endl;
	file.close();
}
int HashTable::timKiemMotTu(string tu)
{
	int t = 0;
	key = hashFunc(tu);

	if (list[key].getSize() == 0)
	{

		t = 0;
	}

	else
	{
		Node<Word*> *tmp = list[key].getHeadNode();
		if ((tmp->data)->getTu() == tu)
		{
			//return false;
			t = 1;
		}
		int i = 0;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
			i++;

			if ((tmp->data)->getTu() == tu)
			{
				t = 1;
				break;
			}

		}
	}
	return t;
}




void HashTable::addOneWord() {
	Word *tmp = new Word;
	string tu;
	string loai;
	string nghia;
	string vidu;
	cin.ignore();
	cout << "Nhap tu ban muon them\t";
	getline(cin, tu);
	tmp->setTu(tu);
	if (timKiemMotTu(tu) == 0)
	{
		cin.ignore();
		cout << "Nhap loai\t";
		getline(cin, loai);

		tmp->setLoai(loai);
		cin.ignore();
		cout << "Nhap nghia\t";


		getline(cin, nghia);

		tmp->setNghia(nghia);
		cin.ignore();
		cout << "Nhap vi du\t";

		getline(cin, vidu);

		tmp->setVidu(vidu);
		themMotTu(tmp);
		cout << "Tu ban vua moi them la " << endl;
		cout << *tmp;
		ghiDuLieuVaoFile(tmp);
	}
	else {
		cout << "Tu ban vua moi them da co trong tu dien " << endl;
		hienThiChiTietMotTu(tu);

	}

}

void HashTable::xoaMotTuTrongFileText(Word *tmp)
{
	string line;
	ifstream file("text.txt");
	if (!file.is_open()) {
		cout << "Input file failed to open\n";
	}
	ofstream out("outfile.txt");
	while (getline(file, line))
	{
		string tach;
		int i = 0;
		while (line[i] != '@')
		{
			tach += line[i++];
		}
		string t = tmp->getTu();

		if (t != tach)
		{
			out << line << endl;
		}


	}
	file.close();
	out.close();
	remove("text.txt");
	rename("outfile.txt", "text.txt");
	return;

}

void HashTable::chinhSuaThongTinMotTu()
{
	Word *tmp = new Word;
	string tu;
	cout << " Nhap tu ban muon chinh sua ";
	cin >> tu;
	if (timKiemMotTu(tu) == 0)
	{
		cout << " Word does not exist" << endl;
	}
	else
	{
		Node<Word*> *tmp = list[key].getHeadNode();
		int choice;
		cout << "Tu muon chinh sua: ";
		cout << ((tmp->data)->getTu()) << "\t" << ((tmp->data)->getLoai()) << "\t" << ((tmp->data)->getNghia()) << "\t" << ((tmp->data)->getViDu()) << endl;
		cout << "\n\t1.Chinh sua tu " << endl;
		cout << "\t2.Chinh sua loai tu" << endl;
		cout << "\t3.Chinh sua nghia cua tu" << endl;
		cout << "\t4.Chinh sua vi du cua tu" << endl;
		cout << "\t0.Chinh sua tat ca " << endl;
		cout << "-------------------------" << endl;
		cout << " Nhap su lua chon cua ban \t";
		cin >> choice;
		
		xoaMotTuTrongFileText(tmp->data);
		string tu;
		string loai;
		string nghia;
		string vidu;
		switch (choice)
		{
		case 1:
			cin.ignore();
			cout << " Nhap tu moi \t";
			getline(cin, tu);
			(tmp->data)->setTu(tu);
			cout << "Tu sau khi chinh sua" << endl;
			cout << ((tmp->data)->getTu()) << "\t" << ((tmp->data)->getLoai()) << "\t" << ((tmp->data)->getNghia()) << "\t" << ((tmp->data)->getViDu()) << endl;
			ghiDuLieuVaoFile(tmp->data);
			break;
		case 2:
			cin.ignore();
			cout << " Nhap loai tu \t";
			getline(cin, loai);
			(tmp->data)->setLoai(loai);
			cout << "Tu sau khi chinh sua" << endl;
			cout << ((tmp->data)->getTu()) << "\t" << ((tmp->data)->getLoai()) << "\t" << ((tmp->data)->getNghia()) << "\t" << ((tmp->data)->getViDu()) << endl;
			ghiDuLieuVaoFile(tmp->data);
			break;
		case 3:
		{

			cin.ignore();
			cout << " Nhap nghia tu \t";
			getline(cin, nghia);
			(tmp->data)->setNghia(nghia);
			cout << "Tu sau khi chinh sua" << endl;
			cout << ((tmp->data)->getTu()) << "\t" << ((tmp->data)->getLoai()) << "\t" << ((tmp->data)->getNghia()) << "\t" << ((tmp->data)->getViDu()) << endl;
			ghiDuLieuVaoFile(tmp->data);
			break;
		}
		case 4:
		{
			cin.ignore();
			cout << " Nhap vi du tu \t";
			getline(cin, vidu);
			(tmp->data)->setVidu(vidu);
			cout << "Tu sau khi chinh sua" << endl;
			cout << ((tmp->data)->getTu()) << "\t" << ((tmp->data)->getLoai()) << "\t" << ((tmp->data)->getNghia()) << "\t" << ((tmp->data)->getViDu()) << endl;
			ghiDuLieuVaoFile(tmp->data);
			break;
		}
		default:
		{
			cin.ignore();
			cout << " Nhap tu moi \t";
			getline(cin, tu);
			(tmp->data)->setTu(tu);
			cin.ignore();
			cout << " Nhap loai tu \t";
			getline(cin, loai);
			(tmp->data)->setLoai(loai);
			cin.ignore();
			cout << " Nhap nghia tu \t";
			getline(cin, nghia);
			(tmp->data)->setNghia(nghia);
			cin.ignore();
			cout << " Nhap vi du tu \t";
			getline(cin, vidu);
			(tmp->data)->setVidu(vidu);
			cout << "\nTu sau khi chinh sua" << endl;
			cout << ((tmp->data)->getTu()) << "\t" << ((tmp->data)->getLoai()) << "\t" << ((tmp->data)->getNghia()) << "\t" << ((tmp->data)->getViDu()) << endl;
			ghiDuLieuVaoFile(tmp->data);
			break;
		}
		}

	}
}
void HashTable::xoaMotTu()
{
	cout << "Nhap tu ban muon xoa : \t";
	string tu;
	cin >> tu;
	key = hashFunc(tu);
	if (list[key].getSize() == 0)
	{
		cout << "Word does not exist" << endl;
	}
	else
	{
		Node<Word*> *tmp = list[key].getHeadNode();

		if ((tmp->data)->getTu() == tu)
		{

			xoaMotTuTrongFileText(tmp->data);

			list[key].remove(0);

			size--;
			cout << " Ban da xoa thanh cong " << endl << endl;
			return;

		}

		int i = 0;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;

			i++;

			if ((tmp->data)->getTu() == tu)
			{

				xoaMotTuTrongFileText(tmp->data);
				list[key].remove(i);
				size--;

				cout << " Ban da xoa thanh cong " << endl;
				return;
			}


		}
		cout << "Word does not exist" << endl;
	}
}

int HashTable::getRanDom()
{
	srand((int)time(0)); //Tạo số ngẫu nhiên thay đổi theo thời gian
	int t = int((rand() % 167)); //Tạo số ngẫu nhiên

	return t;
}
string HashTable::hamRamdomTuTrongBangBam()
{
	int t = getRanDom();
	string s = "";

	while (list[t].getSize() == 0)
	{
		t = getRanDom();
	}

	if (list[t].getSize() != 0)
	{
		Node<Word*> *tmp = list[t].getHeadNode();
		if (list[t].getSize() == 1)
		{
			s = tmp->data->getTu();

		}
		else
		{
			int x = list[t].getSize() - 1;
			int r = (int)rand() % x;
			for (int i = 0; i < x; i++)
			{
				if (i == r)
				{
					break;
				}
			}
			s = tmp->data->getTu();


		}



	}
	return s;



}
char HashTable::hamRanDomTrongKiTu()
{
	string s = hamRamdomTuTrongBangBam();
	int y = s.length() - 1;
	if (y == 0)
	{
		return s[0];
	}
	else
	{
		int rad = rand() % y;

		return (s[rad]);
	}

}


int HashTable::nhapKiTuConThieu()
{

	int diem = 0;
	char n;
	string t = "";
	string tu = hamRamdomTuTrongBangBam();
	t = tu;
	char x = hamRanDomTrongKiTu();
	char y = '_';
	int l = tu.length();
	int temp = 0;
	for (int i = 0; i < l; i++)
	{
		if (tu[i] == x)
		{
			tu[i] = y;
			cout << "Dien tu con thieu vao cho trong " << "\t";
			cout << tu;
			temp = i;
			break;
		}

	}
	cout << "\nKi tu ban nhap la : \t";
	cin >> n;
	for (int j = 0; j < l; j++)
	{
		if (j == temp)
		{
			tu[j] = n;
			break;
		}
	}
	if (timKiemMotTu(tu) == 1)
	{
		diem += 5;

		cout << "Tuyet voi. Ban da dien dung !!!" << endl << endl;
		hienThiChiTietMotTu(t);
	}
	else
	{
		cout << "Khong co tu nay trong tu dien " << endl;

	}
	return diem;


}



void HashTable::trochoi()
{
	int sum = 0;
	int choice = 1;
	while (choice != 0)
	{
		system("cls");
		cout << "\t\t\t ________________________________________________________________________" << endl;
		cout << "\t\t\t|\tBan co muon tiep tuc choi khong ?                                |" << endl;
		cout << "\t\t\t|\t1. YES                                                           |" << endl;
		cout << "\t\t\t|\t0. NO                                                            |" << endl;
		cout << "\t\t\t|________________________________________________________________________|" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{	int t = nhapKiTuConThieu();
		sum += t;
		cout << "Tong diem cua ban la \t" << sum << endl;
		system("pause");
		break;
		}
		case 0:
		{

			break;
		}

		}
	}

}