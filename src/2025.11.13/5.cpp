#include <bits/stdc++.h>
using namespace std;
struct node
{
    int ed;
    int fail;
    int ch[26];
} tree[(int)2e5 + 5];
int n;
int root = 0;
int tot = 0;
int sum[(int)2e5 + 5];
int ed[(int)2e5 + 5];
vector<int> e[(int)2e5 + 5];
inline int get(char x)
{
    return x - 'a';
}
int _insert(string &s)
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
    // int rt = root;
    queue<int> q;
    for (int i = 0; i < 26; i++)
    {
        if (tree[root].ch[i] != 0)
        {
            q.push(tree[root].ch[i]);
        }
    }
    while (!q.empty())
    {
        int rt = q.front();
        q.pop();
        for (int i = 0; i < 26; i++)
        {
            if (tree[rt].ch[i] != 0)
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
void query(string &s)
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
    for (int i : e[x])
    {
        dfs(i);
        sum[x] += sum[i];
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        ed[i] = _insert(s);
    }
    build();
    string s;
    cin >> s;
    for (int i = 1; i <= tot; i++)
    {
        e[tree[i].fail].push_back(i);
    }
    query(s);
    dfs(root);
    for (int i = 1; i <= n; i++)
    {
        cout << sum[ed[i]] << endl;
    }
    return 0;
}