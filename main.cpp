#include<iostream>
#include"Word.h"
#include"HashTable.h"
using namespace std;
void menuShow();
int main()
{
	menuShow();
	system("pause");
}
void menuShow()
{

	int choice;
	HashTable ht = HashTable();
	ht.loadFileIntoHashTable();
	while (true) {
		system("cls");
		cout << "\t\t\t------------------------CAI DAT TU DIEN BANG HASHTABLE----------------------" << endl;
		cout << "\t\t\t|\t1.Them tu vung                                                     |" << endl;
		cout << "\t\t\t|\t2.Hien thi chi tiet mot tu                                         |" << endl;
		cout << "\t\t\t|\t3.Sua thong tin chi tiet mot tu                                    |" << endl;
		cout << "\t\t\t|\t4.Xoa mot tu vung                                                  |" << endl;
		cout << "\t\t\t|\t5.Choi tro choi do chu                                             |" << endl;
		cout << "\t\t\t|\t0.Thoat khoi chuong trinh                                          |" << endl;
		cout << "\t\t\t|__________________________________________________________________________|" << endl;
		cout << "\t\t\t Chon chi muc ban quan tam" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: {
			ht.addOneWord();

			system("pause");
			break;
		}
		case 2: {
			string tu;
			cout << " Nhap tu ban muon xem ";
			cin >> tu;
			ht.hienThiChiTietMotTu(tu);
			system("pause");
			break;
		}
		case 3: {
			ht.chinhSuaThongTinMotTu();
			system("pause");
			break;
		}
		case 4: {
			ht.xoaMotTu();

			system("pause");
			break;
		}
		case 5:
		{
			ht.trochoi();
			system("pause");
			break;
		}
		case 0:
		{
			exit(0);
		}
		}
	}
}