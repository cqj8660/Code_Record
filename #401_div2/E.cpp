#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;
const int maxn = 1e5 + 10;
struct node{
    int a, b;//a为内径、b为外径
    ll h;
}r[maxn];
bool cmp(const node& x, const node &y)
{
    if(x.b == y.b)
        return x.a > y.a;
    return x.b > y.b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> r[i].a >> r[i].b >> r[i].h;
    sort(r, r + n, cmp);
    stack<node> q;
    q.push(r[0]);
    ll ans = r[0].h, len = r[0].h;
    for(int i = 1; i < n; i++)
    {
        while(q.size() && r[i].b <= q.top().a)
        {
            len -= q.top().h;
            q.pop();
        }
        len += r[i].h;
        q.push(r[i]);
        ans = max(len, ans);
    }
    cout << ans << endl;
    return 0;
}
