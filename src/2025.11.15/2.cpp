#include <bits/stdc++.h>
using namespace std;
int n;
int tot = 0;
int root = 0;
struct trie
{
    int cnt;
    int ed;
    int ch[2];
    int fail;
} tree[(int)3e4 + 5];
int vis[(int)3e4 + 5];
inline int get(char x)
{
    return x - '0';
}
void insert(string &s)
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
    tree[rt].ed = 1;
}
void build()
{
    queue<int> q;
    for (int i = 0; i < 2; i++)
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
        for (int i = 0; i < 2; i++)
        {
            if (tree[rt].ch[i])
            {
                tree[tree[rt].ch[i]].fail = tree[tree[rt].fail].ch[i];
                if (tree[tree[tree[rt].fail].ch[i]].ed)
                {
                    tree[tree[rt].ch[i]].ed = 1;
                }
                q.push(tree[rt].ch[i]);
            }
            else
            {
                tree[rt].ch[i] = tree[tree[rt].fail].ch[i];
            }
        }
    }
}
bool dfs(int rt)
{
    // cout << rt << endl;
    if (vis[rt] == 1)
        return 1;
    if (vis[rt] == -1)
        return 0;
    if (tree[rt].ed == 1)
        return 0;
    vis[rt] = 1;
    for (int i = 0; i < 2; i++)
    {
        if (dfs(tree[rt].ch[i]))
        {
            return 1;
        }
    }
    vis[rt] = -1;
    return 0;
}
int main()
{
    memset(vis, 0, sizeof(vis));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        insert(s);
    }
    build();
    if (dfs(root))
    {
        cout << "TAK";
    }
    else
    {
        cout << "NIE";
    }
    return 0;
}