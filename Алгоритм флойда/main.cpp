#include <bits/stdc++.h>

using namespace std;

const int N = 101 , INF = 1e5;

int dp[N][N];

bool circle[N];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k;

    cin >> n;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            dp[i][j] = INF;
        }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            cin >> k;
            if (k != 0)
                dp[i][j] = k;
            if (i == j && k >= 0)
                dp[i][j] = 0;

        }

    for(k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++){
                if (dp[i][k] < INF && dp[k][j] < INF)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                if(dp[i][j] < -INF)
                    dp[i][j] = -INF;
            }

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(dp[i][j] + dp[j][i] < 0){
                    circle[i] = true;
                    circle[j] = true;
                }

    bool t = false;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            //cout << dp[i][j] << " ";
            if (dp[i][j] > 1e4 )
                cout << 0 << " ";
            else {
                for(k = 1; k <= n; k++)
                {
                    if(dp[i][k] < 1e4 && dp[k][j] < 1e4 && circle[k]){
                        cout << 2 << " ";
                        t = true;
                        break;
                    }
                }
                if (!t)
                    cout << 1 << " ";
            }
            t = false;
        }
        cout << "\n";
    }
    return 0;
}
