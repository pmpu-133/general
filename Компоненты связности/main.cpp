#include <bits/stdc++.h>

using namespace std;

const int N = 10000, M = 100;

int pr[M];

vector<int> y[N];

void dfs(int v)
{
    pr[v] = true;
     for (int u : y[v]) {
         if (!pr[u])
            dfs(u);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int m, n, l, r;

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        cin >> l >> r;
        y[l].push_back(r);
        y[r].push_back(l);
    }

    int answer = 0;

    for (int i = 1; i <= n; i++)
        if (!pr[i])
        {
            answer++;
            dfs(i);
        }
    cout << answer;
    return 0;
}
