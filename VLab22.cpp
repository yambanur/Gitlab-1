// VLab2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <math.h>
#include <iomanip>

using namespace std;

int fl=0,m=0, n, nom;
float sr, *a = NULL, ch, min;

int vyvod()                                                     //����� ������� �� �����
{
	if (m == 0) cout << "������! ������� ������� �������� �������\n";
	else
	{
		for (int i = 0; i < n; i++)
			cout << setprecision (3) << a[i] << " ";
		cout << "\n";
	}
	return 0;
}

int menu()
{
	cout << "����:\n���� ��������� ������� - 1\n������ ������������ �������� - 2\n����� ������� �� ����� - 3\n";
	cout << "����� ������������ �������� - 4\n������� ������ ������� - 5\n����� - 0\n���� ��������?\n";
	return 0;
}

int main()                                                      //���� ���������
{
	setlocale(LC_ALL, "Rus");
	int j = 0, f = 0;
	menu();
	do
	{
		cin >> f;
		if ((f>5)||(f<0)) cout << "������� ������������ ��������! ���������� �����\n";
		else
		{
			switch (f)                                         //��������� ������ ������������
			{
			    case 1: 
				j = 0;
				m = 1;
				cout << "������� ������ �������\n";
				cin >> n;
				a = new float[n];
				cout << "������� �������� ��������� �������\n";
				for (int i = 0; i < n; i++)
				{
					cin >> a[i];                                         //���������� ������� �������������
					sr += a[i];
				}
				cout << "������\n";
				break;
			    case 2: break;
			    case 3: vyvod(); break;
			    case 4: break;
			    case 5: system("cls"); menu(); break;
			}
		}
	} while (f != 0);
    return 0;
}

