#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include "labs.h"
#include <set>

using namespace std;

// 6.1

void task6_1()
{
	int n;
	cout << "N = ";
	cin >> n;
	int* array = new int[n];

	int max = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (array[i] < 0 && array[i] > max)
		{
			max = array[i];
		}
	}

	cout << max;
}

void task6_2()
{
	int n;
	cout << "N = ";
	cin >> n;
	int* array = new int[n];

	int min = INT_MAX;

	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (array[i] > 0 && array[i] < min)
		{
			min = array[i];
		}
	}

	cout << min;
}

void task6_4()
{
	int n;
	cout << "N = ";
	cin >> n;
	int* array = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}

	set<int> distinct(array, array + n);
	cout << "Число различных элементов: " << distinct.size();
}

void task6_5()
{
	int n;
	cout << "N = ";
	cin >> n;
	int* array = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}

	int count = 0;
	if (array[0] < array[1])
	{
		count++;
	}

	if (array[n - 1] < array[n - 2])
	{
		count++;
	}

	for (int i = 1; i < n - 1; i++)
	{
		if (array[i] < array[i + 1] && array[i] < array[i - 1])
		{
			count++;
		}
	}

	cout << "Число элементов меньше своих соседей: " << count;
}

void task6_7()
{
	int n;
	cout << "N = ";
	cin >> n;

	int* array = new int[n];
	for (int i = 0; i < n; i++) {
		array[i] = i + 1;
	}

	srand(time(0));
	for (int i = n - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		int t = array[i];
		array[i] = array[j];
		array[j] = t;
	}

	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
}

void task6_11()
{
	int n;
	cout << "N = ";
	cin >> n;
	int* array = new int[n];
	bool isPalindrome = true;

	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}

	for (int i = 0; i < n / 2; i++)
	{
		if (array[i] != array[n - 1 - i])
		{
			isPalindrome = false;
			break;
		}
	}

	cout << "Массив " << ((isPalindrome)? "" : "не ") << "является палиндромом";
}
void task6_12()
{
	int index = -1;
	int min = INT_MAX;
	int n = 10;
	int array[10] = { 1,100,5,6,995,-1,20,10,30,40 };
	for (int i = 0; i < n; i++)
	{
		if (array[i] < min)
		{
			index = i;
			min = array[i];
		}
	}

	for (int i = 0; i < index; i++)
	{
		int j = (index + i) % n;
		int t = array[i];
		array[i] = array[j];
		array[j] = t;
	}

	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
}

void task6_16()
{
	int numbers[5] = { 1,2,3,4,5 };
	int results[5] = { 4,21,5,72,46 };

	for (int i = 0; i < 5; i++)
	{
		cout << results[i] << "\t" << numbers[i] << endl;
	}
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = i; j < 5; j++)
		if (results[i] > results[j])
		{
			int tr = results[i];
			results[i] = results[j];
			results[j] = tr;

			int tn = numbers[i];
			numbers[i] = numbers[j];
			numbers[j] = tn;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		cout << results[i] << "\t" << numbers[i] << endl;
	}
}

void sixth()
{	
	//task6_1();
	//task6_2();
	//task6_4();
	//task6_5();
	//task6_7();
	//task6_11();
	//task6_12();
	//task6_16();
}