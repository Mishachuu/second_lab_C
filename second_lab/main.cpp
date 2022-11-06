
#include "Exteption.h"
#include "Matrix.h"
#include <conio.h>
#include <string>
#include <iostream>
#include <ostream>
#include <iomanip>
using namespace std;
/* Вариант 2. Матрицы
Класс матриц вещественных чисел произвольного размера.
Как минимум, предоставить:
• конструктор с параметрами : размеры матрицы и значение для заполнения;
• оператор() для чтения / записи элемента матрицы по указанным индексам;
• операторы сложения и вычитания матриц;
• оператор умножения матриц;
• оператор умножения матрицы на скаляр(обеспечить коммутативность);
• оператор деления матрицы на скаляр;
• вычисление следа матрицы.
ЗАДАЧА : Привести заданную квадратную матрицу А к нижнетреугольному виду. */
int GetKey()
{
	int key = _getch();
	if ((key == 0) || (key == 224))
		key = _getch();
	return key;
}


int Menu1()
{
	cout << endl << ("\nЗапустить программу - Enter\nВыход - Esc\n") << endl;
	while (true)
	{
		int key = GetKey();
		if ((key == 27) || (key == 13)) return key;
	}
}


int Menu2()
{
	cout << "\nЧто вы хотите сделать?\n\n"
		"1 - выполнить сложение матриц\n"
		"2 - выполнить вычитание матриц\n"
		"3 - выполнить умножение матрицы на матрицу\n"
		"4 - выполнить умножение матрицы на скаляр\n"
		"5 - выполнить деление матрицы на скаляр\n"
		"6 - вычислить след квадратной матрицы\n"
		"7 - преобразовать квадратную матрицу к нижнетреугольному виду\n\n"
		"Выход: Esc\n";


	while (true)
	{
		int key = GetKey();
		if ((key == 27) || (key > '0' && key <= '7'))
			return key;
	}
}


int menu3() {
	cout << "\nЧто вы хотите сделать со значениями матрицы A?\n\n"
		"1 - изменить значения\n"
		"2 - оставить эти\n"
		"Выход: Esc\n";
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
	cout << "Введите значения\n";
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
			cout << "Ошибка! Повторите ввод значения\n";
		}
		if (number <= 0) cout << "Ошибка! Повторите ввод значения\n";

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
		cout << "Введите размеры матрицы А (число столбцов и строк) а так же число для заполнения:";
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
		cout << "Введите размеры матрицы B (число столбцов и строк):";
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
				cout << "Результат сложения матриц:\n";
				try {
					C = A + B;
					cout << C;
				}
				catch (Exteption& er) { er.Print(); }
				break;
			case 50:
				system("cls");
				cout << "Результат вычитания матриц:\n";
				try {
					C = A - B;
					cout << C;
				}
				catch (Exteption& er) { er.Print(); }
				break;
			case 51:
				system("cls");
				cout << "Результат умножения матриц:\n";
				try {
					C = A * B;
					cout << C;
				}
				catch (Exteption& er) { er.Print(); }
				break;
			case 52:
				cout << "Введите скаляр:";
				cin >> scal;
				system("cls");
				cout << "Результат умножение матрицы на скаляр:\n";
				try {
					C = A * scal;
					cout << C;
				}
				catch (Exteption& er) { er.Print(); }
				break;
			case 53:
				system("cls");
				cout << "Результат деления матрицы на скаляр:\n";
				cout << "Введите скаляр:";
				cin >> scal;
				try {
					C = A / scal;
					cout << C;
				}
				catch (Exteption& er) { er.Print(); }
				break;
			case 54:
				system("cls");
				cout << "Результат вычисления следа матрицы:\n";
				try {
					cout << A.Trace();
				}
				catch (Exteption& er) { er.Print(); }
				break;
			case 55:
				system("cls");
				try {
					cout << "Результат преобразования матрицы к нижнетреугольному виду:\n";
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
	cout << "\nКакой тип данных вы хотите использовать?"
		"1 - int"
		"2 - float"
		"3 - double"
		"4 - complex(float)"
		"5 - complex(double)"
		"Выход: Esc\n";
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