#include <bits/stdc++.h>

using namespace std;

const int N = 525000, M = 100000000, NUM = 20;

int dp[N][NUM], k[NUM][NUM], prev1[N][NUM], write[NUM];

int main(){

    freopen("salesman.in", "r", stdin);
    freopen("salesman.out", "w", stdout);

    int n;

    cin >> n;

    for (int mask = 0; mask < (1 << n); mask++)
        for (int last = 0; last < n; last++)
            dp[mask][last] = n * M;

    for (int i = 0; i < n; i++)
        dp[1 << i][i] = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> k[i][j];

    for (int mask = 1; mask < (1 << n); mask++)
        for (int last = 0; last < n; last++)
            for(int l = 0; l < n; l++)
                if (!(mask & (1 << l)))
                    if(mask & (1 << last))
                    {
                        if (dp[mask | (1 << l)][l] > dp[mask][last] + k[last][l])
                            prev1[mask | (1 << l)][l] = last;
                        dp[mask | (1 << l)][l] = min(dp[mask | (1 << l)][l], dp[mask][last] + k[last][l]);
                    }

    int mini = M * n, l;

    for (int last = 0; last < n; last++)
    {
        if (dp[(1 << n) - 1][last] < mini)
            l = last;
        mini = min(mini, dp[(1 << n) - 1][last]);
    }

    cout << mini << "\n";

    int mask = (1 << n) - 1, m, r = 0;

    write[r] = l + 1;
    r++;

    while (mask >= 1)
    {
        m = mask - (1 << l);
        l = prev1[mask][l];
        mask = m;
        write[r] = l + 1;
        r++;
    }

    for(int i = r - 2; i >= 0; i--)
        cout << write[i] << " ";

    return 0;
}
