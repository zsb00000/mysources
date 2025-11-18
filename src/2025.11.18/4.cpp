#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct node
{
    int a, b;
    bool operator<(const node &x) const { return b > x.b; }
} a[(int)1.5e5 + 5];
priority_queue<int> q;
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].a >> a[i].b;
    }
    sort(a + 1, a + 1 + n);
    int sum = 0, now = 0;
    for (int i = 1; i <= n; i++)
    {
        q.push(a[i].a);
        sum += a[i].a;
        if (sum <= a[i].b)
        {
            now++;
        }
        else
        {
            sum -= q.top();
            q.pop();
        }
    }
    cout << now << endl;
    return 0;
}