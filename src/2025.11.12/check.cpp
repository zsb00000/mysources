#include <bits/stdc++.h>
using namespace std;
int main(int arc, char **avc)
{
    string x = avc[1];
    string y = "g++ " + x + ".cpp" + " -o " + x + ".exe";
    system(y.c_str());
    for (int i = 1; i <= 4; i++)
    {
        string a = x + ".exe<" + x + to_string(i) + ".in";
        system(a.c_str());
        string b = x + ".out " + x + to_string(i) + ".ans";
        cout << system(b.c_str()) << endl;
    }
}