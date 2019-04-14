#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#define ll long long
using namespace std;
const int maxm = 2e3 + 10;
const int maxn = 2e5 + 10;
ll bita[maxn], bitb[maxn];
ll n, m;
ll sum(ll* b, int i)
{
    ll res = 0;
    while(i > 0)
    {
        res += b[i];
        i -= i & -i;
    }
    return res;
}
void add(ll* b, int i, ll v)
{
    while(i <= n)
    {
        b[i] += v;
        i += i & -i;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("C:\\Users\\CQJ3360\\Desktop\\ss.txt", "r", stdin);
    while(cin >> n >> m)
    {
        for(int i = 1; i <= n; i++){
            ll t; cin >> t;
            add(bita, i, t);
        }
        while(m--)
        {
            string c;
            ll x, y, t;
            cin >> c >> x >> y;
            if(c[0] == 'Q')
            {
                ll res = sum(bita, y) + sum(bitb, y) * y;
                res -= sum(bita, x - 1) + sum(bitb, x - 1) * (x - 1);
                cout << res << endl;
            }
            else
            {
                cin >> t;
                add(bita, x, -t * (x - 1));
                add(bitb, x, t);
                add(bita, y + 1, y * t);
                add(bitb, y + 1, -t);
            }
        }
    }
}
