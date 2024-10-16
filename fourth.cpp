#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include "labs.h"

using namespace std;

void task4_1()
{
	int a;
	cout << "a = ";
	cin >> a;
	int index = 1;

	int sum = 0;
	int k = 1;

	while (true)
	{
		sum += k;
		
		if (sum > a)
		{
			break;
		}

		k++;
		index++;
	}

	cout << "Номер слагаемого: " << index << endl;
}

void task4_2()
{
	int a;
	cout << "a = ";
	cin >> a;
	int index = 1;

	int factorial = 1;
	int sum = 0;
	int k = 1;

	while (true)
	{
		factorial *= k;
		sum += factorial;
		
		if (sum > a)
		{
			break;
		}

		k++;
		index++;
	}

	cout << "Номер слагаемого: " << index << endl;
}

void task4_3()
{
	int a;
	cout << "a = ";
	cin >> a;
	int index = 1;
	
	int power = 1;
	int sum = 0;

	while (true)
	{
		power *= 2;
		sum += power;

		if (sum > a)
		{
			break;
		}

		index++;
	}

	cout << "Номер слагаемого: " << index << endl;
}

void task4_4()
{
	int n;
	cout << "N = ";
	cin >> n;

	int count = 0;

	while (true)
	{
		if (n < 1)
		{
			break;
		}

		count += (n % 2 == 1) ? 1 : 0;
		n /= 2;
	}

	cout << "Кол-во единиц: " << count << endl;
}

void task4_5()
{
	int n;
	cout << "N = ";
	cin >> n;

	int k = 1;
	int factorial = 1;

	while (true)
	{
		if (factorial > n)
		{
			break;
		}

		k++;
		factorial *= k;
	}

	cout << "Максимальное число: " << k - 1 << endl;
}

void task4_6()
{
	int l = 1, r = 1;

	int n;
	cout << "N = ";
	cin >> n;

	cout << l << endl;
	cout << r << endl;

	while (true)
	{
		int x = l + r;

		if (x > n)
		{
			return;
		}
		
		cout << x << endl;
		l = r;
		r = x;
	}
}

void task4_7()
{
	int p;
	cout << "P = ";
	cin >> p;

	int r;
	cout << "R = ";
	cin >> r;

	int difference = abs(p - r);
	int errors = 0;

	while (true)
	{
		if (difference < 1)
		{
			break;
		}

		errors += (difference % 10 == 0) ? 0 : 1;
		difference /= 10;
	}

	cout << ((errors > 1) ? "не" : "") << "правильный пин-код" << endl;
}

void task4_8()
{
	int n;
	cout << "N = ";
	cin >> n;
	
	int k = 1;
	int pow = 1;

	while (true)
	{
		if (n < 1)
		{
			return;
		}

		if (n % 2 == 1)
		{
			cout << pow << endl;
		}
		pow *= 2;
		n /= 2;
	}
}

void task4_9()
{
	int n;
	cout << "N = ";
	cin >> n;

	int sum = 0;

	while (true)
	{
		if (n < 1)
		{
			break;
		}

		sum += n % 10;
		n /= 10;
	}

	cout << "Сумма цифр: " << sum << endl;
}

void task4_10()
{
	int n;
	cout << "N = ";
	cin >> n;

	int mx = -1;
	int mn = 10;
	int sum = 0;

	while (true)
	{
		if (n < 1)
		{
			break;
		}

		mx = max(mx, n % 10);
		mn = min(mn, n % 10);
		n /= 10;
	}

	cout << "Макс. цифра: " << mx << endl;
	cout << "Мин. цифра: " << mn << endl;
}

void task4_11()
{
	int n;
	cout << "N = ";
	cin >> n;

	int pow = 1;
	int number = 0;

	while (true)
	{
		if (n < 1)
		{
			break;
		}

		int digit = n % 10;
		if (digit % 2 == 0)
		{
			number += digit * pow;
			pow *= 10;
		}

		n /= 10;
	}

	cout << "Новое число: " << number << endl;
}

void task4_13()
{
	int n;
	cout << "N = ";
	cin >> n;

	int m = n;

	int denomintator = 2;
	int count = 0;

	while (true)
	{
		if (denomintator > n)
		{
				return;
		}

		if (m % denomintator == 0)
		{
			count++;
			m /= denomintator;
		}
		else
		{
			if (count != 0)
			{
				cout << denomintator << " ^ " << count << endl;
				count = 0;
			}
			denomintator++;
		}
	}
}

void task4_14()
{	
	int mx = INT_MIN;
	int mn = INT_MAX;

	int imx = -1;
	int imn = -1;
	int k = 1;

	while (true)
	{
		int x;
		cout << "Число: ";
		cin >> x;

		if (x == 0)
		{
			break;
		}

		if (mx < x)
		{
			mx = x;
			imx = k;
		}
		if (mn > x)
		{
			mn = x;
			imn = k;
		}

		k++;
	}

	if (imx == -1)
	{
		cout << "Пустая последовательность";
		return;
	}

	cout << "Индекс макс. числа: " << imx << "\t"
		<< "Индекс мин. числа: " << imn << endl;
}

void task4_15()
{
	int mx = INT_MIN;

	int count = 1;

	while (true)
	{
		int x;
		cout << "x = ";
		cin >> x;

		if (x == 0)
		{
			break;
		}

		if (x > mx)
		{
			mx = x;
			count = 1;
		}
		else if (x == mx)
		{
			count++;
		}
	}

	cout << "Кол-во макс. чисел: " << count;
}

void task4_16()
{
	int mx = INT_MIN;

	int index = 1;
	int k = 1;
	while (true)
	{
		int x;
		cout << "x = ";
		cin >> x;

		if (x == 0)
		{
			break;
		}

		if (x > mx)
		{
			mx = x;
			index = k;
		}

		k++;
	}

	cout << "Индекс макс. числа: " << index;
}

void fourth()
{
	//task4_1();
	//task4_2();
	//task4_3();
	//task4_4();
	//task4_5();

	// ---

	//task4_6();
	//task4_7();
	//task4_8();
	//task4_9();
	//task4_10();

	// ---

	//task4_11();
	//task4_13();
	//task4_14();
	//task4_15();
	task4_16();
}