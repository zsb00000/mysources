#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 1e9 + 7;
typedef long long ll;
int l, r;
int vis[(int)1e7 + 5];
ll fac[(int)1e7 + 5];
ll inv[(int)1e7 + 5];
ll poww(int a, int b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * a % mod;
        }
        b >>= 1, a = 1ll * a * a % mod;
    }
    return ans;
}
inline int c(int n, int m)
{
    if (n < m)
        return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int main()
{
    memset(vis, 0, sizeof(vis));
    cin >> l >> r;
    int n = r - l + 1;
    fac[0] = 1;
    for (int i = 1; i <= r; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
    }
    inv[r] = poww(fac[r], mod - 2);
    for (int i = r - 1; i >= 0; i--)
    {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
    ll ans = 0;
    int sum = 0;
    for (int i = l; i <= r; i++)
    {
        if (l == 1)
        {
            cout << fac[r] * (r + 1) % mod * poww(2, mod - 2) % mod << endl;
            return 0;
        }
        if (!vis[i])
        {
            sum++;
            for (int j = i; j <= r; j += i)
            {
                vis[j] = 1;
            }
        }
    }
    cout << sum << endl;
    for (int i = 1; i <= n; i++)
    {
        ll res = sum * c(n - sum, n - i) % mod * i % mod * fac[n - i] % mod * fac[i - 1] % mod;
        cout << c(n - sum, n - i) << " " << i << " " << fac[n - i] << " " << fac[i - 1] << endl;
        ans = (ans + res) % mod;
    }
    cout << ans << endl;
    return 0;
}