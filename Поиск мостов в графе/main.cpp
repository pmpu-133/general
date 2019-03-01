#include <bits/stdc++.h>

using namespace std;

int const N = 20001, M = 200001;

bool pv[N], pr[M];

int tin[M], dp[M];

int timer = 1, r = 0;

vector<pair<int, int>> y[N];
vector<int> write;

void dfs(int v, int id)
{
    pv[v] = true;
    pr[id] = true;
    tin[v] = timer++;
    for (pair<int, int> u : y[v]) {
        if (!pv[u.first])
            dfs(u.first, u.second);
    }
    dp[v] = tin[v];
     for (pair<int, int> u : y[v]) {
        if (!pr[u.second])
            dp[v] = min(dp[v], tin[u.first]);
        else
        {
            if (tin[v] < tin[u.first])
            {
                dp[v] = min(dp[v], dp[u.first]);
                if (tin[v] < dp[u.first])
                    write.push_back(u.second);
            }
        }

    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m, l, r;

    cin >> n >> m;

    for(int i = 1; i <= m; i++)
    {
        cin >> l >> r;
        y[l].push_back({r, i});
        y[r].push_back({l, i});
    }

    dfs(1, 0);
   // for(int i = 1; i <= 6; i++)
       // cout << tin[i] << ' ' << dp[i] <<"\n";

    cout << write.size() << "\n";

    sort(write.begin(), write.end());

    for (int u : write)
        cout << u << " ";
    return 0;
}
