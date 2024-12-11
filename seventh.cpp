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
bool isSymmetricalByMain(int (&a)[rows][cols], int n)
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
        {4,6,4},
        {5,4,3}
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
        for (int j = 0; j < n - i - 1; j++)
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
        for (int j = n - i; j < n; j++)
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

int maxRowSum(int** matrix, int m, int n)
{
    int mx = 0;
    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += matrix[i][j];
        }
        mx = max(sum, mx);
    }

    return mx;
}

void task7_4()
{
    int m = 5;
    int n = 3;
    int range = 15;
    int** matrix = NULL;
    makeMatrix(matrix, m, n);
    randomFill(matrix, m, n, range);
    printMatrix(matrix, m, n);

    cout << "Макс. сумма: " << maxRowSum(matrix, m, n);
}

void maxMinByColumn(int** matrix, int m, int n, int range)
{
    int mi = -1;
    int mj = -1;
    int mx = -1;

    for (int i = 0; i < n; i++)
    {
        int mn = range;
        for (int j = 0; j < m; j++)
        {
            if (matrix[j][i] <= mn)
            {
                mn = matrix[j][i];
                mi = i;
                mj = j;

            }
        }

        if (mn >= mx)
        {
            mx = mn;
        }
    }
    cout << "matrix[" << mj << "][" << mi << "] = " << mx;
}

void task7_5()
{
    int m = 5;
    int n = 3;
    int range = 15;
    int** matrix = NULL;
    makeMatrix(matrix, m, n);
    randomFill(matrix, m, n, range);
    printMatrix(matrix, m, n);

    maxMinByColumn(matrix, m, n, range);
}

void maxMinByRow(int** matrix, int m, int n, int range)
{
    int mi = -1;
    int mj = -1;
    int mn = range;

    for (int i = 0; i < m; i++)
    {
        int mx = -1;
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] >= mx)
            {
                mx = matrix[i][j];
                mi = i;
                mj = j;
            }
        }

        if (mx <= mn)
        {
            mn = mx;
        }
    }
    cout << "matrix[" << mi << "][" << mj << "] = " << mn;
}

void task7_6()
{
    int m = 5;
    int n = 3;
    int range = 15;
    int** matrix = NULL;
    makeMatrix(matrix, m, n);
    randomFill(matrix, m, n, range);
    printMatrix(matrix, m, n);

    maxMinByRow(matrix, m, n, range);
}

bool isPalindrome(int* a, int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        if (a[i] != a[n - 1 - i])
        {
            return false;
        }
    }
    return true;
}

void task7_7()
{
    int m = 4;
    int n = 5;
    int range = 2;
    int** matrix = NULL;
    makeMatrix(matrix, m, n);
    randomFill(matrix, m, n, range);
    printMatrix(matrix, m, n);

    for (int i = 0; i < m; i++)
    {
        if (isPalindrome(matrix[i], n))
        {
            cout << "Строка " << i + 1 << " - палиндром" << endl;
        }
    }
}

void task7_8()
{
    int m = 4;
    int n = 5;
    int range = 2;
    int** matrix = NULL;
    makeMatrix(matrix, m, n);
    randomFill(matrix, m, n, range);
    printMatrix(matrix, m, n);

    for (int i = 0; i < n; i++)
    {
        int* a = new int[m];
        for (int j = 0; j < m; j++)
        {
            a[j] = matrix[j][i];
        }

        if (isPalindrome(a, m))
        {
            cout << "Столбец " << i + 1 << " - палиндром" << endl;
        }
    }
}



void multMatrices(int** a, int** b, int n)
{
    int** c = NULL;
    makeMatrix(c, n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp = 0;
            for (int k = 0; k < n; k++)
            {
                temp += a[i][k] * b[k][j];
            }
            c[i][j] = temp;
        }
    }
    cout << "C = " << endl;
    printMatrix(c, n, n);
}

void task7_11()
{
    int n = 2;
    int range = 2;
    int** a = NULL;
    
    cout << "A = " << endl;
    makeMatrix(a, n, n);
    randomFill(a, n, n, range);
    printMatrix(a, n, n);

    cout << "B = " << endl;
    int** b = NULL;
    makeMatrix(b, n, n);
    randomFill(b, n, n, range+2);
    printMatrix(b, n, n);

    cout << endl;

    multMatrices(a, b, n);
}

void rotateClockwise(int** a, int n)
{
    int** b = NULL;

    makeMatrix(b, n, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            b[j][i] = a[n - i - 1][j];
        }
    }
    cout << endl;
    cout << "B = " << endl;
    printMatrix(b, n, n);
}

void task7_15()
{
    int n = 4;
    int range = 15;
    int** a = NULL;

    cout << "A = " << endl;
    makeMatrix(a, n, n);
    randomFill(a, n, n, range);
    printMatrix(a, n, n);

    rotateClockwise(a, n);
}

void seventh()
{
    //task7_1();
    //task7_2();
    //task7_3();s
    //task7_4();
    //task7_5();
    //task7_6();
    //task7_7();
    //task7_8();
    //task7_11();
    //task7_15();
}