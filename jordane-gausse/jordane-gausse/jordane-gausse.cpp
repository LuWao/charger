// jordane-gausse.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	cout<<"Size of your quadrate matrix is ";
	int q;
	int k = 0, i_max;		//� - ������� ��� ������ ���������
	double max, my_p = 0;
	cin >> q;
	cout << "\n";

	double **matrix = new double*[q];		//�� ������ �������� �����! �������� �������
	for(int i = 0; i < q; i++)
		matrix[i] = new double[q*2+1];

	cout<<"Here you can write matrix: \n";
	for(int i = 0; i < q; i++)		//�������� ����� ������� � �������� �������� �������������
		for(int j = q; j < 2*q; j++)
			cin >> matrix[i][j];

	cout << "Please, put your vector of free number: \n";
	for(int i = 0; i < q; i++)		//�������� ������ �������� ��������� ������������� ���������
		for(int j = 2*q; j < 2*q+1; j++)
			cin>>matrix[i][j];
	cout << "Let's go!\n";

	for(int i = 0; i < q; i++)		//�������� ���������� ����� ��������� ��������
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
		for(int i = k; i < q; i++)		//��� �������� � ������� �������� �������, �� ������ ��� max, �� �
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

		if(i_max != k)		//���� �������� �� ���� �����, ������ ������ ������� �� ����
		{
			for(int j = 0; j < 2*q+1; j++)		//������ �� ����� ���� ������ � ����������
			{
				swap(matrix[k][j], matrix[i_max][j]);
			}
		}

		for(int j = 0; j < 2*q+1; j++)		//���� ������ � ���������� �� ��������
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

		for(int i = 0; i < q; i++)		//�������� �� �������� ������������ �������
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

