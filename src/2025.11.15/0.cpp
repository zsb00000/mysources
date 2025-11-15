#include <bits/stdc++.h>
#define int long long
#define lid (id << 1)
#define rid (lid | 1)
using namespace std;
int n;
int h[(int)1e5 + 5];
struct segtree
{
    int l, r;
    int lazy;
    int minn;
    int id;
} tree[(int)4e5 + 5];
inline void pushup(int id)
{
    // tree[id].minn = min(tree[lid].minn, tree[rid].minn);
    if (tree[lid].minn < tree[rid].minn)
    {
        tree[id].minn = tree[lid].minn;
        tree[id].id = tree[lid].id;
    }
    else
    {
        tree[id].minn = tree[rid].minn;
        tree[id].id = tree[rid].id;
    }
}
void build(int id, int l, int r)
{
    tree[id].l = l, tree[id].r = r;
    if (l == r)
    {
        tree[id].minn = h[l];
        tree[id].id = l;
        return;
    }
    int mid = (l + r) >> 1;
    build(lid, l, mid), build(rid, mid + 1, r);
    pushup(id);
}
void pushdown(int id)
{
    if (tree[id].lazy && tree[id].l != tree[id].r)
    {
        tree[lid].lazy += tree[id].lazy;
        tree[rid].lazy += tree[id].lazy;
        tree[lid].minn += tree[id].lazy;
        tree[rid].minn += tree[id].lazy;
        tree[id].lazy = 0;
    }
}
void update(int id, int l, int r, int x)
{
    pushdown(id);
    if (tree[id].l == l && tree[id].r == r)
    {
        tree[id].minn += x;
        tree[id].lazy += x;
        return;
    }
    int mid = (tree[id].l + tree[id].r) >> 1;
    if (r <= mid)
    {
        update(lid, l, r, x);
    }
    else if (l > mid)
    {
        update(rid, l, r, x);
    }
    else
    {
        update(lid, l, mid, x), update(rid, mid + 1, r, x);
    }
    pushup(id);
}
pair<int, int> query(int id, int l, int r)
{
    pushdown(id);
    if (tree[id].l == l && tree[id].r == r)
    {
        return make_pair(tree[id].minn, tree[id].id);
    }
    int mid = (tree[id].l + tree[id].r) >> 1;
    if (r <= mid)
    {
        return query(lid, l, r);
    }
    else if (l > mid)
    {
        return query(rid, l, r);
    }
    else
    {
        return min(query(lid, l, mid), query(rid, mid + 1, r));
    }
}
int work(int l, int r)
{
    // cout << l << " " << r << endl;
    if (l > r)
        return 0;
    pair<int, int> x = query(1, l, r);
    int a = x.first;
    int b = x.second;
    update(1, l, r, -a);
    return work(l, b - 1) + a + work(b + 1, r);
}
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    build(1, 1, n);
    cout << work(1, n) << endl;
    return 0;
}