#include <bits/stdc++.h>
using namespace std;
int n;
int a[(int)2e5 + 5];
int h[(int)2e5 + 5];
int q;
int main()
{
    // freopen("simulator.in", "r", stdin);
    // freopen("simulator.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> q;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;
            for (int i = l; i <= r; i++)
            {
                if (h[i])
                    h[i]--;
                else
                    a[i] -= x;
            }
        }
        else if (op == 2)
        {
            int l, r, x;
            cin >> l >> r >> x;
            for (int i = l; i <= r; i++)
            {
                if (a[i] >= 0)
                    a[i] += x;
            }
        }
        else if (op == 3)
        {
            int x;
            cin >> x;
            h[x]++;
        }
        else if (op == 4)
        {
            int l, r;
            cin >> l >> r;
            int ans = 0;
            for (int i = l; i <= r; i++)
            {
                ans += (a[i] < 0);
            }
            cout << ans << '\n';
        }
        else if (op == 5)
        {
            int l, r;
            cin >> l >> r;
            int ans = 0;
            for (int i = l; i <= r; i++)
            {
                ans += (a[i] == 0);
            }
            cout << ans << '\n';
        }
        else
        {
            throw runtime_error("xxxx");
        }
    }
    return 0;
}
/*
5
3 1 4 1 5
14
1 2 4 1
5 2 5
1 2 5 3
4 1 5
5 1 5
2 1 5 10
4 1 5
3 3
3 5
3 3
1 1 5 100
4 1 5
1 1 5 100
4 1 5
*/