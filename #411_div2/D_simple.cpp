#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define eps 1e-6
using namespace std;
const int MOD = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int len = (int)s.length();
    ll power = 0, ans = 0;
    for(int i = len - 1; i >= 0; i--)
    {
        if(s[i] == 'a')
        {
            ans += power;
            ans %= MOD;
            power *= 2;
            power %= MOD;
        }
        else
            power++;
    }
    cout << ans << endl;
    return 0;

}
