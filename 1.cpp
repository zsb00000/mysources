#include <bits/stdc++.h>
#define int __int128
using namespace std;
long long n, m, p;
int fac[(int)4e5 + 5];
int inv[(int)4e5 + 5];
int poww(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}
int c(int n, int m)
{
    if (n < m)
        return 0;
    if (m == 0)
        return 1;
    if (n < p && m < p)
    {
        return fac[n] * inv[m] % p * inv[n - m] % p;
    }
    return c(n % p, m % p) % p * c(n / p, m / p) % p;
}
void pre()
{
    fac[0] = 1;
    for (int i = 1; i < p; i++)
    {
        fac[i] = fac[i - 1] * i % p;
    }
    inv[p - 1] = poww(fac[p - 1], p - 2);
    for (int i = p - 2; i >= 0; i--)
    {
        inv[i] = inv[i + 1] * (i + 1) % p;
    }
}
void solve()
{
    cin >> n >> m >> p;
    pre();
    cout << (long long)c(n + m, n) % p << endl;
}
signed main()
{
    short t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}