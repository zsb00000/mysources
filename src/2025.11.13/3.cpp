#include <bits/stdc++.h>
using namespace std;
int n;
int root = 0;
int tot = 0;
struct node
{
    int cnt;
    int ed;
    int ch[26];
    int fail;
} tree[(int)1e6 + 5];
inline int get(int x)
{
    return x - 'a';
}
void insert(string s)
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
}
void get_fail()
{
    queue<int> q;
    for (int i = 0; i < 26; i++)
    {
        if (tree[0].ch[i] != 0)
        {
            tree[tree[0].ch[i]].fail = 0;
            q.push(tree[0].ch[i]);
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
int query(string s)
{
    int ans = 0;
    int rt = root;
    for (int i = 0; i < s.size(); i++)
    {
        rt = tree[rt].ch[get(s[i])];
        for (int t = rt; t && tree[t].ed != -1; t = tree[t].fail)
        {
            // if ()
            //     continue;
            ans += tree[t].ed;
            tree[t].ed = -1;
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        insert(s);
    }
    tree[0].fail = 0;
    get_fail();
    string s;
    cin >> s;
    cout << query(s) << '\n';
    return 0;
}