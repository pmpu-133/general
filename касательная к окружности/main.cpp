#include <bits/stdc++.h>
#include "windows.h"
using namespace std;

struct Point {
    double x, y;
};

struct Vector{
    double x, y;

    Vector (double _x = 0, double _y = 0) {
        x = _x;
        y = _y;
    }

    Vector operator * (double a) {
        return Vector (a * x, a * y);
    }

    Vector operator / (double a) {
        return Vector (x / a, y / a);
    }

    Vector operator + (Vector a) {
        return Vector (a.x + x, a.y + y);
    }

    Vector operator - (Vector a) {
        return Vector (x - a.x, y - a.y);
    }
};

struct Line {
    double a, b, c;
};

struct Circl{
    double x, y, r;
};
Line pr(Point a, Point b)
{
    Line l;
    l.a = a.y - b.y;
    l.b = b.x - a.x;
    l.c = b.x * (b.y - a.y) - (b.x - a.x) * b.y;
    return l;
}

int main()
{
    //freopen("tangent.in", "r", stdin);
    //freopen("tangent.out", "w", stdout);

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Circl O;
    Point P;
    cout << "Введите координаты центра окружности и его радиус:";
    cin >> O.x >> O.y >> O.r;
    cout << "Введите координаты точки касательной:";
    cin >> P.x >> P.y;

    if ((P.x - O.x) * (P.x - O.x) + (P.y - O.y) * (P.y - O.y) < O.r * O.r)
        cout << "NON";
    else if ((P.x - O.x) * (P.x - O.x) + (P.y - O.y) * (P.y - O.y) == O.r * O.r)
    {
        cout << "Точка лежит на окружности" << endl;
        cout << P.x << ' ' << P.y;
    }
    else
    {
        //cout << "2" << endl;

        double a, b, h, ah;
        Point P0, P3;
        Line m;
        Vector OA, n;

        P0.x = O.x;
        P0.y = O.y;

        a = sqrt((O.x - P.x)*(O.x - P.x) + (O.y - P.y) * (O.y - P.y));

        b = sqrt(a*a - O.r * O.r);

        ah = O.r * O.r / a;


        h = O.r * b / a;

        OA.x = P.x - P0.x;
        OA.y = P.y - P0.y;
        OA = OA / a * ah;

      //  P3.x = (O.x + OA.x);
      //  P3.y = (O.y + OA.y);

        cout.precision(10);
        //cout << fixed << P3.x << ' ' << P3.y << endl;
        //cout << fixed << a - ah << ' ' << h << endl;



        m = pr(P0, P);
        n.x = m.a;
        n.y = m.b;
        n = n / sqrt(m.a * m.a + m.b * m.b) * h;
        cout << "координаты точек касания:"<<endl;
        cout << fixed << P0.x + OA.x - n.x << ' ' << P0.y + OA.y - n.y << endl;
        cout << fixed << P0.x + OA.x + n.x << ' ' << P0.y + OA.y + n.y << endl;
    }

    return 0;
}
