#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 1000000007;
typedef long long ll;
int n;
ll dp[(int)5e6 + 5];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        for (int s = (a - 1) & a; s; s = a & (s - 1))
            (dp[s] = (dp[s] + dp[a] + 1) % mod);
        ans = (ans + dp[a]) % mod;
    }
    cout << ans << endl;
}