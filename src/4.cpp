#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod = 998244353;
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
    int n, k;
    cin >> n >> k;
    cout << poww(poww(2, k) - 1, n);
    return 0;
}