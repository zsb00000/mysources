#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod = 998244353;
struct node
{
    int val;
    int w;
    bool operator<(const node &x) const
    {
        return val > x.val;
    }
    node() {}
    node(int a, int b) : val(a), w(b) {}
} c[(int)2e5 + 5];
int n;
int a[(int)1e5 + 5];
int b[(int)1e5 + 5];
int f[5005 << 1][5005];
int tmp[2][(int)1e5 + 5];
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
    cin >> n;
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c[++tot] = node(a[i], 0);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        c[++tot] = node(b[i], 1);
    }
    sort(c + 1, c + 1 + tot);
    for (int i = 1; i <= tot; i++)
    {
        tmp[1][i] += tmp[1][i - 1];
        tmp[0][i] += tmp[0][i - 1];
        tmp[c[i].w][i] += 1;
    }
    f[0][0] = 1;
    for (int i = 1; i <= tot; i++)
    {
        f[i][0] = 1;
        for (int j = 1; j <= min(n, i); j++)
        {
            if (tmp[!c[i].w][i] >= j)
                f[i][j] = (f[i - 1][j - 1] * c[i].val % mod * (tmp[!c[i].w][i] - j + 1) % mod + f[i - 1][j]) % mod;
            else
                f[i][j] = f[i - 1][j] % mod;
        }
    }
    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        res = res * i % mod;
    }
    cout << poww(res, mod - 2) * f[tot][n] % mod << endl;
    return 0;
}