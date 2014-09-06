// jordane-gausse.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	cout<<"Size of your quadrate matrix is ";
	int q;
	int k = 0, i_max;		//к - счЄтчик дл€ поиска максимума
	double max, my_p = 0;
	cin >> q;
	cout << "\n";

	double **matrix = new double*[q];		//не забыть очистить мусор! создание массива
	for(int i = 0; i < q; i++)
		matrix[i] = new double[q*2+1];

	cout<<"Here you can write matrix: \n";
	for(int i = 0; i < q; i++)		//заполн€ю часть массива с исходным вектором коэффициентов
		for(int j = q; j < 2*q; j++)
			cin >> matrix[i][j];

	cout << "Please, put your vector of free number: \n";
	for(int i = 0; i < q; i++)		//заполн€ю массив вектором свободных коэффициентов уравнений
		for(int j = 2*q; j < 2*q+1; j++)
			cin>>matrix[i][j];
	cout << "Let's go!\n";

	for(int i = 0; i < q; i++)		//заполн€ю оставшеес€ место единичной матрицей
	{
		for(int j = 0; j < q; j++)
		{
			if(i == j)
				matrix[i][j] = 1;
			else matrix[i][j] = 0;
		}
	}

	for(; k < q; k++)
	{
		max = INT_MIN;
		i_max = 0;
		for(int i = k; i < q; i++)		//ищу максимум в столбце исходной матрицы, не забыть сбр max, ув к
		{
			for(int j = q+k;;)
			{
				if(matrix[i][j] >= max)
				{
					i_max = i;
					max = matrix[i][j];
					cout<<max;
				}
				break;
			}
		}

		if(i_max != k)		//если максимум на своЄм месте, ничего мен€ть местами не надо
		{
			for(int j = 0; j < 2*q+1; j++)		//ставлю на самый верх строку с максимумом
			{
				swap(matrix[k][j], matrix[i_max][j]);
			}
		}

		for(int j = 0; j < 2*q+1; j++)		//делю строку с максимумом на максимум
			matrix[k][j] = matrix[k][j] / max;

		for(int i = 0; i < q; i++)
		{
			if(i != k)
			{
				my_p = matrix[i][q+k];
				for(int j = 0; j < 2*q+1; j++)
				{
					matrix[i][j] = matrix[i][j] - matrix[k][j]*my_p;
				}
			}
		}

		for(int i = 0; i < q; i++)		//проверка на верность заполненного массива
		{
			cout<<"\n";
			for(int j = 0; j < 2*q+1; j++)
				cout<<matrix[i][j]<<" ";
		}
	}

	delete [] matrix;
	system("pause");
	return 0;
}

