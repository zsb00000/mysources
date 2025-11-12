#include <bits/stdc++.h>
#define lid (id << 1)
#define rid (id << 1 | 1)
using namespace std;
int n, m;
int rr[(int)2e6 + 5];
struct segtree
{
    int l, r;
    int val;
    int lazy;
} tree[(int)4e6 + 5];
void pushup(int id)
{
    tree[id].val = min(tree[lid].val, tree[rid].val);
}
void build(int id, int l, int r)
{
    tree[id].l = l;
    tree[id].r = r;
    tree[id].val = 0;
    tree[id].lazy = 0;
    if (tree[id].l == tree[id].r)
    {
        tree[id].val = rr[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lid, l, mid);
    build(rid, mid + 1, r);
    pushup(id);
}
void pushdown(int id)
{
    if (tree[id].lazy && tree[id].l != tree[id].r)
    {
        tree[lid].lazy += tree[id].lazy;
        tree[rid].lazy += tree[id].lazy;
        tree[lid].val += tree[id].lazy;
        tree[rid].val += tree[id].lazy;
        tree[id].lazy = 0;
    }
}
void update(int id, int l, int r, int val)
{
    pushdown(id);
    if (tree[id].l == l && tree[id].r == r)
    {
        tree[id].val += val;
        tree[id].lazy += val;
        return;
    }
    int mid = (tree[id].l + tree[id].r) >> 1;
    if (mid >= r)
    {
        update(lid, l, r, val);
    }
    else if (mid < l)
    {
        update(rid, l, r, val);
    }
    else
    {
        update(lid, l, mid, val);
        update(rid, mid + 1, r, val);
    }
    pushup(id);
}
int query(int id, int l, int r)
{
    pushdown(id);
    if (tree[id].l == l && tree[id].r == r)
    {
        return tree[id].val;
    }
    int mid = (tree[id].l + tree[id].r) >> 1;
    if (mid >= r)
    {
        return query(lid, l, r);
    }
    else if (mid < l)
    {
        return query(rid, l, r);
    }
    else
    {
        return min(query(lid, l, mid), query(rid, mid + 1, r));
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> rr[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int s, t, d;
        cin >> d >> s >> t;
        if (query(1, s, t) < d)
        {
            cout << -1 << endl;
            cout << i << endl;
            return 0;
        }
        update(1, s, t, -d);
    }
    cout << 0 << endl;
    return 0;
}