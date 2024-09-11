// practice-cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void task2()
{
    float sideA;
    float sideB;

    cout << "Side a = ";
    cin >> sideA;
    cout << "Side b = ";
    cin >> sideB;

    float hypotenuse = sqrt(sideA * sideA + sideB * sideB);
    cout << "Hypotenuse c = " << hypotenuse << "\n";

    float area = .5 * sideA * sideB;
    cout << "Area S = " << area << "\n";

    float perimeter = sideA + sideB + hypotenuse;
    cout << "Perimeter P = " << perimeter << "\n";
}

void task4()
{
    float volume;

    cout << "Volume V = ";
    cin >> volume;

    float edge = cbrt(volume);
    cout << "Edge a = " << edge << "\n";

    float area = edge * edge * 6;
    cout << "Area S = " << area << "\n";
}

void task5()
{
    float r1;
    float r2;

    cout << "Radius r1 = ";
    cin >> r1;
    cout << "Radius r2 = ";
    cin >> r2;

    float area = abs(r1 * r1 - r2 * r2) * M_PI;
    cout << "Area S = " << area << "\n";
}

void task7()
{
    int hTime;
    int mTime;
    int sTime;

    cout << "h = ";
    cin >> hTime;
    cout << "m = ";
    cin >> mTime;
    cout << "s = ";
    cin >> sTime;

    float sAngle = sTime * 6; // sTime * 360 / 60
    float mAngle = mTime * 6 + sAngle / 60; // mTime * 360 / 60 + sAngle / 60;
    float hAngle = hTime * 30 + mAngle / 12; // hTime * 360 / 12 + mAngle / 12;

    cout << "Hour angle: " << hAngle << "\nMinute angle: " << mAngle << "\nSecond angle: " << sAngle << "\n";
}

void task8()
{
    int v;
    cout << "v = ";
    cin >> v;

    int cmLength = v * 106680;
    div_t km_m = div(cmLength, 1e5);
    div_t m_cm = div(km_m.rem, 1e2);

    cout << "km: " << km_m.quot << "\tm: " << m_cm.quot << "\tcm: " << m_cm.rem << "\n";
}

void task11()
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

void task13()
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

void task17()
{
    int days;
    cout << "N = ";
    cin >> days;

    int humans = pow(2, days) - 1;

    cout << "Humans eaten: " << humans << endl;
}

void task21()
{
    int words;
    cout << "N = ";
    cin >> words;

    int days = floor(log2(words)) + 1;

    cout << "Days taken: " << days << endl;
}

void task23()
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

int main()
{
    int option;

    while (1)
    {
        cout << "Options:\n2.\n4.\n5.\n7.\n8.\n11.\n13.\n17.\n21.\n23." << endl;
        cout << "Selected: ";
        cin >> option;
        switch (option)
        {
        case 2:
            task2();
            break;
        case 4:
            task4();
            break;
        case 5:
            task5();
            break;
        case 7:
            task7();
            break;
        case 8:
            task8();
            break;
        case 11:
            task11();
            break;
        case 13:
            task13();
            break;
        case 17:
            task17();
            break;
        case 21:
            task21();
            break;
        case 23:
            task23();
            break;
        default:
            break;
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
