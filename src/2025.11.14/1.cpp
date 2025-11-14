#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod = 998244353;
int g[15][15];
int dp[2048][15][15];
int fac[3005];
int inv[3005];
int f[3005];
inline int c(int n, int m)
{
    if (n < m)
        return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int poww(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
signed main()
{
    freopen("permutation.in", "r", stdin);
    freopen("permutation.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int t = n / k;
    vector<int> s;
    for (int i = 1; i <= n; i++)
    {
        if (i % k == 0)
            s.push_back(i);
    }
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t; j++)
        {
            if (__gcd(s[i], s[j]) == k)
            {
                g[i][j] = 1;
            }
        }
    }
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
    }
    inv[n] = poww(fac[n], mod - 2);
    for (int i = n - 1; i >= 0; i--)
    {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
    if (t == 0)
    {
        cout << fac[n] << endl;
        return 0;
    }
    for (int i = 0; i < t; i++)
    {
        dp[1 << i][i][0] = 1;
    }
    for (int mask = 0; mask < (1 << t); mask++)
    {
        for (int i = 0; i < t; i++)
        {
            if (!(mask & (1 << i)))
                continue;
            for (int a = 0; a < t; a++)
            {
                if (!dp[mask][i][a])
                    continue;
                for (int j = 0; j < t; j++)
                {
                    if (mask & (1 << j))
                        continue;
                    int nmask = mask | (1 << j);
                    int na = a + g[i][j];
                    if (a >= t)
                        continue;
                    dp[nmask][j][na] = (dp[nmask][j][na] + dp[mask][i][a]) % mod;
                }
            }
        }
    }

    for (int i = 0; i < t; i++)
    {
        for (int a = 0; a < t; a++)
        {
            f[a] = (f[a] + dp[(1 << t) - 1][i][a]) % mod;
        }
    }
    int ans = 0;
    for (int i = 0; i < t; i++)
    {
        ans = (ans + f[i] * c(n - i, t)) % mod;
    }
    ans = ans * fac[n - t] % mod;
    cout << ans << endl;
    return 0;
}