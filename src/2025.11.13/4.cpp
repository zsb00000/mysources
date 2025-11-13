#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod = 1e4 + 7;
int n;
vector<int> a[(int)2e5 + 5];
int w[(int)2e5 + 5];
int ans = 0;
int maxx = -1;
void solve(int x)
{
    int max1 = 0, max2 = 0;
    int sum1 = 0, sum2 = 0;
    for (int i : a[x])
    {
        if (max1 < w[i])
        {
            max2 = max1;
            max1 = w[i];
        }
        else
        {
            if (max2 < w[i])
            {
                max2 = w[i];
            }
        }
        sum1 += w[i];
        sum2 += w[i] * w[i];
    }
    maxx = max(max1 * max2, maxx);
    ans = (ans + sum1 * sum1 - sum2 + mod) % mod;
}
signed main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        solve(i);
    }
    cout << maxx << " " << ans % mod << endl;
    return 0;
}