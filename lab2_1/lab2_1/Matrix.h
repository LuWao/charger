#include "stdafx.h"
#include <iostream>
using namespace std;

class Matrix
{
public:
	int m, n, **mass;
	Matrix ();
	Matrix (int a, int b);
	Matrix (const Matrix &o);		//конструктор копирования
	~Matrix ();
	int* operator [] (int i) {return mass[i];}


	bool operator==(const Matrix &o1) {
		if((this -> m == o1.m) && (this -> n ==o1.n)) {
			for (int i = 0; i < this -> m; i++)
			{
				for (int j = 0; j < this -> n; j++)
				{
					if(this -> mass[i][j] != o1.mass[i][j]) return false;
				}
			}
			return true;
		} else return false;
	}

	bool operator!=(const Matrix &o1) {
		if(*this == o1) return false;
		else return true;
	}

	friend ostream& operator << (ostream& ot, const Matrix& o1);
	Matrix& operator =(const Matrix &o1);
	Matrix operator +(const Matrix &o1);
	Matrix operator -(const Matrix &o1);
	Matrix operator *(const Matrix &o1);
	Matrix operator *(int a);
	Matrix operator +=(const Matrix &o1);
	Matrix operator -=(const Matrix &o1);
	Matrix operator *=(const Matrix &o1);
	Matrix operator *=(int a);
};