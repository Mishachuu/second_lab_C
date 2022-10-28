/* ������� 2. �������
����� ������ ������������ ����� ������������� �������.
��� �������, ������������:
� ����������� � ����������� : ������� ������� � �������� ��� ����������;**
� ��������() ��� ������ / ������ �������� ������� �� ��������� ��������;
� ��������� �������� � ��������� ������;
� �������� ��������� ������;
� �������� ��������� ������� �� ������(���������� ���������������);
� �������� ������� ������� �� ������;
� ���������� ����� �������.
������ : �������� �������� ���������� ������� � � ����������������� ����. */
#include <iostream>
template <typename T>
class Matrix {
private:
	int n = 0;
	int m = 0;
	T** M = NULL;
public:
	Matrix();
	Matrix(int m_, int n_);
	Matrix(int m_, int n_, T value);
	Matrix(const Matrix& M_);
	void Print();
	int GetM();
	int GetN();
	T& operator ()(int i, int j);
	Matrix& operator ()(int i, int j, T value);
	Matrix operator + (const Matrix& B);
	Matrix operator - (const Matrix& B);
	Matrix operator * (const Matrix& B);
	Matrix operator * (const T a);
	Matrix operator / (const T a);
	double Trace();
	Matrix Triangular();
	void Transpose();
	friend std::ostream& operator << (std::ostream& s, const Matrix& matrix);
};

