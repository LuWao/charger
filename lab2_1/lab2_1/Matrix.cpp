#include "stdafx.h"
#include "Matrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix()
{
	m = n = 1;
	mass = new int*[1];
	mass[0] = new int [1];
}

Matrix::Matrix(int a, int o1) {
	m = a;
	n = o1;

	mass = new int*[m];
	for(int i = 0; i < m; i++)
	{
		mass[i] = new int [n];
	}
}

Matrix::Matrix(const Matrix &o) {//конструктор(копирует оттуда-то по ссылке)
	m = o.m;
	n = o.n;

	mass = new int*[o.m];
	for (int i = 0; i < o.m; i++)
	{
		mass[i] = new int [o.n];
	}

	for (int i = 0; i < o.m; i++)
	{
		for (int j = 0; j < o.n; j++)
		{
			mass[i][j] = o.mass[i][j];
		}
	}
}

Matrix::~Matrix()
{
	for(int i = 0; i < n; i++)
	{
		delete[] mass[i];
	}
	delete[] mass;
	cout << " *Object is crash!* ";
}

ostream& operator << (ostream& ot, const Matrix& o1) {
	for (int i = 0; i < o1.m; i++)
	{
		ot << "\n";
		for (int j = 0; j < o1.n; j++)
		{
			ot << o1.mass[i][j] <<" ";
		}
	}
	return ot;
}

Matrix& Matrix::operator =(const Matrix &o1) {
	if(&o1 != this)
	{
		this -> ~Matrix();			//очищаю заполненную в объекте пам€ть
		new (this) Matrix(o1);		//левый операнд заполн€етс€ заново данными правого операнда
		cout << "no error";
	} return *this;
}

Matrix Matrix::operator +(const Matrix &o1) {
	if ((o1.m == this -> m) && (o1.n == this -> n)) {
		//Matrix add = Matrix(o1.m, o1.n);
		for (int i = 0; i < o1.m; i++)
		{
			for (int j = 0; j < o1.n; j++)
			{
				mass[i][j] = o1.mass[i][j] + mass[i][j];
			}
		}
	} else cout << "Failed of addition! Cause: imcompatibility of matrix or other...";
	return *this;
}

Matrix Matrix::operator -(const Matrix &o1) {
	if ((o1.m == this -> m) && (o1.n == this -> n)) {
		//Matrix dic = Matrix(o1.m, o1.n);
		for (int i = 0; i < o1.m; i++)
		{
			for (int j = 0; j < o1.n; j++)
			{
				mass[i][j] = mass[i][j] - o1.mass[i][j];
			}
		}
	} else cout << "Failed of subtraction! Cause: imcompatibility of matrix or other...";
	return *this;

}

Matrix Matrix::operator *(const Matrix &o1) {
	if (o1.n == this -> m) {
		Matrix R = Matrix(this -> m, o1.n);
		for (int i = 0; i < this -> m; i++) {
			for (int j = 0; j < o1.n; j++) {
				R.mass[i][j] = 0; 
				for (int k = 0; k < this -> n; k++) {
					R.mass[i][j] = R.mass[i][j] + this -> mass[i][k]*o1.mass[k][j];
				}
			}
		}
		return R;
	}
	else cout << "Failed of multiplication! Cause: imcompatibility of matrix or other...";
}

Matrix Matrix::operator *(int a)
{
	int temp = a;
	//Matrix mul = Matrix(this -> m, this -> n);
	for (int i = 0; i < this -> m; i++)
	{
		for (int j = 0; j < this -> n; j++)
		{
			mass[i][j] = mass[i][j] * temp;
		}
	}
	return *this;
}

Matrix Matrix::operator+=(const Matrix &o1) {
	return *this + o1;
}

Matrix Matrix::operator-=(const Matrix &o1) {
	return *this - o1;
}

Matrix Matrix::operator*=(const Matrix &o1) {
	return *this * o1;
}

Matrix Matrix::operator*=(int a) {
	return *this * a;
}

