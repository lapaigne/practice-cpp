#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <vector>
#include "labs.h"

using namespace std;

void task1_2()
{
    float sideA;
    float sideB;

    cout << "Катет a = ";
    cin >> sideA;
    cout << "Катет b = ";
    cin >> sideB;

    float hypotenuse = sqrt(sideA * sideA + sideB * sideB);
    cout << "Гипотенуза c = " << hypotenuse << "\n";

    float area = .5 * sideA * sideB;
    cout << "Площадь S = " << area << "\n";

    float perimeter = sideA + sideB + hypotenuse;
    cout << "Периметр P = " << perimeter << "\n";
}

void task1_4()
{
    float volume;

    cout << "Объем V = ";
    cin >> volume;

    float edge = cbrt(volume);
    cout << "Ребро a = " << edge << "\n";

    float area = edge * edge * 6;
    cout << "Площадь S = " << area << "\n";
}

void task1_5()
{
    float r1;
    float r2;

    cout << "Радиус r1 = ";
    cin >> r1;
    cout << "Радиус r2 = ";
    cin >> r2;

    float area = abs(r1 * r1 - r2 * r2) * M_PI;
    cout << "Площадь S = " << area << "\n";
}

void task1_7()
{
    int hTime;
    int mTime;
    int sTime;

    cout << "Часы: ";
    cin >> hTime;
    cout << "Минуты: ";
    cin >> mTime;
    cout << "Секунды ";
    cin >> sTime;

    float sAngle = sTime * 6; // sTime * 360 / 60
    float mAngle = mTime * 6 + sAngle / 60; // mTime * 360 / 60 + sAngle / 60;
    float hAngle = hTime * 30 + mAngle / 12; // hTime * 360 / 12 + mAngle / 12;

    cout << "Угол поворота часовой стрелки: " << hAngle << "\nУгол поворота минутной стрелки: " << mAngle << "\nУгол поворота секундной стрелки: " << sAngle << "\n";
}

void task1_8()
{
    int v;
    cout << "Длина в верстах: ";
    cin >> v;

    int cmLength = v * 106680;
    div_t km_m = div(cmLength, 1e5);
    div_t m_cm = div(km_m.rem, 1e2);

    cout << "км: " << km_m.quot << "\tм: " << m_cm.quot << "\tсм: " << m_cm.rem << "\n";
}

void task1_11()
{
    int a;
    int b;
    int c;

    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;

    int temp = a;
    a = b;
    b = c;
    c = temp;

    cout << "a = " << a << "\tb = " << b << "\tc = " << c << "\n";
}

void task1_13()
{
    vector<pair<float, float>> points;
    pair<float, float> p;

    cout << "x1 = ";
    cin >> p.first;
    cout << "y1 = ";
    cin >> p.second;
    points.push_back(p);

    cout << "x2 = ";
    cin >> p.first;
    cout << "y2 = ";
    cin >> p.second;
    points.push_back(p);

    cout << "x3 = ";
    cin >> p.first;
    cout << "y3 = ";
    cin >> p.second;
    points.push_back(p);

    points.push_back(
        make_pair(
            .5 * (points[0].first + points[1].first),
            .5 * (points[0].second + points[1].second)
        )
    );
    points.push_back(
        make_pair(
            .5 * (points[1].first + points[2].first),
            .5 * (points[1].second + points[2].second)
        )
    );
    points.push_back(
        make_pair(
            .5 * (points[0].first + points[2].first),
            .5 * (points[0].second + points[2].second)
        )
    );

    cout << "1-2 : (" << points[3].first << ", " << points[3].second << ")" << endl;
    cout << "2-3 : (" << points[4].first << ", " << points[4].second << ")" << endl;
    cout << "1-3 : (" << points[5].first << ", " << points[5].second << ")" << endl;
}

void task1_17()
{
    int days;
    cout << "N = ";
    cin >> days;

    int humans = pow(2, days) - 1;

    cout << "Людей съедено: " << humans << endl;
}

void task1_21()
{
    int words;
    cout << "N = ";
    cin >> words;

    int days = floor(log2(words)) + 1;

    cout << "Кол-во дней: " << days << endl;
}

void task1_23()
{
    float a;
    float b;

    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    a = a + b;
    b = a - b;
    a = a - b;

    cout << "a = " << a << "\nb = " << b << endl;
}

void first()
{
    int option;

    while (1)
    {
        cout << "Задачи:\n2.\n4.\n5.\n7.\n8.\n11.\n13.\n17.\n21.\n23." << endl;
        cout << "Выбранная задача: ";
        cin >> option;
        switch (option)
        {
        case 2:
            task1_2();
            break;
        case 4:
            task1_4();
            break;
        case 5:
            task1_5();
            break;
        case 7:
            task1_7();
            break;
        case 8:
            task1_8();
            break;
        case 11:
            task1_11();
            break;
        case 13:
            task1_13();
            break;
        case 17:
            task1_17();
            break;
        case 21:
            task1_21();
            break;
        case 23:
            task1_23();
            break;

        case 0:
            return;

        default:
            cout << "Такой задачи нет";
            break;
        }
        system("pause");
    }
}
