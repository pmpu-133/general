#include <bits/stdc++.h>

using namespace std;

const int  N = 100001, M = 300;

bool tipe[N];

int main(){

    //freopen("backpack.in", "r", stdin);
    //freopen("backpack.out", "w", stdout);

    long long s, n, x;

    cin >> s >> n;

    fill(tipe, tipe + s, false);

    tipe[0] = true;

    for (int i = 1; i <= n; i++)
    {
        cin >> x;

        for(int j = s - x; j >= 0; j--)
        {
            if (tipe[j])
                tipe[j + x] = true;
        }
    }
    for(int i = s; i >= 0; i--)
    {
        if (tipe[i])
        {
            cout << i;
            break;
        }
    }

    return 0;
}
