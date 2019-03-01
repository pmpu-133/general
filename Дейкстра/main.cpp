#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5001, INF = 1e9;

int dp[MAXN], prev1[MAXN];

bool used[MAXN];

int  c = 0, c1 = 0;

vector<int> write;

vector < vector < pair<int, int> > > g;

int main()
{

    freopen("distance.in", "r", stdin);
   // freopen("distance.out", "w", stdout);

    g.resize(MAXN);

    int n, m, s, f, a, b, w;


    cin >> n >> m >> s >> f;

    for (int i = 0; i < m; i++) {

        cin >> a >> b >> w;

        g[a - 1].push_back({b - 1, w});
        g[b - 1].push_back({a - 1, w});
    }

    fill(dp, dp + MAXN, INF);

    dp[s - 1] = 0;

    for (int x = 0; x < n; x++) {

        int p = -1;

        for (int i = 0; i < n; i++)
            if(!used[i] && (p == -1 || dp[i] < dp[p]))
                p = i;

      // if (dp[p] == INF)
         //   break;

        used[p] = true;

        for (int i = 0; i < g[p].size(); i++) {
            int to = g[p][i].first;
            if (dp[p] + g[p][i].second < dp[to]) {
                dp[to] = dp[p] + g[p][i].second;
                prev1[to] = p;
            }
        }
    }
    for (int i = f - 1; i != s - 1; i = prev1[i])
        write.push_back (i + 1);

    write.push_back (s);

    reverse (write.begin(), write.end());

    cout << dp[f - 1] << endl << write.size()  << endl;

    for (int i = 0; i < write.size(); i++)
        cout << write[i] << " ";


    return 0;
}
