#include <bits/stdc++.h>
using namespace std;
long long n;
int main()
{
    freopen("dis.in", "r", stdin);
    freopen("dis.out", "w", stdout);
    cin >> n;
    cout << n % 998244353 * (n - 1) % 998244353 << endl;
    return 0;
}