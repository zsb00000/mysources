#include <bits/stdc++.h>
#define lid (id << 1)
#define rid (lid | 1)
#define int long long
using namespace std;
int n;
int a[(int)2e5 + 5];
int h[(int)2e5 + 5];
int q;
struct node
{
    int l, r;
    int sum;
    int lazy;
} tree[(int)4e5 + 5];
inline void pushup(int id)
{
    tree[id].sum = tree[lid].sum + tree[rid].sum;
}
void build(int id, int l, int r)
{
    tree[id].l = l, tree[id].r = r;
    if (l == r)
    {
        tree[id].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lid, l, mid), build(rid, mid + 1, r);
    pushup(id);
}
inline void pushdown(int id)
{
    if (tree[id].lazy && tree[id].l != tree[id].r)
    {
        tree[lid].lazy += tree[id].lazy;
        tree[rid].lazy += tree[id].lazy;
        tree[lid].sum += tree[id].lazy * (tree[lid].r - tree[lid].l + 1);
        tree[rid].sum += tree[id].lazy * (tree[rid].r - tree[rid].l + 1);
        tree[id].lazy = 0;
    }
}
void update(int id, int l, int r, int x)
{
    pushdown(id);
    if (l == tree[id].l && r == tree[id].r)
    {
        tree[id].lazy += x;
        tree[id].sum += x * (r - l + 1);
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
int query(int id, int l, int r)
{
    pushdown(id);
    if (l == tree[id].l && r == tree[id].r)
    {
        return tree[id].sum;
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
        return query(lid, l, mid) + query(rid, mid + 1, r);
    }
}
signed main()
{
    freopen("simulator.in", "r", stdin);
    freopen("simulator.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    cin >> q;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;
            if (l == r)
            {
                for (int i = l; i <= r; i++)
                {
                    if (h[i])
                        h[i]--;
                    else
                        a[i] -= x;
                }
            }
            else
            {
                update(1, l, r, -x);
            }
        }
        else if (op == 2)
        {
            int l, r, x;
            cin >> l >> r >> x;
            if (l == r)
            {
                for (int i = l; i <= r; i++)
                {
                    if (a[i] >= 0)
                        a[i] += x;
                }
            }
            else
            {
                update(1, l, r, x);
            }
        }
        else if (op == 3)
        {
            int x;
            cin >> x;
            h[x]++;
        }
        else if (op == 4)
        {
            int l, r;
            cin >> l >> r;
            int ans = 0;
            for (int i = l; i <= r; i++)
            {
                ans += (a[i] < 0);
            }
            cout << ans << '\n';
        }
        else if (op == 5)
        {
            int l, r;
            cin >> l >> r;
            if (l == r)
            {
                int ans = 0;
                for (int i = l; i <= r; i++)
                {
                    ans += (a[i] == 0);
                }
                cout << ans << '\n';
            }
        }
        else
        {
            throw runtime_error("xxxx");
        }
    }
    return 0;
}
/*
5
3 1 4 1 5
14
1 2 4 1
5 2 5
1 2 5 3
4 1 5
5 1 5
2 1 5 10
4 1 5
3 3
3 5
3 3
1 1 5 100
4 1 5
1 1 5 100
4 1 5
*/