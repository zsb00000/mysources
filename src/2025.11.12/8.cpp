#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[25][25];
signed main()
{
    int n;
    cin >> n;
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 && j == 0)
                continue;
            dp[i][j] = (j <= (i - 1)) * dp[i - 1][j] + ((j - 1) <= i) * dp[i][j - 1];
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}