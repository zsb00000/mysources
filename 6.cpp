#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 9998244353;
int n, m;
int s[2005];
int a[2005][2005];
int tot = 1;
int f[2005][4005];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            s[i] = (s[i] + a[i][j]) % mod;
        }
        tot = tot * (s[i] + 1) % mod;
    }
    tot -= 1;
    for (int k = 1; k <= m; k++)
    {
        memset(f, 0, sizeof(f));
        f[0][n] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int d = -i; d <= i; d++)
            {
                f[i][d + n] = (f[i][d + n] + f[i - 1][d + n] + f[i - 1][d - 1 + n] * a[i][k] % mod + f[i - 1][d + 1 + n] * (s[i] - a[i][k]) % mod) % mod;
            }
        }
    }
    return 0;
}