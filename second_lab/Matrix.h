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
#include <complex>
template <typename T>
class Matrix {
private:
	int n = 0;
	int m = 0;
	T** M = NULL;
public:
	Matrix<T>();
	Matrix<T>(int m_, int n_);
	Matrix<T>(int m_, int n_, T value);
	Matrix<T>(const Matrix& M_);
	void Print();
	int GetM();
	int GetN();
	T& operator ()(int i, int j);
	Matrix& operator ()(int i, int j, T value);
	Matrix<T> operator + (const Matrix<T>& B);
	Matrix<T> operator - (const Matrix<T>& B);
	Matrix<T> operator * (const Matrix<T>& B);
	Matrix<T> operator * (const T a);
	Matrix<T> operator / (const T a);
	T Trace();
	Matrix<T> Triangular();
	void Transpose();
	friend std::ostream& operator << (std::ostream& s, const Matrix<T>& matrix);
};

