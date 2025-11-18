#include <bits/stdc++.h>
using namespace std;
constexpr long long mod = 1e9 + 7;
typedef long long ll;
ll fac[(int)1e7 + 5];
ll inv[(int)1e7 + 5];
int maxn = 0;
int sum = 0;
int vis[(int)1e7 + 5];
ll poww(ll a, int b)
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
void pre()
{
    fac[0] = 1;
    for (int i = 1; i <= maxn; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
    }
    inv[maxn] = poww(fac[maxn], mod - 2);
    for (int i = maxn - 1; i >= 0; i--)
    {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
}
inline int c(int n, int m)
{
    if (n < m)
        return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
signed main()
{
    int l, r;
    cin >> l >> r;
    maxn = r + 1;
    pre();
    for (int i = l; i <= r; i++)
    {
        if (!vis[i])
        {
            sum++;
            for (int j = i + i; j <= r; j += i)
            {
                vis[j] = 1;
            }
        }
    }
    ll ans = 0;
    int n = r - l + 1;
    for (int i = sum; i <= n; i++)
    {
        ll res = 1ll * i * sum % mod * c(n - sum, n - i) % mod * fac[n - i] %
                 mod * fac[i - 1] % mod;
        ans = (ans + res) % mod;
    }
    cout << ans << endl;
    return 0;
}
