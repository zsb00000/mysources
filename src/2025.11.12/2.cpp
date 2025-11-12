#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 4 * (1 << 22);
int n, m;
int a[(int)2e6 + 5];
int ans[(int)2e6 + 5];
int main()
{
    // freopen("purple.in", "r", stdin);
    // freopen("purple.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    memset(ans, 0x3f, sizeof(ans));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ans[a[i]] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < (1 << m); j++)
        {
            ans[j ^ (1 << i)] = min(ans[j ^ (1 << i)], ans[j] + 1);
        }
    }
    for (int i = 0; i < n; i++)
    {
        int res = ((1 << m) - 1) ^ a[i];
        cout << m - ans[res] << " ";
    }
    return 0;
}