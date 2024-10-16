#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include "labs.h"

using namespace std;

void task3_1()
{
	cout << "3.1" << endl;

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
	cout << "3.2" << endl;
	int n;
	int factorial = 1;
	double power = 1;
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

void task3_3()
{
	cout << "3.3" << endl;
	int n;
	double power = 1;
	double sum = 0;
	double subsum = 0;
	cout << "N = ";
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		subsum += 1.0 / i;
		power *= 2;
		sum += power / subsum;
	}

	cout << "Сумма: " << sum << endl;
}

void task3_4()
{
	cout << "3.4" << endl;
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
	cout << "3.5" << endl;
	int n;
	int factorial = 1;
	double prod = 1;
	cout << "N = ";
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		factorial *= i;
		prod *= 0.5 * (i + 1) * i / factorial;
	}

	cout << "Произведение: " << prod << endl;
}

void task3_6()
{
	cout << "3.6" << endl;
	int n;
	int factorial = 1;
	double prod = 1;
	double power = 1;
	cout << "N = ";
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		power *= 2;
		factorial *= i;
		prod *= (power + 0.5 * (i + 1) * i / factorial);
	}

	cout << "Произведение: " << prod << endl;
}

void task3_7()
{
	cout << "3.7" << endl;
	int n;
	double result = 0;
	cout << "N = ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		result = sqrt(result + 1);
	}

	cout << "Результат: " << result << endl;
}

void task3_9()
{
	cout << "3.9" << endl;
	int n;
	double result = 0;
	cout << "N = ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		result = sqrt(result + i);
	}

	cout << "Результат: " << result << endl;
}

void task3_10()
{
	cout << "3.10" << endl;
	int n;
	double result = 0;
	cout << "N = ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		result = sqrt(result + 3 * i);
	}
	

	cout << "Результат: " << result << endl;
}

void task3_12()
{
	cout << "3.12" << endl;
	int n;
	double x;

	cout << "n = ";
	cin >> n;
	cout << "x = ";
	cin >> x;
	
	double power = x;

	int imax = 1; 
	int imin = 1;
	
	double max = sin(power);
	double min = sin(power);

	for (int i = 2; i <= n; i++)
	{
		power *= x;
		double current = i * sin(power);
		if (current > max)
		{
			imax = i;
			max = current;
		}
		if (current < min)
		{
			imin = i;
			min = current;
		}
	}

	cout << "Max: " << max << "\t (" << imax << ")" << endl;
	cout << "Min: " << min << "\t (" << imin << ")" << endl;
}

void task3_14()
{
	cout << "3.14" << endl;
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
	cout << "3.16" << endl;
	int m, n;
	int count = 0;

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
	}

	cout << "Результат: " << count << endl;
}

void task3_17()
{
	cout << "3.17" << endl;
	double r;
	int count = 0;

	cout << "R = ";
	cin >> r;

	if (r < 0)
	{
		cout << "Неправльные данные!" << endl;
		return;
	}

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
	cout << "3.18" << endl;
	double r1, r2;
	int count = 0;
	
	cout << "R1 = ";
	cin >> r1;
	cout << "R2 = ";
	cin >> r2;

	if (r1 < 0 || r2 < 0)
	{
		cout << "Неправльные данные!" << endl;
		return;
	}

	for (int i = -max(r1,r2); i <= max(r1, r2); i++)
	{
		for (int j = -max(r1, r2); j <= max(r1, r2); j++)
		{
			if (i * i + j * j <= max(r1, r2) * max(r1, r2) && i * i + j * j >= min(r1, r2) * min(r1, r2))
			{
				count++;
			}
		}
	}

	cout << "Кол-во точек, попавших в окружность: " << count << endl;
}

void task3_20()
{
	cout << "3.20" << endl;
	int m, n;
	
	cout << "N = ";
	cin >> n;
	cout << "M = ";
	cin >> m;

	if (m < n || m > 1000 || n > 1000)
	{
		cout << "Неправльные данные!" << endl;
		return;
	}

	for (int i = n; i <= m; i++)
	{
		int count = 0;
		for (int j = 1; j <= i; j++)
		{
			if (i % j == 0)
			{
				count++;
			}
		}

		if (count == 2)
		{
			cout << i << endl;
		}

	}
}

void third()
{
	//task3_1();
	//task3_2();
	//task3_3();
	//task3_4();
	//task3_5();

	// ---

	//task3_6();
	//task3_7();
	//task3_9();
	//task3_10();
	//task3_12();

	// ---

	//task3_14();
	//task3_16();
	//task3_17();
	//task3_18();
	task3_20();
}