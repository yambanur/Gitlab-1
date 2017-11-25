// VLab2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <math.h>
#include <iomanip>

using namespace std;

int fl=0,m=0, n, nom;
float sr, *a = NULL, ch, min;

int vvod()                                                       //функция заполнения массива
{
	int j;
	m = 1;
	cout << "Введите размер массива\n";
	cin >> n;
	a = new float[n];
	cout << "Нажмите '1', если хотите заполнить массив сами или '2' в противном случае\n";
	cin >> j;
	while ((j!=1)&&(j!=2))
	{
		cout << "Выбрана некорректная операция! Попробуйте снова\n";
		cin >> j;
	} 
	if (j == 1)
	{
		cout << "Введите значения элементов массива\n";
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];                                         //заполнение массива пользователем
			sr += a[i];
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			a[i]=(rand()%1000+1)/float(rand()%100+1);            //заполнение массива случайными числами
			sr += a[i];
		}
	}
	cout << "Готово\n";
	return 0;
}

int obrab()                                                      //функция обработки массива
{
	if (m == 0) cout << "Ошибка! Сначала задайте значение массива\n";
	else
	{
		fl = 1;
		ch = sr / n;                                             //вычисление среднего значения в массиве
		min = fabs(ch - a[1]);
		nom = 1;
		for (int i=0; i<n; i++)
			if (fabs(ch - a[i]) < min)
			{
				min = fabs(ch - a[i]);
				nom = i + 1;
			}
		cout << "Готово\n";
	}
	return 0;
}

int vyvod()                                                     //вывод массива на экран
{
	if (m == 0) cout << "Ошибка! Сначала задайте значение массива\n";
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
	cout << "Меню:\nВвод элементов массива - 1\nРасчет контрольного значения - 2\nВывод массива на экран - 3\n";
	cout << "Вывод контрольного значения - 4\nОчистка экрана консоли - 5\nВыход - 0\nЧего изволите?\n";
	return 0;
}

int main()                                                      //тело программы
{
	setlocale(LC_ALL, "Rus");
	int j = 0, f = 0;
	menu();
	do
	{
		cin >> f;
		if ((f>5)||(f<0)) cout << "Выбрана некорректная операция! Попробуйте снова\n";
		else
		{
			switch (f)                                         //обработка команд пользователя
			{
			    case 1: vvod(); break;
			    case 2: obrab(); break;
			    case 3: vyvod(); break;
				case 4: if (fl == 0) { cout << "Ошибка! Выполните расчет контрольного значения\n"; break; }
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

