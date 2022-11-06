
#include "Exteption.h"
#include "Matrix.h"
#include <conio.h>
#include <string>
#include <iostream>
#include <ostream>
#include <iomanip>
using namespace std;
/* ������� 2. �������
����� ������ ������������ ����� ������������� �������.
��� �������, ������������:
� ����������� � ����������� : ������� ������� � �������� ��� ����������;
� ��������() ��� ������ / ������ �������� ������� �� ��������� ��������;
� ��������� �������� � ��������� ������;
� �������� ��������� ������;
� �������� ��������� ������� �� ������(���������� ���������������);
� �������� ������� ������� �� ������;
� ���������� ����� �������.
������ : �������� �������� ���������� ������� � � ����������������� ����. */
int GetKey()
{
	int key = _getch();
	if ((key == 0) || (key == 224))
		key = _getch();
	return key;
}


int Menu1()
{
	cout << endl << ("\n��������� ��������� - Enter\n����� - Esc\n") << endl;
	while (true)
	{
		int key = GetKey();
		if ((key == 27) || (key == 13)) return key;
	}
}


int Menu2()
{
	cout << "\n��� �� ������ �������?\n\n"
		"1 - ��������� �������� ������\n"
		"2 - ��������� ��������� ������\n"
		"3 - ��������� ��������� ������� �� �������\n"
		"4 - ��������� ��������� ������� �� ������\n"
		"5 - ��������� ������� ������� �� ������\n"
		"6 - ��������� ���� ���������� �������\n"
		"7 - ������������� ���������� ������� � ����������������� ����\n\n"
		"�����: Esc\n";


	while (true)
	{
		int key = GetKey();
		if ((key == 27) || (key > '0' && key <= '7'))
			return key;
	}
}


int menu3() {
	cout << "\n��� �� ������ ������� �� ���������� ������� A?\n\n"
		"1 - �������� ��������\n"
		"2 - �������� ���\n"
		"�����: Esc\n";
	while (true)
	{
		int key = GetKey();
		if ((key == 27) || (key > '0' && key <= '2'))
			return key;
	}
}



template <typename T>
void SetData(Matrix<T>& Mass, int m, int n) {
	double value;
	cout << "������� ��������\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "[" << i << "][" << j << "]:";
			cin >> value;
			Mass(i, j, value);
		}
	}
}


int IntCheck()
{
	int number = 0;
	while (number <= 0)
	{
		while (!(cin >> number) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "������! ��������� ���� ��������\n";
		}
		if (number <= 0) cout << "������! ��������� ���� ��������\n";

	}

	return number;
}

template <typename T>
void RandValue(Matrix<T>& Mass, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			Mass(i, j, rand() % 9);
		}
	}
}

template <typename T>void menu4() {
	Matrix<T> C, B;
	setlocale(LC_ALL, "");
	int column, row;
	while (true) {
		system("cls");
		cout << "������� ������� ������� � (����� �������� � �����) � ��� �� ����� ��� ����������:";
		column = IntCheck();
		row = IntCheck();
		T value = IntCheck();
		Matrix<T> A(column, row, value);
		while (true) {
			system("cls");
			cout << "A:\n" << A << endl;
			int m3 = menu3();
			if (m3 == 27) break;
			switch (m3)
			{
			case 49:
				SetData(A, column, row);
			case 50:
				break;
			}
			break;
		}
		cout << "������� ������� ������� B (����� �������� � �����):";
		cin >> column >> row;
		Matrix<T> B(column, row);
		RandValue(B, column, row);
		cout << "A:\n" << A << endl;
		cout << "B:\n" << B << endl;
		int m1 = Menu1();
		if (m1 == 27) break;
		while (true) {
			int m2 = Menu2();
			if (m2 == 27) break;
			int scal;
			switch (m2)
			{
			case 49:
				system("cls");
				cout << "��������� �������� ������:\n";
				try {
					C = A + B;
					cout << C;
				}
				catch (Exteption& er) { er.Print(); }
				break;
			case 50:
				system("cls");
				cout << "��������� ��������� ������:\n";
				try {
					C = A - B;
					cout << C;
				}
				catch (Exteption& er) { er.Print(); }
				break;
			case 51:
				system("cls");
				cout << "��������� ��������� ������:\n";
				try {
					C = A * B;
					cout << C;
				}
				catch (Exteption& er) { er.Print(); }
				break;
			case 52:
				cout << "������� ������:";
				cin >> scal;
				system("cls");
				cout << "��������� ��������� ������� �� ������:\n";
				try {
					C = A * scal;
					cout << C;
				}
				catch (Exteption& er) { er.Print(); }
				break;
			case 53:
				system("cls");
				cout << "��������� ������� ������� �� ������:\n";
				cout << "������� ������:";
				cin >> scal;
				try {
					C = A / scal;
					cout << C;
				}
				catch (Exteption& er) { er.Print(); }
				break;
			case 54:
				system("cls");
				cout << "��������� ���������� ����� �������:\n";
				try {
					cout << A.Trace();
				}
				catch (Exteption& er) { er.Print(); }
				break;
			case 55:
				system("cls");
				try {
					cout << "��������� �������������� ������� � ����������������� ����:\n";
					C = A.Triangular();
					C.Transpose();
					cout << C;
				}
				catch (Exteption& er) { er.Print(); }
				break;
			}
		}
	}
	return 0;
}
int main() {
	cout << "\n����� ��� ������ �� ������ ������������?"
		"1 - int"
		"2 - float"
		"3 - double"
		"4 - complex(float)"
		"5 - complex(double)"
		"�����: Esc\n";
	while (true)
	{
		int type = GetKey();
		switch (type)
		{
		case 49:
			menu4<int>();
			break;
		case 50:
			menu4<float>();
			break;
		case 51:
			menu4<double>();
			break;
		case 52:
			menu4<complex<float>>();
			break;
		case 53:
			menu4<complex<double>>();
			break;
		}
		
	}
	return 0;
}