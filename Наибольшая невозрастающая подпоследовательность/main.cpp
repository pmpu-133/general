#include <bits/stdc++.h>

using namespace std;
const long long MAXA = 240000, MAXW = 2200000000;

long long fir[MAXA], dp[MAXA], prev1[MAXA], pos[MAXA], write[MAXA];

long long binsearch(long long a)
{
    long long m, l, r;

    l = 0;
    r = MAXA;
    while (l+1 != r)
    {
        m = (l + r) / 2;
        if (dp[m] >= a)
            l = m;
        else
            r = m;
    }
    return r;
}
int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    fill(dp, dp + MAXA, -MAXW);
    dp[0] = MAXW;

    long long n, i, rprev = 0;

    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> fir[i];
        auto a = binsearch(fir[i]);
        dp[a] = fir[i];
        pos[a] = i;
        if (a == 1)
            prev1[rprev] = -1;
        else
            prev1[rprev] = pos[a-1];
        rprev++;
    }

    for (i = 0; i < MAXA; i++)
    {
        if (dp[i + 1] == -MAXW)
        {
            cout << i <<"\n";
            break;
        }
    }

    long long r = 0;
    write[r] = pos[i]+1;
    r++;
    i = pos[i];

    while(prev1[i] != -1)
    {
        write[r] = prev1[i] + 1;
        r++;
        i = prev1[i];
    }
    for (i = r-1; i > -1; i--)
    {
        cout << write[i] << ' ';
    }
    return 0;
}
