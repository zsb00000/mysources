#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod = 998244853;
int n;
typedef long long ll;
ll fac[(int)8e5 + 5];
ll inv[(int)8e5 + 5];
int a[(int)2e5 + 5];
int b[(int)2e5 + 5];
int maxx = 0;
ll poww(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * a % mod;
        }
        b >>= 1, a = a * a % mod;
    }
    return ans;
}
inline ll c(int n, int m)
{
    if (n < m)
        return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
signed main()
{
    freopen("flower.in", "r", stdin);
    freopen("flower.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        maxx = max(maxx, max(a[i], b[i]));
    }
    fac[0] = 1;
    for (int i = 1; i <= maxx * 4; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
    }
    inv[maxx * 4] = poww(fac[maxx * 4], mod - 2);
    for (int i = maxx * 4 - 1; i >= 0; i--)
    {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i - 1; j++)
        {
            ll res = c(a[i] + a[j] + b[i] + b[j], a[i] + a[j]);
            ans = (ans + res) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}
/*
3
1 1
2 1
1 1
*/