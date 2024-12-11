#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include "labs.h"

using namespace std;

void makeMatrix(int**& a, int m, int n)
{
    a = new int* [m];
    for (int i = 0; i < m; i++)
    {
        a[i] = new int[n];
    }
}

void randomFill(int** a, int m, int n, int range)
{
    srand(time(0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % range;
        }
    }
}

template <size_t rows, size_t cols>
bool isSymmetricalByMain(int(&a)[rows][cols], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i][j] != a[j][i])
            {
                return false;   
            }
        }
    }
    return true;
}
template <size_t rows, size_t cols>
bool isSymmetricalBySecondary(int (&a)[rows][cols], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (a[i][j] != a[n - j - 1][n - i - 1])
            {       
                return false;
            }
        }
    }
    return true;
}

void printMatrix(int** a, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
}

void task7_1()
{
    int n = 3;
    int matrix[3][3]=
    {
        {3,4,5},
        {4,6,8},
        {5,8,0}
    };
  
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Матрица " << (isSymmetricalByMain(matrix, n) ? "" : "не ") << "симметрична относительно главной диагонали" << endl;
    cout << "Матрица " << (isSymmetricalBySecondary(matrix, n) ? "" : "не ") << "симметрична относительно побочной диагонали" << endl;
}

int minBelowMain(int** matrix, int n, int range)
{
    int mn = range;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            mn = min(matrix[i][j], mn);
        }
    }

    return mn;
}

int maxAboveMain(int** matrix, int n)
{
    int mx = -1;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            mx = max(matrix[j][i], mx);
        }
    }

    return mx;
}

void task7_2()
{
    int n = 5;
    int range = 15;
    int** matrix = NULL;
    makeMatrix(matrix, n, n);
    randomFill(matrix, n, n, range);
    printMatrix(matrix, n, n);

    int mx = maxAboveMain(matrix, n);
    int mn = minBelowMain(matrix, n, range);

    cout << "Максимум: " << mx << endl;
    cout << "Минимум: " << mn << endl;
}

int sumAboveSecondary(int** matrix, int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = n - i; j < n; j++)
        {
            sum += matrix[i][j];
        }
    }

    return sum;
}

int maxBelowSecondary(int** matrix, int n)
{
    int mx = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            mx = max(matrix[i][j], mx);
        }
    }

    return mx;
}

void task7_3()
{
    int n = 3;
    int range = 15;
    int** matrix = NULL;
    makeMatrix(matrix, n, n);
    randomFill(matrix, n, n, range);
    printMatrix(matrix, n, n);

    int mx = maxBelowSecondary(matrix, n);
    int sum = sumAboveSecondary(matrix, n);

    cout << "Максимум: " << mx << endl;
    cout << "Сумма: " << sum << endl;
}

void seventh()
{
    //task7_1();
    //task7_2();
    task7_3();
}