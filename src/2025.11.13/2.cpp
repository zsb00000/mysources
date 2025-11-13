#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int root = 0;
int tree[(int)3.2e6 + 5][3];
int a[(int)1e5 + 5];
int tot = 0;
void insert(int x)
{
    int rt = root;
    for (int i = 30; i >= 0; i--)
    {
        int bit = (x >> i) & 1;
        if (tree[bit][rt] == -1)
        {
            tree[bit][rt] = ++tot;
        }
        rt = tree[bit][rt];
    }
}
int find(int x)
{
    int rt = root;
    int ans = 0;
    for (int i = 30; i >= 0; i--)
    {
        int bit = ((x >> i) & 1) ^ 1;
        if (tree[bit][rt] != -1)
        {
            ans |= (1ll << i);
            rt = tree[bit][rt];
        }
        else
        {
            rt = tree[bit ^ 1][rt];
        }
    }
    return ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(tree, -1, sizeof(tree));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        insert(a[i]);
    }
    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, find(a[i]));
        // cout << find(a[i]) << ' ';
    }
    // cout << '\n';
    cout << ans << '\n';
    return 0;
}