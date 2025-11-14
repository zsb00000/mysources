#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 1e9 + 7;
int a[(int)1e5 + 5];
int main()
{
    freopen("light.in", "r", stdin);
    freopen("light.out", "w", stdout);
    for (int j = 1; j <= 20; j++)
    {
        for (int k = 1; k <= (j >> 1); k++)
        {
            if (k == 1)
            {
                cout << 0 << " ";
                continue;
            }
            for (int i = 1; i <= j; i++)
            {
                a[i] = i;
            }
            long long ans = 0;
            do
            {
                bool flag = 1;
                for (int i = 2; i <= j && flag; i++)
                {
                    if (__gcd(a[i], a[i - 1]) == k)
                    {
                        flag = 0;
                    }
                }
                ans = (ans + flag) % mod;
            } while (next_permutation(a + 1, a + 1 + j));
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}
/*
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2
2 1 3 4
2 1 4 3
2 3 1 4
2 3 4 1
2 4 1 3
2 4 3 1
3 1 2 4
3 1 4 2
3 2 1 4
3 2 4 1
3 4 1 2
3 4 2 1
4 1 2 3
4 1 3 2
4 2 1 3
4 2 3 1
4 3 1 2
4 3 2 1
*/