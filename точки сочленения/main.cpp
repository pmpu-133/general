#include <bits/stdc++.h>

using namespace std;

int const MAXN = 20001;

vector < vector< int > > g;

vector<bool> used;

bool us[MAXN];

int timer, answer;

vector<int> tin, fup, write;

void dfs (int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    int children = 0;

    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p) continue;
        if (used[to])
            fup[v] = min (fup[v], tin[to]);
        else {
            dfs (to, v);
            fup[v] = min (fup[v], fup[to]);
            if (fup[to] >= tin[v] && p != -1 && !us[v]){
                write.push_back(v);
                us[v] = true;
            }
            ++children;
        }
    }

    if (p == -1 && children > 1 && !us[v]){
        write.push_back(v);
        us[v] = true;
    }
}
int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m, a, b;

    cin >> n >> m;

    g.resize(MAXN);

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    timer = 0;
    used.assign (n, false);
    tin.resize (n);
    fup.resize (n);
    dfs (0);

    cout << write.size() <<endl;
    sort(write.begin(), write.end());
    for (int i : write)
        cout << i + 1 << ' ';
}
