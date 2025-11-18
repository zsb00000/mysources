#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
struct node
{
    int x, t;
    node() { x = 0, t = 0; }
    bool operator<(const node &a) const { return x < a.x; }
} a[(int)1e5 + 5];
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].t;
    }
    sort(a + 1, a + 1 + n);
    priority_queue<int> q;
    int sum = 0, now = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i].x - a[i - 1].x;
        q.push(a[i].t);
        if (sum + a[i].t <= m)
        {
            sum += a[i].t;
            now++;
        }
        else if (sum > q.top())
        {
            sum -= q.top();
            q.pop();
        }
    }
    cout << now << endl;
    return 0;
}