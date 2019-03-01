#include <bits/stdc++.h>

using namespace std;

struct Point {
    long double x, y;
};

struct Vector{
    long double x, y;

    Vector (long double _x=0, long double _y=0) {
        x = _x;
        y = _y;
    }

    Vector operator * (long double a) {
        return Vector (a * x, a * y);
    }

    Vector operator / (long double a) {
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
    long double a, b, c;
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

    freopen("altitude.in", "r", stdin);
    freopen("altitude.out", "w", stdout);

    Point A, B, C, C1, A1, ans;
    Line a, b, m, n;
    Vector p;
    long double len;

    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;

    a = pr(A, B);
    b = pr(B, C);



    p.x = a.a;
    p.y = a.b;

    C1.x = C.x + p.x;
    C1.y = C.y + p.y;

    m = pr(C, C1);



    p.x = b.a;
    p.y = b.b;

    A1.x = A.x + p.x;
    A1.y = A.y + p.y;

    n = pr(A, A1);



    ans.x = (m.b * n.c - n.b * m.c) / (n.b * m.a - m.b * n.a);
    ans.y = (m.a * n.c - n.a * m.c) / (n.a * m.b - m.a * n.b);

    cout << fixed << setprecision(20) << ans.x << ' ' << ans.y;

    return 0;
}
