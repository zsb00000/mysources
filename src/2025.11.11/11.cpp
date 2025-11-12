#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr ll mod = 1e9 + 7;
ll n, k;
ll fac[(int)1e6 + 5];
ll inv[(int)1e6 + 5];
ll poww(ll a, ll b)
{
    ll ans = 1;
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
ll powww(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * a % (mod - 1);
        }
        a = a * a % (mod - 1);
        b >>= 1;
    }
    return ans;
}
inline ll c(int n, int m)
{
    if (n < m)
        return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

inline ll g(int x)
{
    return c(n, x) * (poww(2, powww(2, n - x) % (mod - 1)) % mod - 1) % mod;
}
int main()
{
    cin >> n >> k;
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
    ll ans = 0;
    for (int i = k; i <= n; i++)
    {
        int cnt = i - k;
        ll res = c(n, k) * g(i) % mod;
        if (cnt & 1)
        {
            ans = (ans - res + mod) % mod;
        }
        else
        {
            ans = (ans + res) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}