#include <bits/stdc++.h>
using namespace std;
struct node
{
    int a, v;
} a[200005];
int f[25][200005];
int ans = 0;
int x[(int)2e5 + 5], y[(int)2e5 + 5], z[(int)2e5 + 5];
int main()
{
    int n, k, p;
    cin >> n >> k >> p;
    int d = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].a >> a[i].v;
        if (a[i].a < p)
            d = i;
        if (i >= x[a[i].a])
        {
            y[a[i].a] = z[a[i].a];
        }
        ans += y[a[i].a];
        z[a[i].a]++;
        x[a[i].a] = i;
        // f[0][i] = a[i].v;
    }
    // for (int j = 1; j <= 21; j++)
    // {
    //     for (int i = 1; i + (1 << j) - 1 <= n; i++)
    //     {
    //         f[j][i] = min(f[j - 1][i], f[j - 1][i + (1 << j - 1)]);
    //     }
    // }
    // int ans = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = i + 1; j <= n; j++)
    //     {
    //         if (a[i].a == a[j].a)
    //         {
    //             int m = log2(j - i + 1);
    //             if (min(f[m][i], f[m][j - (1 << m) + 1]) <= p)
    //             {
    //                 ans++;
    //             }
    //         }
    //     }
    // }
    cout << ans << endl;
    return 0;
}