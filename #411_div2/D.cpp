#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define eps 1e-6
using namespace std;
const int maxn = 2e5 + 10;
const int MOD = 1e9 + 7;

string a[maxn];
ll quick_pow(ll a, ll q)
{
    ll res = 1;
    while(q)
    {
        if(q & 1)
            res *= a;
        a *= a;
        a %= MOD;
        q >>= 1;
        res %= MOD;
    }
    return res;
}
ll solve(string s)
{
    ll res = 0;
    int pos = s.find("ab");
    ll an = 0, bn = 1;
    while(pos != -1)
    {
        an++;
        int l = pos - 1, r = pos + 2;
        bn = 1;
        while(l >= 0 && s[l] == 'a')
        {
            an++;
            l--;
        }
        while(r < s.length() && s[r] == 'b')
        {
            bn++;
            r++;
        }
        ll power = quick_pow(2, an) - 1;
        res += power * bn;
        res %= MOD;
        pos = s.find("ab", pos + 1);
    }
    return res;
}
int vio(string s)
{
    int res = 0;
    int pos = s.find("ab");
    while(pos != -1)
    {
        s = s.replace(pos, 2, "bba");
        pos = s.find("ab");
        res++;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //int v = quick_pow(2, 10);
    string s;
    while(cin >> s)
    {
        //ll res = vio(s);
        ll ans = solve(s);
        //cout << "real: " << res << endl;
        cout << ans <<endl;
    }
    return 0;

}
