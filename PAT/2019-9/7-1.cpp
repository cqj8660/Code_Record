#include <iostream>
#include <set>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#define ll long long
using namespace std;
int gcd(ll a, ll b)
{
    if(a % b == 0)
        return b;
    return gcd(b, a % b);
}
int calDigit(ll n)
{
    string s = to_string(n);
    int res = 0;
    int len = s.length();
    for(int i = 0; i < len; i++)
        res += s[i] - '0';
    return res;
}
bool isprime(ll n)
{
    if(n == 2 || n == 1)
        return false;
    for(ll i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
            return false;
    }

    return true;
}

struct node
{
    int a;
    ll b;
    bool operator<(const node& pa)
    {
        if(a == pa.a)
            return b < pa.b;
        return a < pa.a;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int k, m;
        cin >> k >> m;
        cout << "Case " << i << endl;
        ll num = 1;
        for(int i = 2; i < k; i++)
            num *= 10;
        vector<node> ans;
        for(int j = num; ; j++)
        {
            ll t = j * 10 + 9;
            if(t > num * 100)
                break;
            int tempm = calDigit(t);
            int tempn = calDigit(t + 1);
            if(tempm == m && isprime(gcd(tempm, tempn)))
            {
                ans.push_back(node{tempn, t});
            }
        }
        if(ans.empty())
            cout << "No Solution\n";
        else
        {
            sort(ans.begin(), ans.end());
            for(auto idx: ans)
                cout << idx.a << ' ' << idx.b << endl;
        }
    }

    return 0;
}
