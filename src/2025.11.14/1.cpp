#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 998244353;
typedef long long ll;
ll fac[(int)1e5 + 5];
ll inv[(int)1e5 + 5];
int a[3005];
vector<int> x;
int n, k;
int _gcd[15][15] = {{},
                    {-1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                    {-1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2},
                    {-1, 1, 1, 3, 1, 1, 3, 1, 1, 3, 1},
                    {-1, 1, 2, 1, 4, 1, 2, 1, 4, 1, 2},
                    {-1, 1, 1, 1, 1, 5, 1, 1, 1, 1, 5},
                    {-1, 1, 2, 3, 2, 1, 6, 1, 2, 3, 2},
                    {-1, 1, 1, 1, 1, 1, 1, 7, 1, 1, 1},
                    {-1, 1, 2, 1, 4, 1, 2, 1, 8, 1, 2},
                    {-1, 1, 1, 3, 1, 1, 3, 1, 1, 9, 1},
                    {-1, 1, 2, 1, 2, 5, 2, 1, 2, 1, 10}};
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
void pre()
{
    fac[0] = 1;
    for (int i = 1; i <= n + 1; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
    }
    inv[n + 1] = poww(fac[n + 1], mod - 2);
    for (int i = n; i >= 0; i--)
    {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
}
inline ll c(int n, int m)
{
    if (n < m)
        return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int main()
{
    freopen("permutation.in", "r", stdin);
    freopen("permutation.out", "w", stdout);
    cin >> n >> k;
    if (n == 1)
        return cout << 0 << endl, 0;
    if (n == k)
    {
        pre();
        cout << fac[n] << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    if (n <= 10)
    {
        int ans = 0;
        do
        {
            bool flag = 1;
            for (int i = 2; i <= n && flag; i++)
            {
                if (_gcd[a[i]][a[i - 1]] == k)
                {
                    flag = 0;
                }
            }
            ans += flag;
        } while (next_permutation(a + 1, a + 1 + n));
        cout << ans << endl;
        return 0;
    }
    else if (n <= 20)
    {
        int ans = 0;
        do
        {
            bool flag = 1;
            for (int i = 2; i <= n && flag; i++)
            {
                if (__gcd(a[i], a[i - 1]) == k)
                {
                    flag = 0;
                }
            }
            ans += flag;
        } while (next_permutation(a + 1, a + 1 + n));
        cout << ans << endl;
        return 0;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (i % k == 0)
            {
                x.push_back(i);
            }
        }
        if (x.empty())
        {
            pre();
            cout << fac[n] << endl;
            return 0;
        }
        else
        {
            pre();
            ll ans = 0;
            for (int i = 0; i <= x.size(); i++)
            {
                ll res = c(x.size(), i) * fac[n - i] % mod * fac[i] % mod;
                if (i & 1)
                    ans = (ans - res + mod) % mod;
                else
                    ans = (ans + res) % mod;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
/*
39916800
479001600
*/