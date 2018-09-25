#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 10;
struct node
{
    int a, b, c;
}q[maxn];
bool cmp(const node& x, const node& y)
{
    return x.c < y.c;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> q[i].a;
    for (int i = 0; i < n; i++)
        cin >> q[i].b;
    for (int i = 0; i < n; i++)
        q[i].c = q[i].a - q[i].b;
    sort(q, q + n, cmp);
    ll ans = 0;
    for(int i = 0; i < k; i++)
        ans += q[i].a;
    int j = k;
    while(q[j].c < 0)
        ans += q[j++].a;
    for(int i = j; i < n; i++)
        ans += q[i].b;
    cout << ans << endl;
    return 0;
}
