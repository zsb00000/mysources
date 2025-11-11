#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 998244353;
int id;
int n, m;
vector<int> a[(int)1e6 + 5];
int f[(int)1e6 + 5];
int sum[(int)1e6 + 5];
int indu[(int)1e6 + 5];
int main()
{
    cin >> id;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        // a[v].push_back(u);
        indu[u]++;
    }
    for (int i = 1; i <= n; i++)
    {
        f[i] = indu[i] + 1;
        for (int j : a[i])
        {
            f[i] = (f[i] + (sum[i - 1] - sum[j - 1] + mod) % mod) % mod;
        }
        sum[i] = (sum[i - 1] + f[i]) % mod;
    }
    cout << sum[n] << endl;
    return 0;
}