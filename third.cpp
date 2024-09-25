#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include "labs.h"

using namespace std;

void task3_1()
{
	int n;
	double sum = 0;
	cout << "N = ";
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		// seq = (i + 1) * i / 2 
		// sum += i / seq
		sum += 2.0 / (i + 1);
	}

	cout << "Сумма: " << sum << endl;
}

void task3_2()
{
	int n;
	int factorial = 1;
	int power = 1;
	double sum = 0;
	cout << "N = ";
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		factorial *= i;
		power *= 3;
		sum += power / factorial;
	}

	cout << "Сумма: " << sum << endl;
}

void task3_4()
{
	int n;
	int factorial = 1;
	double sum = 0;
	cout << "N = ";
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		factorial *= i;
		sum += 2.0 * factorial / ((i + 1) * i);
	}

	cout << "Сумма: " << sum << endl;
}

void task3_5()
{
	int n;
	int factorial = 1;
	double prod = 0;
	cout << "N = ";
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		factorial *= i;
		prod *= 0.5 * (i + 1) * i / factorial;
	}

	cout << "Произведение: " << prod << endl;
}

void task3_7()
{
	int n;
	int result = 0;
	double prod = 0;
	cout << "N = ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		result += sqrt(result + 1);
	}

	cout << "Результат: " << result << endl;
}

void task3_9()
{
	int n;
	int result = 0;
	double prod = 0;
	cout << "N = ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		result += sqrt(result + i);
	}

	cout << "Результат: " << result << endl;
}

void task3_10()
{
	int n;
	int result = 0;
	double prod = 0;
	cout << "N = ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		result += sqrt(result + 3 * i);
	}

	cout << "Результат: " << result << endl;
}

void task3_14()
{
	int n;
	int result = 0;
	int max = 0;
	cout << "N = ";
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int count = 0;
		for (int j = 1; j <= i; j++)
		{
			if (i % j == 0)
			{
				count++;
			}
		}
		if (count > max)
		{
			max = count;
			result = i;
		}
	}

	cout << "Число с максимальным кол-вом делителей: " << result << endl;
}

void task3_16()
{
	int m, n;
	int count;

	cout << "M = ";
	cin >> m;
	cout << "N = ";
	cin >> n;

	if (m > n || m < 1e5 || n >= 1e6)
	{
		cout << "Неправльные данные!" << endl;
		return;
	}

	for (int i = m; i <= n; i++)
	{
		int left = i / 1000;
		int right = i % 1000;

		int leftSum = left % 10 + (left / 10) % 10 + left / 100;
		int rightSum = right % 10 + (right / 10) % 10 + right / 100;

		if (rightSum == leftSum)
		{
			count++;
		}
		
		cout << "Результат: " << count << endl;
	}
}

void task3_17()
{
	int r;
	int count = 0;

	cout << "R = ";
	cin >> r;

	for (int i = -r; i <= r; i++)
	{
		for (int j = -r; j <= r; j++)
		{
			if (i * i + j * j <= r * r)
			{
				count++;
			}
		}
	}

	cout << "Кол-во точек, попавших в окружность: " << count << endl;
}


void task3_18()
{
	int r1, r2;
	int count = 0;
	
	cout << "(r1, r2): ";
	cin >> r1 >> r2;

	int rsq = r1 * r1 + r2 * r2;

	for (int i = - floor(r1); i <= r1; i++)
	{
		for (int j = -floor(r2); j <= r2; j++)
		{
			if (i * i + j * j <= rsq)
			{
				count++;
			}
		}
	}

	cout << "Кол-во точек, попавших в окружность: " << count << endl;
}

void third()
{
	task3_1();
	task3_2();
	task3_4();
	task3_5();
	task3_7();

	// ---
	
	task3_9();
	task3_10();
	task3_14();
	task3_16();
	task3_17();

	// ---

	task3_18();
}