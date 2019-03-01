#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

string s;

int z[MAXN];

int main()
{
    freopen("zfunction.in", "r", stdin);
    freopen("zfunction.out", "w", stdout);

    int l, r, n, j;

    z[0] = 0;
    l = 0;
    r = 0;

    cin >> s;

    n = s.length();

    s = s + '!';

    for (int i = 1; i < n; i++)
    {
        if (z[i-l] < r-i)
            z[i] = z[i - l];
        else{
            z[i] = max(0, r-i);
            //j = i;
            while (s[i + z[i]] == s[z[i]]){
                z[i]++;
                //j++;
            }
            r = i + z[i];
            l = i;
        }
    }

    for (int i = 0; i < n; i++)
        cout << z[i] << " ";

    return 0;
}
