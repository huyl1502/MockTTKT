#include "Matrix.h"

Matrix::Matrix()
{
	int i, j;
	/*cout << "Nhap so hang : "; cin >> rows;
	cout << "Nhap so cot : "; cin >> cols;
	if (!(checkInput(rows) && checkInput(cols))) exit(0);*/

	value = new int *[rows];
	for (i = 0; i < rows; i++)
		value[i] = new int[cols];
	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++)
		{
			cout << "v[" << i << j << "]: ";
			cin >> value[i][j];
		}
}
Matrix::Matrix(short r, short c)
{
	rows = r; cols = c;
	value = new int *[rows];
	for (int i = 0; i < rows; i++)
		value[i] = new int[cols];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			value[i][j] = NULL;
		}
}
Matrix::Matrix(Matrix &a)
{
	rows = a.rows; cols = a.cols;
	value = new int *[rows];
	for (int i = 0; i < rows; i++)
		value[i] = new int[cols];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			value[i][j] = a.value[i][j];
}
Matrix::~Matrix()
{
	for (int i = 0; i < rows; i++)
		delete value[i];
	delete value;
}
short Matrix::getValue(short i, short j) {
	if (check(i, j)) {
		return value[i][j];
	}
	else {
		return -1; // loi truy cap ngoai ma tran da khoi tao
	}
}
void Matrix::copy(Matrix a) {
	for (int i = 0; i < a.rows; i++)
		for (int j = 0; j < a.cols; j++)
			value[i][j] = a.value[i][j];
}
void Matrix::add(short i, short j, short v) {
	if (check(i,j)) {
		value[i][j] = v;
	}
}
void Matrix::display()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << value[i][j] << "\t";
		cout << endl;
	}
}

Matrix operator + (Matrix a, Matrix b)
{
	short i, j;
	Matrix c = a;
	for (i = 0; i < a.rows; i++)
		for (j = 0; j < a.cols; j++)
			c.value[i][j] = a.value[i][j] + b.value[i][j];
	return c;
}

