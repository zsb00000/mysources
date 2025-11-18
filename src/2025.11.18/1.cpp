#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = LLONG_MAX;
struct edge
{
    int to;
    int next;
    int val;
} e[(int)1e5 + 5];
int cnt = 1;
int n, m, s, t;
int head[(int)1e5 + 5];
int dis[(int)1e5 + 5];
int now[(int)1e5 + 5];
inline void add(int u, int v, int w)
{
    e[++cnt].to = v;
    e[cnt].next = head[u];
    e[cnt].val = w;
    head[u] = cnt;

    e[++cnt].to = u;
    e[cnt].val = 0;
    e[cnt].next = head[v];
    head[v] = cnt;
}
bool bfs()
{
    for (int i = 1; i <= n; i++)
    {
        dis[i] = inf;
    }
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    now[s] = head[s];
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = e[i].next)
        {
            int v = e[i].to;
            if (e[i].val > 0 && dis[v] == inf)
            {
                dis[v] = dis[x] + 1;
                now[v] = head[v];
                q.push(v);
                if (v == t)
                    return 1;
            }
        }
    }
    return 0;
}
int dfs(int x, int sum)
{
    int k = 0, res = 0;
    if (x == t)
        return sum;
    for (int i = now[x]; i && sum; i = e[i].next)
    {
        int v = e[i].to;
        now[x] = i;
        if ((e[i].val > 0) && (dis[v] == dis[x] + 1))
        {
            k = dfs(v, min(e[i].val, sum));
            e[i].val -= k;
            e[i ^ 1].val += k;
            sum -= k;
            res += k;
        }
    }
    return res;
}
signed main()
{
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    int ans = 0;
    while (bfs())
    {
        ans += dfs(s, inf);
    }
    cout << ans << endl;
    return 0;
}