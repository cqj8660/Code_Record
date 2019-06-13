#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e3 + 10;
ll dp[maxn];
struct segment{
    ll a, b, c;
};
segment p[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> p[i].a >> p[i].b >> p[i].c;

    return 0;
}
