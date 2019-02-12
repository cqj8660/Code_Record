#include <bits/stdc++.h>
const int maxn = 2e5 + 10;
typedef long long ll;
using namespace std;
string solve(string s)
{
    int len = (int)s.length(), i, carry;
    for(i = len - 1; i >= 0; i--)
    {
        int v = s[i] - 'A';
        if(v < 25)
        {
            s[i]++;
            break;
        }
        else
            s[i] = 'A';
    }
    if(i < 0)
        return 'A' + s;
    else
        return s;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    if(a < b)
        cout << solve(a) << endl;
    else
        cout << solve(b) << endl;
    return 0;
}

