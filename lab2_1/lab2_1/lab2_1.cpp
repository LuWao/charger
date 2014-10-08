// lab2_1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Matrix.h"
#include <iostream>
using namespace std;

int main()
{
	Matrix a;
	Matrix b(2,2);
	Matrix c(3,3);


	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++) {b[i][j] = i+j;}

		cout << b;

		b *= 2;
		cout << b << a;

		b = a = b + b;
		//cout << a << b;
		if (a != b) cout << "Something wrong\n";
		else cout << "As expected\n";
		b += c;

		cout << a << endl
        << c << endl
        << b << endl;

		system("pause");
		return 0;
}

