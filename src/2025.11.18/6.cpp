#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct node
{
    int a, b;
    bool operator<(const node &x) const { return a < x.a; }
} a[(int)2.5e5 + 5];
set<int> s;
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].a;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].b;
    }
    int sum = 0, ans = 0;
    priority_queue<node> q;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i].a;
        if (!q.empty() && sum < a[i].b && q.top().a > a[i].b)
        {
            sum += q.top().a;
            s.erase(q.top().b);
            q.pop();
            ans--;
        }
        if (sum >= a[i].b)
        {
            sum -= a[i].b;
            ans++;
            q.push({a[i].b, i});
            s.insert(i);
        }
    }
    cout << ans << endl;
    for (int i : s)
    {
        cout << i << " ";
    }
    return 0;
}