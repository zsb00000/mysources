#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int t, n, m, p;
    cin >> t >> n >> m >> p;
    int ans = 1;
    for (int i = n - 2 * m + 2; i <= n - m + 1; i++)
    {
        ans = ans * i % p;
    }
    cout << ans << endl;
    return 0;
}