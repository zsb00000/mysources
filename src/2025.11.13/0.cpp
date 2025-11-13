#include <bits/stdc++.h>
using namespace std;
int _next[(int)2e6 + 5];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    string p = s2 + '#' + s1;
    int j = 2, k = 0;
    int lenb = s2.size();
    for (int i = 1; i < p.size(); i++)
    {
        int len = _next[i - 1];
        while (len && p[i] != p[len])
        {
            len = _next[len - 1];
        }
        if (p[i] == p[len])
        {
            _next[i] = len + 1;
        }
    }
    for (int i = 0; i < p.size(); i++)
    {
        if (_next[i] == s2.size())
        {
            cout << i - _next[i] + 1 - lenb << '\n';
        }
    }
    for (int i = 0; i < s2.size(); i++)
    {
        cout << _next[i] << " ";
    }
}