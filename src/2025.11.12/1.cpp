#include <bits/stdc++.h>
using namespace std;
int n, b;
int a[(int)5e5 + 5];
int main()
{
    freopen("empty.in", "r", stdin);
    freopen("empty.out", "w", stdout);
    cin >> n >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int pos = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == b)
        {
            pos = i;
            break;
        }
    }
    map<int, int> x;
    long long ans = 0;
    int s = 0;
    for (int i = pos; i <= n; i++)
    {
        if (a[i] > b)
        {
            s++;
        }
        else if (a[i] < b)
        {
            s--;
        }
        x[s]++;
    }
    s = 0;
    for (int i = pos; i >= 1; i--)
    {
        if (a[i] > b)
        {
            s++;
        }
        else if (a[i] < b)
        {
            s--;
        }
        ans += x[-s];
    }
    cout << ans << endl;
    return 0;
}