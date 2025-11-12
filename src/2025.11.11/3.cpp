#include <bits/stdc++.h>
using namespace std;
bool a = 0;
constexpr int mod = 998244353;
typedef long long ll;
ll fac[(int)4e7 + 5];
ll inv[(int)4e7 + 5];
ll poww(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = 1ll * ans * a % mod;
        }
        b >>= 1;
        a = a * a % mod;
    }
    return ans % mod;
}
inline ll c(int n, int m)
{
    if (n < m || n < 0 || m < 0)
        return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int main()
{
    int n, k;
    cin >> n >> k;
    fac[0] = 1;
    for (int i = 1; i <= 2 * n; i++)
    {
        ll tmp = 1ll * fac[i - 1] * i % mod;
        fac[i] = tmp % mod;
        // cout<<fac[i]<<" ";
    }
    // cout<<endl;
    inv[2 * n] = poww(fac[2 * n], mod - 2);
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        // cout<<inv[i]<<" ";
        ll tmp = inv[i + 1] * (i + 1) % mod;
        inv[i] = tmp % mod;
        // cout<<inv[i]<<" ";
    }
    // cout<<endl;
    ll ans = 0;
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            ll res = c(i + 1, j) * c(n - i - 1, j - 1) % mod * c(2 * (n - i - j), k - i - j * 2) % mod;
            ans = (ans + res) % mod;
        }
    }
    cout << ans + (n == k) << endl;
    bool b = 0;
    // cout << (ll)(&b - &a) << endl;
    return 0;
}