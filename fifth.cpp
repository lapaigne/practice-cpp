#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include "labs.h"

using namespace std;

int sqr(int number)
{
	return number * number;
}


bool isSquare(int number)
{
	return sqr(round(sqrt(number))) == number;
}


int digitSum(int number)
{
	int n = number;
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

	return sum;
}

int maxOfThree(int a, int b, int c)
{
	return max(max(a, b), c);
}


int maxDigit(int number)
{
	int n = number;

	int mx = 0;

	while (true)
	{
		if (n < 1)
		{
			break;
		}

		mx = max(mx, n % 10);
		n /= 10;
	}

	return mx;
}

int minOfThree(int a, int b, int c)
{
	return min(min(a, b), c);
}


// 5.1

void task5_1()
{
	int a, b, c;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;

	int aSum = digitSum(a);
	int bSum = digitSum(b);
	int cSum = digitSum(c);

	int m = maxOfThree(aSum, bSum, cSum);

	if (m == aSum)
	{
		cout << "Число a имеет максимальную сумму цифр: " << aSum << endl;
	}
	else if (m == bSum)
	{
		cout << "Число b имеет максимальную сумму цифр: " << bSum << endl;
	}
	else
	{
		cout << "Число c имеет максимальную сумму цифр: " << cSum << endl;
	}
}


// 5.2

void task5_2()
{
	int a, b, c;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;

	int amd = maxDigit(a);
	int bmd = maxDigit(b);
	int cmd = maxDigit(c);

	int m = minOfThree(amd, bmd, cmd);

	if (m == amd)
	{
		cout << "Число a; минимальная цифра: " << amd << endl;
	}
	else if (m == bmd)
	{
		cout << "Число b; минимальная цифра: " << bmd << endl;
	}
	else
	{
		cout << "Число c; минимальная цифра: " << cmd << endl;
	}
}

// 5.6

void task5_6()
{
	int a, b, c;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;

	cout << "Число a - " << (!isSquare(a) ? "не " : "") << "квадрат" << endl;
	cout << "Число b - " << (!isSquare(b) ? "не " : "") << "квадрат" << endl;
	cout << "Число c - " << (!isSquare(c) ? "не " : "") << "квадрат" << endl;
}
// 5.8

int minDigit(int number)
{
	int n = number;

	int mn = 0;

	while (true)
	{
		if (n < 1)
		{
			break;
		}

		mn = min(mn, n % 10);
		n /= 10;
	}

	return mn;
}

int prod(int a, int b)
{
	return a * b;
}

void task5_8()
{
	int a, b, c;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;

	cout << "Произведение макс. и мин. цифр числа a: " << prod(minDigit(a), maxDigit(a)) << endl;
	cout << "Произведение макс. и мин. цифр числа b: " << prod(minDigit(b), maxDigit(b)) << endl;
	cout << "Произведение макс. и мин. цифр числа c: " << prod(minDigit(c), maxDigit(c)) << endl;
}

// 5.13
double lineLength(double x1, double y1, double x2, double y2)
{
	return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}

double midPoint(double a, double b)
{
	return .5 * (a + b);
}
void task5_13()
{
	
	int x1, y1, x2, y2, x3, y3;
	cout << "(x1,y1): ";
	cin >> x1;
	cin >> y1;

	cout << "(x2,y2): ";
	cin >> x2;
	cin >> y2;

	cout << "(x3,y3): ";
	cin >> x3;
	cin >> y3;

	cout << "Длина медианы первой точки: " << lineLength(x1, y1, midPoint(x2, x3), midPoint(y2, y3)) << endl;
	cout << "Длина медианы второй точки: " << lineLength(x2, y2, midPoint(x1, x3), midPoint(y1, y3)) << endl;
	cout << "Длина медианы третьей точки: " << lineLength(x3, y3, midPoint(x2, x1), midPoint(y2, y1)) << endl;
}



// 5.17

struct Vector3
{
	double x, y, z;
};

Vector3 input()
{
	Vector3 result;
	cin >> result.x >> result.y >> result.z;
	return result;
}

void print(Vector3 v)
{
	cout << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}

Vector3 add(Vector3 v1, Vector3 v2)
{
	Vector3 result;
	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return result;
}

double dotProduct(Vector3 v1, Vector3 v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vector3 mult(double alpha, Vector3 v)
{
	Vector3 nv = v;
	nv.x = v.x * alpha;
	nv.y = v.y * alpha;
	nv.z = v.z * alpha;
	return nv;
}

double length(Vector3 v)
{
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

void task5_17()
{
	Vector3 x, y, z;
	x = input();
	y = input();
	z = input();

	cout << "xy + yz + xz = " << dotProduct(x, y) + dotProduct(y, z) + dotProduct(x, z);
}

void task5_18()
{
	Vector3 x, y, z;
	x = input();
	y = input();
	z = input();

	print(
		add(
			x,
			add(
				mult(2,y),
				mult(3,z)
			)
		)
	);
}

void task5_19()
{
	Vector3 x, y;
	x = input();
	y = input();

	cout << length(x) + length(y) + length(add(x, y)) << endl;
}

void fifth()
{
	//task5_1();
	//task5_2();
	//task5_6();
	//task5_8();
	
	//task5_13();
	//task5_17();
	//task5_18();
	//task5_19();
}