#include <bits/stdc++.h>
using namespace std;
int n, m;
struct node
{
    int v, w;
    node() {}
    node(int a, int b) : v(a), w(b) {}
};
vector<node> a[(int)1e5 + 5];
int _size[(int)1e5 + 5];
int dp[(int)1e5 + 5];
int dis[(int)1e5 + 5];
int tmp[(int)1e5 + 5];
int q[(int)1e5 + 5];
int num = 0;
int root = 0;
int sum = 0;
unordered_map<int, int> tot;
int ans[(int)1e5 + 5];
bool vis[(int)1e5 + 5];
void getrt(int x, int fa)
{
    // cout << x << endl;
    _size[x] = 1;
    dp[x] = 0;
    for (auto &i : a[x])
    {
        int v = i.v;
        int w = i.w;
        if (v == fa || vis[v])
            continue;
        getrt(v, x);
        _size[x] += _size[v];
        dp[x] = max(dp[x], _size[v]);
    }
    dp[x] = max(dp[x], sum - _size[x]);
    if (dp[x] < dp[root])
    {
        root = x;
    }
}
void dfs(int x, int fa)
{
    tmp[++num] = dis[x];
    for (auto &i : a[x])
    {
        int v = i.v;
        int w = i.w;
        if (v == fa || vis[v])
            continue;
        dis[v] = dis[x] + w;
        dfs(v, x);
    }
}
void doit(int x)
{
    queue<int> qq;
    for (auto &i : a[x])
    {
        int v = i.v;
        int w = i.w;
        if (vis[v])
            continue;
        num = 0;
        dis[v] = w;
        dfs(v, x);
        for (int j = 1; j <= num; j++)
        {
            for (int k = 1; k <= m; k++)
            {
                if (q[k] >= tmp[j])
                    ans[k] |= tot[q[k] - tmp[j]];
            }
        }
        for (int j = 1; j <= num; j++)
        {
            qq.push(tmp[j]);
            tot[tmp[j]]++;
        }
    }
    while (!qq.empty())
    {
        tot[qq.front()] = 0;
        qq.pop();
    }
    // tot.clear();
}
void solve(int x)
{
    // cout << x << endl;
    tot[0] = 1;
    vis[x] = 1;
    doit(x);
    for (auto &i : a[x])
    {
        int v = i.v;
        int w = i.w;
        if (vis[v])
            continue;
        sum = _size[v];
        dp[0] = n;
        root = 0;
        getrt(v, x);
        if (vis[root])
            throw runtime_error("");
        solve(root);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].emplace_back(v, w);
        a[v].emplace_back(u, w);
    }
    for (int i = 1; i <= m; i++)
    {
        int k;
        cin >> k;
        q[i] = k;
    }
    sum = n;
    root = 0;
    dp[0] = n;
    getrt(1, 0);
    solve(root);
    for (int i = 1; i <= m; i++)
    {
        if (ans[i])
        {
            cout << "AYE\n";
        }
        else
        {
            cout << "NAY\n";
        }
    }
    return 0;
}