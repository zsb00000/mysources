#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int INF = 1e9;

int n;
int health[MAXN], shield[MAXN];
bool dead[MAXN], dying[MAXN];

struct Node
{
	int min_health;  // 区间最小生命值
	int dead_count;  // 区间死亡英雄数量
	int dying_count; // 区间殒死英雄数量
	int lazy;        // 延迟标记（治疗操作）

	Node() : min_health(INF), dead_count(0), dying_count(0), lazy(0) {}
};

Node tree[MAXN * 4];

void pushup(int id)
{
	tree[id].min_health = min(tree[id * 2].min_health, tree[id * 2 + 1].min_health);
	tree[id].dead_count = tree[id * 2].dead_count + tree[id * 2 + 1].dead_count;
	tree[id].dying_count = tree[id * 2].dying_count + tree[id * 2 + 1].dying_count;
}

void pushdown(int id, int l, int r)
{
	if (tree[id].lazy != 0)
	{
		tree[id * 2].lazy += tree[id].lazy;
		tree[id * 2 + 1].lazy += tree[id].lazy;

		if (tree[id * 2].min_health != INF)
		{
			tree[id * 2].min_health += tree[id].lazy;
		}
		if (tree[id * 2 + 1].min_health != INF)
		{
			tree[id * 2 + 1].min_health += tree[id].lazy;
		}

		tree[id].lazy = 0;
	}
}

void build(int id, int l, int r)
{
	if (l == r)
	{
		tree[id].min_health = health[l];
		tree[id].dead_count = dead[l] ? 1 : 0;
		tree[id].dying_count = dying[l] ? 1 : 0;
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	pushup(id);
}

// 治疗操作：区间增加生命值
void update_heal(int id, int l, int r, int ql, int qr, int val)
{
	if (ql <= l && r <= qr)
	{
		tree[id].lazy += val;
		if (tree[id].min_health != INF)
		{
			tree[id].min_health += val;
		}
		return;
	}

	pushdown(id, l, r);
	int mid = (l + r) / 2;

	if (ql <= mid) update_heal(id * 2, l, mid, ql, qr, val);
	if (qr > mid) update_heal(id * 2 + 1, mid + 1, r, ql, qr, val);

	pushup(id);
}

// 攻击操作：处理护盾和生命值减少
void update_attack(int id, int l, int r, int ql, int qr, int damage)
{
	if (l == r)
	{
		// 叶子节点，直接处理
		if (!dead[l])
		{
			if (shield[l] > 0)
			{
				shield[l]--;
			}
			else
			{
				health[l] -= damage;
				if (health[l] < 0)
				{
					dead[l] = true;
					dying[l] = false;
					tree[id].min_health = INF;
				}
				else if (health[l] == 0)
				{
					dying[l] = true;
					tree[id].min_health = 0;
				}
				else
				{
					dying[l] = false;
					tree[id].min_health = health[l];
				}
			}
		}

		tree[id].dead_count = dead[l] ? 1 : 0;
		tree[id].dying_count = dying[l] ? 1 : 0;
		return;
	}

	pushdown(id, l, r);
	int mid = (l + r) / 2;

	// 如果当前区间有英雄可能受到攻击，继续递归
	if (ql <= mid && (tree[id * 2].dead_count < (mid - l + 1) || tree[id * 2].min_health <= damage))
	{
		update_attack(id * 2, l, mid, ql, qr, damage);
	}
	if (qr > mid && (tree[id * 2 + 1].dead_count < (r - mid) || tree[id * 2 + 1].min_health <= damage))
	{
		update_attack(id * 2 + 1, mid + 1, r, ql, qr, damage);
	}

	pushup(id);
}

// 添加护盾
void update_shield(int id, int l, int r, int pos)
{
	if (l == r)
	{
		shield[l]++;
		return;
	}

	pushdown(id, l, r);
	int mid = (l + r) / 2;

	if (pos <= mid) update_shield(id * 2, l, mid, pos);
	else update_shield(id * 2 + 1, mid + 1, r, pos);
}

// 查询死亡英雄数量
int query_dead(int id, int l, int r, int ql, int qr)
{
	if (ql <= l && r <= qr)
	{
		return tree[id].dead_count;
	}

	pushdown(id, l, r);
	int mid = (l + r) / 2;
	int res = 0;

	if (ql <= mid) res += query_dead(id * 2, l, mid, ql, qr);
	if (qr > mid) res += query_dead(id * 2 + 1, mid + 1, r, ql, qr);

	return res;
}

// 查询殒死英雄数量
int query_dying(int id, int l, int r, int ql, int qr)
{
	if (ql <= l && r <= qr)
	{
		return tree[id].dying_count;
	}

	pushdown(id, l, r);
	int mid = (l + r) / 2;
	int res = 0;

	if (ql <= mid) res += query_dying(id * 2, l, mid, ql, qr);
	if (qr > mid) res += query_dying(id * 2 + 1, mid + 1, r, ql, qr);

	return res;
}

int main()
{
//    freopen("simulator.in", "r", stdin);
//    freopen("simulator.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> health[i];
		shield[i] = 0;
		dead[i] = false;
		dying[i] = (health[i] == 0);
	}

	build(1, 1, n);

	int q;
	cin >> q;
	while (q--)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int l, r, x;
			cin >> l >> r >> x;
			update_attack(1, 1, n, l, r, x);
		}
		else if (op == 2)
		{
			int l, r, x;
			cin >> l >> r >> x;
			update_heal(1, 1, n, l, r, x);
		}
		else if (op == 3)
		{
			int h;
			cin >> h;
			update_shield(1, 1, n, h);
		}
		else if (op == 4)
		{
			int l, r;
			cin >> l >> r;
			cout << query_dead(1, 1, n, l, r) << '\n';
		}
		else if (op == 5)
		{
			int l, r;
			cin >> l >> r;
			cout << query_dying(1, 1, n, l, r) << '\n';
		}
	}

	return 0;
}
