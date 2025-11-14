#include <bits/stdc++.h>
#define lid (id << 1)
#define rid (lid | 1)
// #define int long long
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
	int minn;
	int min_cnt;
	int hujia;
	int die;
} tree[(int)4e5 + 5];
inline void pushup(int id)
{
	tree[id].sum = tree[lid].sum + tree[rid].sum;
	tree[id].hujia = tree[lid].hujia + tree[rid].hujia;
	tree[id].die = tree[lid].die + tree[rid].die;

	if (tree[lid].minn < tree[rid].minn)
	{
		tree[id].minn = tree[lid].minn;
		tree[id].min_cnt = tree[lid].min_cnt;
	}
	else if (tree[lid].minn > tree[rid].minn)
	{
		tree[id].minn = tree[rid].minn;
		tree[id].min_cnt = tree[rid].min_cnt;
	}
	else
	{
		tree[id].minn = tree[lid].minn;
		tree[id].min_cnt = tree[lid].min_cnt + tree[rid].min_cnt;
	}
}
void build(int id, int l, int r)
{
	tree[id].l = l, tree[id].r = r;
	if (l == r)
	{
		tree[id].sum = a[l];
		tree[id].minn=a[l];
		tree[id].min_cnt=1;
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
		tree[lid].sum += tree[id].lazy * (tree[lid].r - tree[lid].l + 1);
		tree[rid].sum += tree[id].lazy * (tree[rid].r - tree[rid].l + 1);
		tree[id].lazy = 0;
	}
}
void update_p(int id, int l, int r, int x)
{
	pushdown(id);
	if (l == tree[id].l && tree[id].r == r)
	{
		tree[id].lazy += x;
		tree[id].sum += (tree[id].r - tree[id].l + 1) * x;
		if(tree[id].l==tree[id].r)
		{
			tree[id].minn=tree[id].sum;
			tree[id].minn=max(0,tree[id].minn);
			tree[id].min_cnt=1;
		}
		return;
	}
	int mid = (tree[id].l + tree[id].r) >> 1;
	if (r <= mid)
	{
		update_p(lid, l, r, x);
	}
	else if (l > mid)
	{
		update_p(rid, l, r, x);
	}
	else
	{
		update_p(lid, l, mid, x);
		update_p(rid, mid + 1, r, x);
	}
	pushup(id);
}
void update_hujia(int id,int l,int r,int x)
{
	pushdown(id);
	if(tree[id].l==tree[id].r)
	{
		if(tree[id].hujia)tree[id].hujia--;
		else tree[id].sum-=x;
		return;
	}
	int mid=(tree[id].l+tree[id].r)>>1;
	if(r<=mid)
	{
		update_hujia(lid,l,r,x);
	}
	else if(l>mid)
	{
		update_hujia(rid,l,r,x);
	}
	else
	{
		update_hujia(lid,l,mid,x),update_hujia(rid,mid+1,r,x);
	}
	pushup(id);
}
void update(int id,int pos)
{
	pushdown(id);
	if(tree[id].l==tree[id].r)
	{
		tree[id].hujia++;
		return;
	}
	int mid=(tree[id].l+tree[id].r)>>1;
	if(mid>=pos)
	{
		update(lid,pos);
	}
	else
	{
		update(rid,pos);
	}
	pushup(id);
}
void update_d(int id,int l,int r,int x)
{
	pushdown(id);
	if(tree[id].l==l&&tree[id].r==r)
	{
		if(tree[id].l==tree[id].r)
		{
			if(tree[id].hujia)
			{
				tree[id].hujia--;
			}
			else
			{
				tree[id].sum-=x;
			}
			tree[id].minn=tree[id].sum;
			if(tree[id].sum<0)tree[id].die=1;
			tree[id].minn=max(0,tree[id].minn);
			tree[id].min_cnt=1;
		}
		else if(tree[id].hujia)
		{
			int mid=(tree[id].l+tree[id].r)>>1;
			if(tree[lid].hujia)update_d(lid,l,mid,x);
			if(tree[rid].hujia)update_d(rid,mid+1,r,x);
		}
		else
		{
			tree[id].sum-=x*(tree[id].r-tree[id].l+1);
		}
		if(tree[id].minn<x)
		{
			int mid=(tree[id].l+tree[id].r)>>1;
			if(tree[lid].minn<x)update_d(lid,l,mid,x);
			if(tree[rid].minn<x)update_d(rid,mid+1,r,x);
		}
		return;
	}
	int mid=(tree[id].l+tree[id].r)>>1;
	if(r<=mid)
	{
		update_d(lid,l,r,x);
	}
	else if(l>mid)
	{
		update_d(rid,l,r,x);
	}
	else
	{
		update_d(lid,l,mid,x);
		update_d(rid,mid+1,r,x);
	}
	pushup(id);
}
int query_b(int id,int l,int r)
{
	pushdown(id);
	if(tree[id].l==l&&tree[id].r==r)
	{
		if(tree[id].minn>0)return 0;
		else if(tree[id].minn==0)return tree[id].min_cnt;
	}
	int mid=(tree[id].l+tree[id].r)>>1;
	if(r<=mid)
	{
		return query_b(lid,l,r);
	}
	else if(l>mid)
	{
		return query_b(rid,l,r);
	}
	else
	{
		return query_b(lid,l,mid)+query_b(rid,mid+1,r);
	}
}
int query_s(int id,int l,int r)
{
	pushdown(id);
	if(tree[id].l==l&&tree[id].r==r)
	{
		return tree[id].die;
	}
	int mid=(tree[id].l+tree[id].r)>>1;
	if(r<=mid)
	{
		return query_s(lid,l,r);
	}
	else if(l>mid)
	{
		return query_s(rid,l,r);
	}
	else
	{
		return query_s(lid,l,mid)+query_s(rid,mid+1,r);
	}
}
signed main()
{
//	freopen("simulator.in", "r", stdin);
//	freopen("simulator.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	cin >> q;
	while (q--)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int l, r, x;
			cin >> l >> r >> x;
			update_d(1,l,r,x);
		}
		else if (op == 2)
		{
			int l, r, x;
			cin >> l >> r >> x;
			update_p(1,l,r,x);
		}
		else if (op == 3)
		{
			int x;
			cin >> x;
			update(1,x);
		}
		else if (op == 4)
		{
			int l, r;
			cin >> l >> r;
			cout<<query_b(1,l,r)<<endl;
		}
		else if (op == 5)
		{
			int l, r;
			cin >> l >> r;
			cout<<query_s(1,l,r)<<endl;
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
