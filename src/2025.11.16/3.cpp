#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k;
struct node
{
    int v, w;
    node() {}
    node(int _v, int _w)
    {
        v = _v;
        w = _w;
    }
};
vector<node> a[(int)2e5 + 5];
int dp[(int)2e5 + 5];
int _size[(int)2e5 + 5];
int vis[(int)2e5 + 5];
int root = 0;
int tmp[(int)2e6 + 5];
int cnt = 0;
int dis[(int)2e5 + 5];
int diss[(int)2e5 + 5];
int tmpp[(int)2e6 + 5];
int ans = INT_MAX;
int sum;
unordered_map<int, int> tot;
// int tot[(int)2e6 + 5];
constexpr int inf = INT_MAX;
void getrt(int x, int fa)
{
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
    tmp[++cnt] = dis[x];
    tmpp[cnt] = diss[x];
    for (auto &i : a[x])
    {
        int v = i.v;
        int w = i.w;
        if (v == fa || vis[v])
            continue;
        dis[v] = dis[x] + w;
        diss[v] = diss[x] + 1;
        dfs(v, x);
    }
}
void doit(int x)
{
    vis[x] = 1;
    tot[0] = 0;
    queue<int> q;
    for (auto &i : a[x])
    {
        int v = i.v;
        int w = i.w;
        if (vis[v])
            continue;
        cnt = 0;
        dis[v] = w;
        diss[v] = 1;
        dfs(v, x);
        for (int i = 1; i <= cnt; i++)
        {
            if (k >= tmp[i])
            {
                ans = min(ans, tmpp[i] + tot[k - tmp[i]]);
                // if (k == tmp[i])
                // {
                // ans = min(ans, tmpp[i] + 1);
                // }
            }
        }
        for (int i = 1; i <= cnt; i++)
        {
            q.push(tmp[i]);
            tot[tmp[i]] = min(tot[tmp[i]], tmpp[i]);
        }
    }
    while (!q.empty())
    {
        tot[q.front()] = inf;
        q.pop();
    }
}
void solve(int x)
{
    vis[x] = 1;
    doit(x);
    for (auto &i : a[x])
    {
        int v = i.v;
        int w = i.w;
        if (vis[v])
            continue;
        root = 0;
        dp[0] = n;
        sum = _size[v];
        getrt(v, x);
        solve(root);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[u + 1].emplace_back(v + 1, w);
        a[v + 1].emplace_back(u + 1, w);
    }
    root = 0;
    dp[0] = n;
    sum = n;
    for (int i = 0; i <= 1.5 * k; i++)
    {
        tot[i] = inf;
    }
    getrt(1, 0);
    solve(root);
    cout << (ans == INT_MAX ? -1 : ans) << endl;
    return 0;
}