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

int vvod()                                                       //������� ���������� �������
{
	int j;
	m = 1;
	cout << "������� ������ �������\n";
	cin >> n;
	a = new float[n];
	cout << "������� '1', ���� ������ ��������� ������ ���� ��� '2' � ��������� ������\n";
	cin >> j;
	while ((j!=1)&&(j!=2))
	{
		cout << "������� ������������ ��������! ���������� �����\n";
		cin >> j;
	} 
	if (j == 1)
	{
		cout << "������� �������� ��������� �������\n";
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];                                         //���������� ������� �������������
			sr += a[i];
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			a[i]=(rand()%1000+1)/float(rand()%100+1);            //���������� ������� ���������� �������
			sr += a[i];
		}
	}
	cout << "������\n";
	return 0;
}

int obrab()                                                      //������� ��������� �������
{
	if (m == 0) cout << "������! ������� ������� �������� �������\n";
	else
	{
		fl = 1;
		ch = sr / n;                                             //���������� �������� �������� � �������
		min = fabs(ch - a[1]);
		nom = 1;
		for (int i=0; i<n; i++)
			if (fabs(ch - a[i]) < min)
			{
				min = fabs(ch - a[i]);
				nom = i + 1;
			}
		cout << "������\n";
	}
	return 0;
}

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
			    case 1: vvod(); break;
			    case 2: obrab(); break;
			    case 3: vyvod(); break;
				case 4: if (fl == 0) { cout << "������! ��������� ������ ������������ ��������\n"; break; }
						else
				        {
					        cout << nom << "\n"; break;
				        }
			    case 5: system("cls"); menu(); break;
			}
		}
	} while (f != 0);
	delete [] a;
    return 0;
}

