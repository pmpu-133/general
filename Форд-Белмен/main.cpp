#include <bits/stdc++.h>

using namespace std;

struct edge{
    int st, fn, m;
};

vector <edge> e;

int const MAXN = 101, INF = 1e9;

int dp[MAXN][MAXN];

int main()
{
    freopen("avia.in", "r", stdin);
    //freopen("avia.out", "w", stdout);

    int n, m, k, s, f;

    cin >> n >> m >> k >> s >> f;

     for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            dp[i][j] = INF;

    for (int i = 0; i < MAXN; i++)
        dp[s][i] = 0;

    int st, fin, p;
    edge t;

    for (int i = 0; i < m; i++)
    {
        cin >> st >> fin >> p;
        t.st = st;
        t.fn = fin;
        t.m = p;
        e.push_back(t);
    }

    for (int i = 1; i <= k; i++)
        for (auto h: e){
            dp[h.fn][i] = min(dp[h.fn][i - 1], min(dp[h.fn][i], dp[h.st][i - 1] + h.m));
             }
    if (dp[f][k] == INF)
        cout << -1;
    else
        cout << dp[f][k];

     /*for (int i = 0; i <= k; i++){
        for (int j = 0; j <= n; j++)
            cout << dp[j][i] << " ";
        cout <<"\n";
     }*/
    return 0;
}
