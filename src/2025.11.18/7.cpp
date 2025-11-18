#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k;
int a[(int)3e5 + 5];
struct node
{
    int val, id;
    bool operator<(const node &x) const { return val < x.val; }
};
struct _list
{
    int l, r;
    int val;
} p[(int)3e5 + 5];
priority_queue<node> q;
bool vis[(int)3e5 + 5];
void del(int x)
{
    p[x].l = p[p[x].l].l;
    p[x].r = p[p[x].r].r;
    p[p[x].l].r = x;
    p[p[x].r].l = x;
}
signed main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        q.push({a[i], i});
        p[i].val = a[i];
        p[i].l = i - 1;
        p[i].r = i + 1;
    }
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        while ((!q.empty()) && (vis[q.top().id]))
            q.pop();
        int id = q.top().id;
        int val = q.top().val;
        if (val < 0)
            break;
        ans += val;
        q.pop();
        // vis[id] = 1;
        vis[p[id].l] = vis[p[id].r] = 1;
        int res = p[p[id].l].val + p[p[id].r].val - p[id].val;
        p[id].val = res;
        q.push({res, id});
        del(id);
    }
    cout << ans << endl;
    return 0;
}