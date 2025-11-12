#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 4 * (1 << 22);
int n, m;
int a[(int)2e6 + 5];
int ans[(int)2e6 + 5];
int root = 0;
int tot = 0;
struct trie
{
    int ls, rs;
    // ls 1
    // rs 0
    // int ed;
    trie() : ls(-1), rs(-1) {};
} tree[maxn];
inline int nailong(int x, int y)
{
    int z = x ^ y;
    return __builtin_popcount(z);
}
void build(int x)
{
    int rt = root;
    for (int i = 0; i <= 21; i++)
    {
        if (x & (1 << i))
        {
            if (tree[rt].ls == -1)
            {
                tree[rt].ls = ++tot;
            }
            rt = tree[rt].ls;
        }
        else
        {
            if (tree[rt].rs == -1)
            {
                tree[rt].rs = ++tot;
            }
            rt = tree[rt].rs;
        }
    }
    // tree[rt].ed++;
}
int _find(int x)
{
    int cnt = 0;
    int rt = root;
    for (int i = 0; i <= 21; i++)
    {
        if (x & (1 << i))
        {
            if (tree[rt].rs == -1)
            {
                rt = tree[rt].ls;
            }
            else
            {
                rt = tree[rt].rs;
                cnt++;
            }
        }
        else
        {
            if (tree[rt].ls == -1)
            {
                rt = tree[rt].rs;
            }
            else
            {
                rt = tree[rt].ls;
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
    freopen("purple.in", "r", stdin);
    freopen("purple.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        // build(a[i]);
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     // _find(a[i]);
    //     cout << _find(a[i]) << " ";
    // }
    // cout << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ans[i] = max(ans[i], nailong(a[i], a[j]));
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}