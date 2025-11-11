#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int mod = 100003;
int poww(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * a % mod;
        }
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}
signed main()
{
    int m, n;
    cin >> m >> n;
    int ans = (poww(m, n) - m * (poww(m - 1, n - 1) % mod + mod) % mod) % mod;
    cout << (ans + mod) % mod;
    return 0;
}