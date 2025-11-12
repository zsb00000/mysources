#include <bits/stdc++.h>
#define int long long
using namespace std;
struct ball
{
    int x, y, z;
};
int father[(int)1e5 + 5];
int find(int x)
{
    if (father[x] != x)
        father[x] = find(father[x]);
    return father[x];
}
void unionn(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
        father[fx] = fy;
}
bool isqie(int x, int y, vector<ball> &a, int r)
{
    int dx = a[x].x - a[y].x;
    int dy = a[x].y - a[y].y;
    int dz = a[x].z - a[y].z;
    return dx * dx + dy * dy + dz * dz <= 4 * r * r;
}
void solve()
{
    int n, h, r;
    cin >> n >> h >> r;
    vector<ball> a(n + 5);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    for (int i = 1; i <= n; i++)
    {
        father[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (isqie(i, j, a, r))
            {
                unionn(i, j);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i].z <= r)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[j].z + r >= h)
                {
                    if (find(i) == find(j))
                    {
                        cout << "Yes\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "No\n";
    return;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}