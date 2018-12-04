#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll x, y, p, q;
        cin >> x >> y >> p >> q;
        if((p == q && x == y) || (p == 0 && x == 0))
        {
            cout << 0 << endl;
            continue;
        }
        if((p == q && x != y) || (p == 0 && x != 0))
        {
            cout << -1 << endl;
            continue;
        }
        // try to make x * q == p * y
        ll l = 0, r = 1e10;
        ll b = y / q * q;
        if(y % q)
            b += q;
        for(int id = 0; id < 100; id++)
        {
            ll mid = (l + r) / 2;
            ll temp = p * b / q + mid * p;//temp为AC的题目数
            if(temp >= x && temp <= (x + mid * q + b - y))
                r = mid;
            else
                l = mid;
        }
        cout << b + r * q - y << endl;
    }
    return 0;
}
