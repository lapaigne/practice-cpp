#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include "labs.h"

using namespace std;



void task2_1()
{
	double a, b, c;
	double maxV, minV;

	cout << "a, b, c: " << endl;
	cin >> a >> b >> c;

	maxV = max(max(a, b), c);
	minV = min(min(a, b), c);

	/*min = a;
	max = a;
	
	if (b > max)
	{
		max = b;
	}
	if (c > max)
	{
		max = c;
	}
	if (b < min)
	{
		min = b;
	}
	if (c < min)
	{
		min = c;
	}*/

	cout << "Максимум: " << maxV << "\tМинимум: " << minV << endl;
}

void task2_2()
{
	double a, b, c;
	cout << "a, b, c: " << endl;
	cin >> a >> b >> c;

	double mid = max(min(a, b), c);

	if ((a == b) && (b == c))
	{
		cout << "Такого числа нет" << endl;
		return;
	}
	cout << "Второе по величине число: " << mid << endl;
}

void task2_3()
{
	double a, b, c;
	double hp, area;
	cout << "a, b, c: " << endl;
	cin >> a >> b >> c;

	if ((a + b > c) && (a + c > b) && (b + c > a))
	{
		hp = (a + b + c) / 2;
		area = sqrt(hp * (hp - a) * (hp - b) * (hp - c));
		cout << "Площадь S = " << area << endl;
		return;
	}
	cout << "Такого треугольника не существует";	
}

void task2_4()
{
	double a, b, c;
	int result = 1;
	cout << "a, b, c: " << endl;
	cin >> a >> b >> c;

	if (a == b || b == c || a == c)
	{
		result = 2;
	}

	if (a == b && b == c)
	{
		result = 3;
	}

	cout << "Результат: " << result << endl;
}

void task2_6()
{
	int a, b, c, x, y, z;

	cout << "2.6" << endl;
	cout << "Даны целые числа a, b, c, X, Y, Z. В каждый новогодний подарок нужно положить a конфет, b яблок и c печенек. Сколько подарков можно скомплектовать из X конфет, Y яблок и Z печенек?" << endl;

	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;

	cout << "X = ";
	cin >> x;
	cout << "Y = ";
	cin >> y;
	cout << "Z = ";
	cin >> z;

	int result = 0;

	if (a <= 0 || b <= 0 || c <= 0 || x <= 0 || y <= 0 || z <= 0)
	{
		cout << "Неправильные данные!" << endl;
		return;
	}

	result = min(min(floor(x / a), floor(y / b)), floor(z / c));
	cout << "Результат: " << result << endl;
}

void task2_8()
{
	double x, y;
	double a, b, c;

	cout << "x, y: " << endl;
	cin >> x >> y;
	cout << "a, b, c: " << endl;
	cin >> a >> b >> c;

	double brickMin = min(min(a, b), c);
	double brickMid = max(min(a, b), c);

	if ((min(x, y) > brickMin) && (max(x, y) > brickMid))
	{
		cout << "Кирпич пройдет" << endl;
		return;
	}
	cout << "Кирпич не пройдет" << endl;
}

void task2_10()
{
	int year;
	bool isLeap = false;
	cout << "Введите год: ";
	cin >> year;

	if (year % 4 == 0)
	{
		isLeap = true;
	}
	if (year % 100 == 0)
	{
		isLeap = false;
	}
	if (year % 400 == 0)
	{
		isLeap = true;
	}

	if (isLeap)
	{
		cout << year << " - високосный" << endl;
	}
	else
	{
		cout << year << " - невисокосный" << endl;
	}
	
}

void task2_11()
{
	double r, x, y;
	int score = 0;
	
	cout << "R = " << endl;
	cin >> r;
	cout << "x, y: " << endl;
	cin >> x >> y;
	
	double distance = sqrt(x * x + y * y);
	
	score = max(0.0, 4 - floor(distance / r));
	
	cout << "Счет: " << score << endl;
}

void task2_14()
{
	int a, b, c, d;

	cout << "2.14" << endl;
	cout << "Даны четыре целых числа, одно из них не равно трём другим, равным между собой. Указать порядковый номер числа, отличного от остальных." << endl;

	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	cout << "d = ";
	cin >> d;

	cout << "Результат: " << endl;

	if (a != b && a != c)
	{
		cout << "1" << endl;
		return;
	}
	if (a != b && b != c)
	{
		cout << "2" << endl;
		return;
	}
	if (b != c && c != d)
	{
		cout << "3" << endl;
		return;
	}
	if (b != d && c != d)
	{
		cout << "4" << endl;
		return;
	}
}

void task2_19()
{
	int number;
	string result;
	bool special = false;

	cout << "Число N = ";
	cin >> number;

	if (number > 999 || number < 1)
	{
		cout << "Неправильное число";
		return;
	}

	switch (number / 100)
	{
	case 1:
		result = "сто ";
		break;
	case 2:
		result = "двести ";
		break;
	case 3:
		result = "триста ";
		break;
	case 4:
		result = "четыреста ";
		break;
	case 5:
		result = "пятьсот ";
		break;
	case 6:
		result = "шестьсот ";
		break;
	case 7:
		result = "семьсот ";
		break;
	case 8:
		result = "восемьсот ";
		break;
	case 9:
		result = "девятьсот ";
		break;
	default:
		break;
	}

	if ((number / 10) % 10 != 1)
	{
		switch ((number / 10) % 10)
		{
		case 1:
			special = true;
			break;
		case 2:
			result += "двадцать ";
			break;
		case 3:
			result += "тридцать ";
			break;
		case 4:
			result += "сорок ";
			break;
		case 5:
			result += "пятьдесят ";
			break;
		case 6:
			result += "шестьдесят ";
			break;
		case 7:
			result += "семьдесят ";
			break;
		case 8:
			result += "восемьдесят ";
			break;
		case 9:
			result += "девяносто ";
			break;
		default:
			break;
		}

		switch (number % 10)
		{
		case 1:
			result += "один";
			break;
		case 2:
			result += "два";
			break;
		case 3:
			result += "три";
			break;
		case 4:
			result += "четыре";
			break;
		case 5:
			result += "пять";
			break;
		case 6:
			result += "шесть";
			break;
		case 7:
			result += "семь";
			break;
		case 8:
			result += "восемь";
			break;
		case 9:
			result += "девять";
			break;
		default:
			break;
		}
	}
	else
	{
		switch (number % 100)
		{
		case 10:
			result += "десять";
			break;
		case 11:
			result += "одиннадцать";
			break;
		case 12:
			result += "двенадцать";
			break;
		case 13:
			result += "тринадцать";
			break;
		case 14:
			result += "четырнадцать";
			break;
		case 15:
			result += "пятнадцать";
			break;
		case 16:
			result += "шестнадцать";
			break;
		case 17:
			result += "семнадцать";
			break;
		case 18:
			result += "восемнадцать";
			break;
		case 19:
			result += "девятнадцать";
			break;

		default:
			break;
		}
	}

	cout << "Число: " << result << endl;
}

void task2_22()
{
	double k, b, r;

	cout << "2.22" << endl;
	cout << "Даны вещественные числа k, b и R (R > 0). Найти количество точек пересечения прямой, задаваемой уравнением y=kx+b и окружностью с центром в начале координат и радиусом R." << endl;

	cout << "k =  ";
	cin >> k;
	cout << "b =  ";
	cin	>> b;
	cout << "r =  ";
	cin	>> r;

	if (r <= 0)
	{
		cout << "Ошибка" << endl;
		return;
	}

	double d = k * k * b * b - (k * k + 1) * (b * b - r * r);

	if (d < 0)
	{
		cout << "Нет точек пересечения" << endl;
		return;
	}
	if (d == 0)
	{
		cout << "Одна точка пересечения" << endl;
		return;
	}
	cout << "Две точки пересечения" << endl;
}

void task2_23()
{
	double a, b, c;
	cout << "a, b, c:" << endl;
	cin >> a >> b >> c;

	if (a == 0)
	{
		cout << "a = 0\nНеправильные данные" << endl;
		return;
	}

	double d = b * b - 4 * a * c;
	double y1, y2, x1, x2, x3, x4;

	if (d > 0)
	{
		y1 = 0.5 * (-b - sqrt(d)) / a;
		y2 = 0.5 * (-b + sqrt(d)) / a;

		if (y1 < 0 && y2 < 0)
		{
			cout << "Нет корней" << endl;
			return;
		}

		if (y1 >= 0)
		{
			x1 = -sqrt(y1);
			x2 = sqrt(y2);
			cout << "x1 = " << x1 << endl
				<< "x2 = " << x2 << endl;
		}

		if (y2 >= 0)
		{
			x3 = -sqrt(y2);
			x4 = sqrt(y2);
			cout << "x3 = " << x3 << endl
				<< "x4 = " << x4 << endl;
		}
		
		return;
	}
	
	if (d == 0)
	{
		y1 = -0.5 * b / a;
		
		if (y1 < 0)
		{
			cout << "Нет корней" << endl;
			return;
		}

		x1 = -sqrt(y1);
		x2 = sqrt(y1);

		if (x1 == x2)
		{
			cout << "x1 = " << x1 << endl;
		}
		else
		{
			cout << "x1 = " << x1 << endl << "x2 = " << x2 << endl;
		}
		return;
	}

	cout << "Нет корней" << endl;
}

void task2_27()
{
	int a, b, c;

	cout << "2.27" << endl;
	cout << "Даны целые положительные A, B и C. Какое максимальное число квадратов со стороной С можно разместить в прямоугольнике со сторонами A и B без наложений? Указать площадь занятой квадратами и незанятой частей прямоугольника." << endl;

	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;

	int count = floor(a / c) * floor(b / c);
	cout << "Кол-во квадратов: " << count << endl;
	int area = count * c * c;
	cout << "Площадь, занятая квадратами: " << area << endl;
	int free = a * b - area;
	cout << "Оставшаяся площадь: " << free << endl;
}

void task2_29()
{
	double n, r, x, y;
	int score = 0;

	cout << "N, R: " << endl;
	cin >> n >> r;
	cout << "x, y: " << endl;
	cin >> x >> y;

	double distance = sqrt(x * x + y * y);

	score = max(0.0, n - floor(distance / r));

	cout << "Счет: " << score << endl;
}

void task2_31()
{
	double a, b, c;
	double y1, y2, x1, x2, x3, x4;
	cout << "a, b, c:" << endl;
	cin >> a >> b >> c;

	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0)
			{
				cout << "x - любое число" << endl;
				return;
			}

			cout << "Нет корней" << endl;
			return;
		}

		y1 = -c / b;
		
		if (y1 < 0)
		{
			cout << "Нет корней" << endl;
			return;
		}

		if (y1 == 0)
		{
			x1 = 0;
			cout << "x1 = " << x1 << endl;
			return;
		}

		x1 = -sqrt(y1);
		x2 = sqrt(y1);

		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
	}

	double d = b * b - 4 * a * c;

	if (d > 0)
	{
		y1 = 0.5 * (-b - sqrt(d)) / a;
		y2 = 0.5 * (-b + sqrt(d)) / a;

		if (y1 < 0 && y2 < 0)
		{
			cout << "Нет корней" << endl;
			return;
		}

		if (y1 >= 0)
		{
			x1 = -sqrt(y1);
			x2 = sqrt(y2);
			cout << "x1 = " << x1 << endl
				<< "x2 = " << x2 << endl;
		}

		if (y2 >= 0)
		{
			x3 = -sqrt(y2);
			x4 = sqrt(y2);
			cout << "x3 = " << x3 << endl
				<< "x4 = " << x4 << endl;
		}

		return;
	}

	if (d == 0)
	{
		y1 = -0.5 * b / a;

		if (y1 < 0)
		{
			cout << "Нет корней" << endl;
			return;
		}

		x1 = -sqrt(y1);
		x2 = sqrt(y1);

		if (x1 == x2)
		{
			cout << "x1 = " << x1 << endl;
		}
		else
		{
			cout << "x1 = " << x1 << endl << "x2 = " << x2 << endl;
		}
		return;
	}

	cout << "Нет корней" << endl;
}

void second()
{
	//task2_1();
	//task2_2();
	//task2_3();
	//task2_4();
	//task2_8();
	
	//task2_10();
	//task2_11();
	//task2_19();
	//task2_23();
	//task2_29();
	
	//task2_31();

	// ---

	//task2_6();
	//task2_14();
	//task2_22();
	//task2_27();

}