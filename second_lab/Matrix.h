/* ¬ариант 2. ћатрицы
 ласс матриц вещественных чисел произвольного размера.
 ак минимум, предоставить:
Х конструктор с параметрами : размеры матрицы и значение дл€ заполнени€;**
Х оператор() дл€ чтени€ / записи элемента матрицы по указанным индексам;
Х операторы сложени€ и вычитани€ матриц;
Х оператор умножени€ матриц;
Х оператор умножени€ матрицы на скал€р(обеспечить коммутативность);
Х оператор делени€ матрицы на скал€р;
Х вычисление следа матрицы.
«јƒј„ј : ѕривести заданную квадратную матрицу ј к нижнетреугольному виду. */
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

