#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--)
    {
        ll a, b, c;
        vector<ll> p;
        cin >> a >> b >> c;
        p.push_back(a);
        p.push_back(b);
        p.push_back(c);
        sort(p.begin(), p.end());
        ll ans = p[1];
        if(p[2] > p[1] - p[0])
            ans = ans + (p[2] - p[1] + p[0]) / 2;
        cout << ans << endl;
    }
    return 0;
}
