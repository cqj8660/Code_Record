#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
const int maxn = 2e5 + 10;
using namespace std;
pair<int, int> q[maxn];
int n, x, y;
char s[maxn];
bool check(int mid)
{
    for(int i = 1; i <= n - mid + 1; i++)
    {
        int l = i, r = i + mid - 1;
        int nedx = x - q[i - 1].fi - (q[n].fi - q[r].fi);
        int nedy = y - q[i - 1].se - (q[n].se - q[r].se);
        if(mid >= abs(nedx) + abs(nedy) && ((abs(nedx) + abs(nedy)) % 2 == mid % 2))
            return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> (s + 1);
    cin >> x >> y;
    q[0] = make_pair(0, 0);
    for(int i = 1; i <= n; i++)
    {
        switch(s[i])
        {
        case 'R':
            q[i] = make_pair(q[i - 1].fi + 1, q[i - 1].se);
            break;
        case 'L':
            q[i] = make_pair(q[i - 1].fi - 1, q[i - 1].se);
            break;
        case 'U':
            q[i] = make_pair(q[i - 1].fi, q[i - 1].se + 1);
            break;
        case 'D':
            q[i] = make_pair(q[i - 1].fi, q[i - 1].se - 1);
            break;
        }
    }
    if(q[n].fi == x && q[n].se == y)
    {
        cout << 0 << endl;
        return 0;
    }
    int l = 0, r = n;
    int ans = -1;
    for(int i = 0; i < 100; i++)
    {
        int mid = (l + r) >> 1;
        if(check(mid))
        {
            r = mid;
            ans = r;
        }
        else
            l = mid;
    }
    cout << ans << endl;
    return 0;

}
