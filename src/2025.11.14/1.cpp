#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 998244353;
int a[3005];
int _gcd[15][15] = {{},
                    {-1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                    {-1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2},
                    {-1, 1, 1, 3, 1, 1, 3, 1, 1, 3, 1},
                    {-1, 1, 2, 1, 4, 1, 2, 1, 4, 1, 2},
                    {-1, 1, 1, 1, 1, 5, 1, 1, 1, 1, 5},
                    {-1, 1, 2, 3, 2, 1, 6, 1, 2, 3, 2},
                    {-1, 1, 1, 1, 1, 1, 1, 7, 1, 1, 1},
                    {-1, 1, 2, 1, 4, 1, 2, 1, 8, 1, 2},
                    {-1, 1, 1, 3, 1, 1, 3, 1, 1, 9, 1},
                    {-1, 1, 2, 1, 2, 5, 2, 1, 2, 1, 10}};
int main()
{
    // freopen("permutation.in", "r", stdin);
    // freopen("permutation.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    int ans = 0;
    do
    {
        bool flag = 1;
        for (int i = 2; i <= n && flag; i++)
        {
            if (_gcd[a[i]][a[i - 1]] == k)
            {
                flag = 0;
            }
        }
        ans += flag;
    } while (next_permutation(a + 1, a + 1 + n));
    cout << ans << endl;
    return 0;
}