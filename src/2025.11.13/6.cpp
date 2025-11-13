#include <bits/stdc++.h>
using namespace std;
int n;
int root = 0;
int tot = 0;
string s[205];
struct trie
{
    int fail;
    int ed;
    int ch[27];
} tree[(int)1e6 + 5];
int sum[(int)1e6 + 5];
int ed[205];
vector<int> a[(int)1e6 + 5];
inline int get(char x)
{
    if (x == '#')
        return 0;
    else
        return x - 'a' + 1;
}
int _insert(const string &s)
{
    int rt = root;
    for (char x : s)
    {
        if (tree[rt].ch[get(x)] == 0)
        {
            tree[rt].ch[get(x)] = ++tot;
        }
        rt = tree[rt].ch[get(x)];
    }
    tree[rt].ed++;
    return rt;
}
void build()
{
    queue<int> q;
    for (int i = 0; i < 27; i++)
    {
        if (tree[root].ch[i])
        {
            q.push(tree[root].ch[i]);
        }
    }
    while (!q.empty())
    {
        int rt = q.front();
        q.pop();
        for (int i = 0; i < 27; i++)
        {
            if (tree[rt].ch[i])
            {
                tree[tree[rt].ch[i]].fail = tree[tree[rt].fail].ch[i];
                q.push(tree[rt].ch[i]);
            }
            else
            {
                tree[rt].ch[i] = tree[tree[rt].fail].ch[i];
            }
        }
    }
}
void query(const string &s)
{
    int rt = 0;
    for (char x : s)
    {
        rt = tree[rt].ch[get(x)];
        sum[rt]++;
    }
}
void dfs(int x)
{
    for (int i : a[x])
    {
        dfs(i);
        sum[x] += sum[i];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    string text;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        ed[i] = _insert(s[i]);
        text += '#' + s[i];
    }
    build();
    query(text);
    for (int i = 1; i <= tot; i++)
    {
        a[tree[i].fail].push_back(i);
    }
    dfs(0);
    for (int i = 1; i <= n; i++)
    {
        cout << sum[ed[i]] << '\n';
    }
    return 0;
}