#include <bits/stdc++.h>
using namespace std;
int n, m;
int _map[1005][1005];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int father[(int)1e6 + 5];
int _size[(int)1e6 + 5];
int vis[1005][1005];
int find(int x) { return x == father[x] ? x : father[x] = find(father[x]); }
void unionn(int x, int y)
{
    int rx = find(x);
    int ry = find(y);
    if (rx == ry)
        return;
    if (_size[rx] < _size[ry])
    {
        father[rx] = ry;
        _size[ry] += _size[rx];
    }
    else
    {
        father[ry] = rx;
        _size[rx] += _size[ry];
    }
}
int get(int x, int y) { return (x - 1) * n + y; }
void bfs(int a, int b)
{
    queue<pair<int, int>> q;
    q.push({a, b});
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (!(xx <= n && xx >= 1 && yy <= n && yy >= 1))
                continue;
            if (_map[xx][yy] == _map[x][y])
                continue;
            if (vis[xx][yy])
                continue;
            vis[xx][yy] = 1;
            unionn(get(xx, yy), get(x, y));
            q.push({xx, yy});
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char x;
            cin >> x;
            _map[i][j] = x - '0';
        }
    }
    for (int i = 1; i <= n * n; i++)
    {
        father[i] = i;
        _size[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!vis[i][j])
            {
                vis[i][j] = 1;
                bfs(i, j);
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << _size[find(get(x, y))] << endl;
    }
    return 0;
}