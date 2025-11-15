#include <bits/stdc++.h>
using namespace std;
string t[(int)1e5 + 5];
struct trie
{
    int ed;
    int ch[26];
    int fail;
} tree[(int)1e5 + 5];
int root = 0;
int tot = 0;
int ed[(int)1e5 + 5];
int sign[(int)1e5 + 5];
int ans[(int)1e5 + 5];
int top = 0;
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
    tree[rt].ed = s.size();
    return rt;
}
void build()
{
    queue<int> q;
    for (int i = 0; i < 26; i++)
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
        for (int i = 0; i < 26; i++)
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
void query(string &s)
{
    int rt = root;
    for (int i = 0; i < s.size(); i++)
    {
        rt = tree[rt].ch[get(s[i])];
        sign[++top] = rt;
        ans[top] = i;
        if (tree[rt].ed)
        {
            int len = tree[rt].ed;
            top -= len;
            if (!top)
                rt = 0;
            else
                rt = sign[top];
        }
    }
}
int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
        ed[i] = _insert(t[i]);
    }
    build();
    query(s);
    for (int i = 1; i <= top; i++)
    {
        cout << s[ans[i]];
    }
    return 0;
}