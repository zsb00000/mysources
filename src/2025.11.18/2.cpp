#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct node
{
    int p;
    int d;
} a[(int)2e5 + 5];
priority_queue<int> q;
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int d, p;
        cin >> d >> p;
        a[i].d = d, a[i].p = p;
    }
    sort(a + 1, a + 1 + n,
         [&](const node &x, const node &y) { return x.d < y.d; });
    int now = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (now < a[i].d)
        {
            now++;
            ans += a[i].p;
            q.push(-a[i].p);
        }
        else if (a[i].p > (-q.top()))
        {
            ans += a[i].p + q.top();
            q.pop();
            q.push(-a[i].p);
        }
    }
    cout << ans << endl;
    return 0;
}