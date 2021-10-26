#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6 + 10;
string s;
ll solve(int loc, int len)
{
    ll res = 0;
    for(int i = loc; i < loc + len; i++)
        res = res * 10 + s[i] - '0';
    return res;
}
bool isprime(ll val)
{
    if(val == 1 || val == 0) return false;
    for(int i = 2; i <= sqrt(val); i++)
        if(val % i == 0)
            return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll l, k;
    cin >> l >> k >> s;
    for(int i = 0; i <= l - k; i++)
    {
        ll temp = solve(i, k);
        if(isprime(temp))
        {
            cout << s.substr(i, k) << endl;
            return 0;
        }
    }
    cout << "404" << endl;
    return 0;
}
