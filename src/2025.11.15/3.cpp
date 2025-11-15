#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[(int)1e4 + 5];
vector<int> b[(int)1e4 + 5];
int s, t;
int out[(int)1e4 + 5];
bool ok[(int)1e4 + 5];
void bfs()
{
    queue<int> q;
    vector<int> vis(n + 1, 0);
    q.push(t);
    vis[t] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : b[u])
        {
            if (vis[v])
                continue;
            vis[v] = 1;
            q.push(v);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int v : a[i])
        {
            if (!vis[v])
            {
                ok[i] = 1;
            }
        }
    }
}
void bbfs()
{
    queue<int> q;
    vector<int> vis(n + 1, 0);
    q.push(s);
    vis[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : a[u])
        {
            if (vis[v] || ok[v])
                continue;
            vis[v] = vis[u] + 1;
            q.push(v);
        }
    }
    cout << (vis[t] == 0 ? -1 : vis[t]) << "\n";
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        b[v].push_back(u);
        out[u]++;
    }
    cin >> s >> t;
    bfs();
    if (ok[s])
        cout << -1 << "\n";
    else
        bbfs();
    // cout << -1 << "\n";
    return 0;
}