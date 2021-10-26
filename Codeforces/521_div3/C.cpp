#include <bits/stdc++.h>
#define ll long long
const int maxn = 2e5 + 10;
using namespace std;
struct node{
    ll v, idx;
}a[maxn];
bool cmp(const node& a, const node& b)
{
    return a.v < b.v;
}
ll sum;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].v;
        sum += a[i].v;
        a[i].idx = i;
    }
    sort(a + 1, a + n + 1, cmp);
    set<ll> q;
    for(int i = 1; i <= n - 1; i++)
    {
        if(sum - a[i].v - a[n].v == a[n].v)
            q.insert(a[i].idx);
    }
    if(sum - a[n].v - a[n - 1].v == a[n - 1].v)
        q.insert(a[n].idx);
    cout << q.size() << endl;
    for(auto idx: q)
        cout << idx << ' ';
    cout << endl;
    return 0;
}
