#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll w1, h1, w2, h2;
    cin >> w1 >> h1 >> w2 >> h2;
    ll ans = 0;
    ans += w1 + 2;
    ans += h1 + h2 + 1;
    ans += w2 + 1;
    ans += h2;
    ans += (w1 - w2);
    ans += h1;
    cout << ans << endl;
    return 0;
}
