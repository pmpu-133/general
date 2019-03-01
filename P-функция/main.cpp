#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 150001;

long long p[MAXN];

string s;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    long long j = 0, n, sum = 0;

    cin >> s;

    p[0] = 0;

    n = s.length();

    for (int i = 1; i < n; i++) {
        j = p[i - 1];
        while(j > 0 && s[i] != s[j])
            j = p[j - 1];
        if(s[i] == s[j])
            j++;
        p[i] = j;
    }

    for (int i = 0; i < n; i++)
        sum += p[i];

    cout << sum;

    return 0;
}
