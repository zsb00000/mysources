#include <bits/stdc++.h>
using namespace std;
void solve(int a, int b, int &x, int &y)
{
    if (b == 0)
        x = 1;
    solve(b, a % b, y, x);
    y -= (a / b) * x;
}
int main()
{
    int a, b;
    cin >> a >> b;
    int x = 0, y = 0;
    solve(a, b, x, y);
    cout << x << " " << y << endl;
    return 0;
}