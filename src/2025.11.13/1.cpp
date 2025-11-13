#include <bits/stdc++.h>
#define int long long
using namespace std;
struct trie
{
    int ed;
    int cnt = 0;
    int ch[62];
    trie()
    {
        ed = 0;
        cnt = 0;
        memset(ch, -1, sizeof(ch));
    }
    void clear()
    {
        ed = 0;
        cnt = 0;
        memset(ch, -1, sizeof(ch));
    }
} tree[(int)3e6 + 5];
// vector<trie> tree;
int root = 0;
int tot = 0;
inline int get(char x)
{
    if (x >= 'a' && x <= 'z')
        return x - 'a';
    else if (x >= 'A' && x <= 'Z')
        return x - 'A' + 26;
    else
        return x - '0' + 52;
}
void insert(string s)
{
    int rt = root;
    for (char x : s)
    {
        if (tree[rt].ch[get(x)] == -1)
        {
            tree[rt].ch[get(x)] = ++tot;
        }
        rt = tree[rt].ch[get(x)];
        tree[rt].cnt++;
    }
    tree[rt].ed++;
}
int find(string s)
{
    int ans = 0;
    int rt = root;
    for (char x : s)
    {
        if (tree[rt].ch[get(x)] == -1)
            return 0;
        // ans += tree[rt].cnt;
        rt = tree[rt].ch[get(x)];
    }
    return tree[rt].cnt;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i <= tot; i++)
    {
        tree[i].clear();
    }
    tot = 0;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        insert(s);
    }
    for (int i = 1; i <= q; i++)
    {
        string s;
        cin >> s;
        cout << find(s) << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    // tree.reserve((int)6e6 + 5);
    while (t--)
    {
        solve();
    }
    return 0;
}