#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 10;
struct node{
    ll l, r;
};
node a[maxn];
bool cmp(const node & pa, const node & pb)
{
    ll a = min(2 * pa.l, pa.r) - min(pa.l, pa.r);
    ll b = min(2 * pb.l, pb.r) - min(pb.l, pb.r);
    return a > b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, f, ans = 0;
    cin >> n >> f;
    for(int i = 0; i < n; i++)
        cin >> a[i].l >> a[i].r;
    sort(a, a + n, cmp);
    for(int i = 0; i < f; i++)
        ans += min(2 * a[i].l, a[i].r);
    for(int i = f; i < n; i++)
        ans += min(a[i].l, a[i].r);
    cout << ans << endl;
    return 0;
}
