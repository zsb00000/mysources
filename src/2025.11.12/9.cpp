#include <bits/stdc++.h>
using namespace std;
long long ans[(int)1e6 + 5];
int main()
{
    int n;
    cin >> n;
    ans[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        ans[i] = ans[i - 1] * (4 * i - 2) / (i + 1);
    }
    cout << ans[n] << endl;
    return 0;
}