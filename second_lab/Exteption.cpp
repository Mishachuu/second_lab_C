#include <iostream>
#include "Exteption.h"
#include <locale.h>
using namespace std;


void EInvalidSize::Print() {
	cout << endl << "������:\n�������� �� ��������. ������� ������ �� ���������" << endl;
}


void EInvalidIndex::Print() {
	cout << endl << "������:\n�������� �� ��������. ��� �������� �������������� �� ���� �������� " << endl;
}

void EInvalidMull::Print() {
	cout << endl << "������:\n����� �������� ������� A �� ����� ����� ����� ������� B" << endl;
}


void EInvalidQuadrate::Print() {
	cout << endl << "������:\n������� �� ����������" << endl;
}


void EdivisionZero::Print() {
	cout << endl << "������:\n������� �� ����" << endl;
}