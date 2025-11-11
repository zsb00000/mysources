#include <bits/stdc++.h>
using namespace std;
int n;
double p[(int)1e5 + 5];
double f[(int)1e5 + 5];
double g[(int)1e5 + 5];
double t[(int)1e5 + 5];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++)
    {
        f[i] = (f[i - 1] + 1) * p[i];
        g[i] = (g[i - 1] + 2 * f[i - 1] + 1) * p[i];
        t[i] = t[i - 1] + (3 * g[i - 1] + 3 * f[i - 1] + 1) * p[i];
    }
    cout << fixed << setprecision(1) << t[n] << endl;
    return 0;
}