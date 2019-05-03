#include <bits/stdc++.h>
#define ll long long
using namespace std;
map<string, ll> mp;
ll gcd(ll a, ll b){
    if(a % b == 0)
        return b;
    return gcd(b, a %b);
}
int main()
{
   // freopen("C:\\Users\\stu\\Desktop\\in.txt", "r", stdin);
    ll h, m;
    cin >> h >> m;
    ll rep = 0, res = 0;
    /*for(int i = 0; i < h; i++)
        for(int j = 0; j < m; j++)
    {
        if(j >= i)
            rep++;
    }*/
    if(h >= m){
        res =  (1 + m) * m / 2;
    }
    else
    {
        res = (m - h + 1 + m) * h / 2;
    }
    ll gd = gcd(res, h * m);
    ll ans = h * m / gd;
    cout << res / gd << '/' << ans << endl;
    return 0;
}

