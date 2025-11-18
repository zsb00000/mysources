#include <bits/stdc++.h>
using namespace std;
int n;
int p[(int)3e6 + 5];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    priority_queue<int> q;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((!q.empty()) && (-q.top()) < p[i])
        {
            ans += p[i] + q.top();
            q.pop();
            q.push(-p[i]);
        }
        q.push(-p[i]);
    }
    cout << ans << endl;
    return 0;
}