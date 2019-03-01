#include <bits/stdc++.h>

using namespace std;

struct Vector{
    double x, y;

    Vector (double _x=0, double _y=0) {
        x = _x;
        y = _y;
    }

    Vector operator * (double a) {
        return Vector (a * x, a * y);
    }

    double operator ^ (Vector a) {
        return x * a.y - a.x * y;
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

int main()
{
   // freopen("square.in", "r", stdin);
    //freopen("square.out", "w", stdout);

    double ans = 0, n;
    Vector a, b, first;

    cin >> n;

    cin >> first.x >> first.y;

    a = first;

    for (int i = 1; i < n; i++)
    {

        cin >> b.x >> b.y;

            ans =  ans + (b ^ a);

        a = b;
    }
        ans = ans + (first ^ a);

    cout.precision(5);
    cout << fixed << abs(ans / 2);
    return 0;
}
