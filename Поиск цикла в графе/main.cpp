#include <bits/stdc++.h>

using namespace std;

vector <int> a[100001], write;

int color[100001], prev1[100001];
int ans = 0;

void dfs(int c)
{
    color[c] = 1;
    for(int v: a[c]){
        if (color[v] == 0){
            prev1[v] = c;
            dfs(v);
        }
        if (color[v] == 1){
            ans = c;
            prev1[v] = c;
        }
    }
    color[c] = 2;
}

int main()
{
    //freopen("cycle.in", "r", stdin);
    //freopen("cycle.out", "w", stdout);

    int n, m, l, r;

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> l >> r;
        a[l].push_back(r);
    }


    for (int i = 1; i <= n; i++)
        if (color[i] == 0)
            dfs(i);

    if (ans == 0)
        cout << "NO";
    else
    {
        cout << "YES" << endl;
        for(int i = prev1[ans]; i != ans; i = prev1[i])
            write.push_back(i);
        write.push_back(ans);
    }

    reverse(write.begin(), write.end());
    for (int v: write)
        cout << v << ' ';

    return 0;
}
