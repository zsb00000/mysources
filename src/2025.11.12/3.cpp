#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int mod = 1e9 + 7;
constexpr int s = 2050;
constexpr int maxx = 8005;
int n;
int a[(int)2e5 + 5];
int b[(int)2e5 + 5];
ll fac[(int)2e5 + 5];
ll inv[(int)2e5 + 5];
ll f[5005][5005];
ll poww(int a, int b)
{
    ll res = 1;
    ll base = a;
    while (b)
    {
        if (b & 1)
        {
            res = res * base % mod;
        }
        base = base * base % mod;
        b >>= 1;
    }
    return res;
}
inline int c(int n, int m)
{
    if (m > n || m < 0)
        return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int main()
{
    // cout << poww(2, mod - 2) << endl;
    // freopen("flower.in", "r", stdin);
    // freopen("flower.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    fac[0] = 1;
    for (int i = 1; i <= maxx; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
    }
    inv[maxx] = poww(fac[maxx], mod - 2);
    for (int i = maxx - 1; i >= 0; i--)
    {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
    for (int i = 1; i <= n; i++)
    {
        f[s - a[i]][s - b[i]]++;
    }
    for (int i = 1; i <= 2 * s; i++)
    {
        for (int j = 1; j <= 2 * s; j++)
        {
            f[i][j] = (f[i][j] + f[i - 1][j] + f[i][j - 1]) % mod;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + f[s + a[i]][s + b[i]] % mod - c(2 * a[i] + 2 * b[i], 2 * a[i]) + mod) % mod;
    }
    cout << ans * 500000004 % mod << "\n";
    return 0;
}