#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
typedef long long ll;
struct node
{
    int v;
    ll w;
    node() {}
    node(int x, ll y) : v(x), w(y) {}
    bool operator<(const node &x) const
    {
        return w > x.w;
    }
};
vector<node> a[(int)2e5 + 5];
struct point
{
    int x, y;
    int id;
    bool operator<(const point &w) const
    {
        if (x == w.x)
            return y < w.y;
        else
            return x < w.x;
    }
} p[(int)2e5 + 5];
ll dis[(int)2e5 + 5];
inline ll get(point &a, point &b)
{
    return min(abs(a.x - b.x), abs(a.y - b.y));
}
signed main()
{
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    bool flag = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        dis[i] = LLONG_MAX;
        int x, y;
        cin >> x >> y;
        flag &= (x == y);
        p[i] = {x, y, i};
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        // w = min(w, get(p[u], p[v]));
        a[u].emplace_back(v, w);
        a[v].emplace_back(u, w);
    }
    // memset(dis, 0x3f, sizeof(dis));
    // if (m == 0)
    // {
    //     for (int i = 2; i <= n; i++)
    //     {
    //         cout << get(p[1], p[i]) << " ";
    //     }
    // }
    if (n <= 1000)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i != j)
                {
                    a[i].emplace_back(j, get(p[i], p[j]));
                    a[j].emplace_back(i, get(p[i], p[j]));
                }
            }
        }
        priority_queue<node> q;
        q.push(node(1, 0));
        dis[1] = 0;
        while (!q.empty())
        {
            int x = q.top().v;
            q.pop();
            for (auto &i : a[x])
            {
                int v = i.v;
                ll w = i.w;
                if (dis[v] > dis[x] + w)
                {
                    dis[v] = dis[x] + w;
                    q.push(node(v, dis[v]));
                }
            }
        }
        for (int i = 2; i <= n; i++)
        {
            cout << dis[i] << " ";
        }
    }
    else if (flag)
    {
        // cout << "here:" << endl;
        sort(p + 1, p + 1 + n);
        for (int i = 1; i < n; i++)
        {
            a[p[i].id].emplace_back(p[i + 1].id, get(p[i], p[i + 1]));
            a[p[i + 1].id].emplace_back(p[i].id, get(p[i], p[i + 1]));
        }
        priority_queue<node> q;
        q.push(node(1, 0));
        dis[1] = 0;
        while (!q.empty())
        {
            int x = q.top().v;
            q.pop();
            for (auto &i : a[x])
            {
                int v = i.v;
                ll w = i.w;
                if (dis[v] > dis[x] + w)
                {
                    dis[v] = dis[x] + w;
                    q.push(node(v, dis[v]));
                }
            }
        }
        for (int i = 2; i <= n; i++)
        {
            cout << dis[i] << " ";
        }
    }
    else
    {
        vector<int> vis(n + 5, 0);
        sort(p + 1, p + 1 + n);
        for (int i = 1; i < n; i++)
        {
            a[p[i].id].emplace_back(p[i + 1].id, get(p[i], p[i + 1]));
            a[p[i + 1].id].emplace_back(p[i].id, get(p[i + 1], p[i]));
        }
        sort(p + 1, p + 1 + n, [&](const point &x, const point &y)
             {if(x.y==y.y)return x.x<y.x;else return x.y<y.y; });
        for (int i = 1; i < n; i++)
        {
            a[p[i].id].emplace_back(p[i + 1].id, get(p[i], p[i + 1]));
            a[p[i + 1].id].emplace_back(p[i].id, get(p[i + 1], p[i]));
        }
        priority_queue<node> q;
        q.push(node(1, 0));
        dis[1] = 0;
        while (!q.empty())
        {
            int x = q.top().v;
            q.pop();
            if (vis[x])
                continue;
            vis[x] = 1;
            for (auto &i : a[x])
            {
                int v = i.v;
                int w = i.w;
                if ((!vis[v]) && dis[v] > dis[x] + w)
                {
                    dis[v] = dis[x] + w;
                    q.push(node(v, dis[v]));
                }
            }
        }
        for (int i = 2; i <= n; i++)
        {
            cout << dis[i] << " ";
        }
    }
    return 0;
}
/*
5 4
1 1
4 6
3 4
4 3
6 6
1 2 2
1 3 1
3 4 1
4 5 5
*/
/*
5 2
1 1
2 2
5 5
3 3
4 4
1 5 1
2 3 10
*/