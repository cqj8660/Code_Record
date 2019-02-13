#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
const int maxn = 1e5 + 10;
ll ext[maxn];
ll a, b, h, w, n;
int solve(ll h, ll w, int time)
{
    if(h >= a && w >= b){
        return time;
    }
    if(time == n || ext[time] == 1) return INT_MAX;
    if(ext[time] == 2)
    {
        if(h < a)
            return solve(h * ext[time], w, time + 1);
        else
            return solve(h, w * ext[time], time + 1);
    }
    else
    {
        if(h >= a)
            return solve(h, w * ext[time], time + 1);
        else if(w >= b)
            return solve(h * ext[time], w, time + 1);
        else return min(solve(h, w * ext[time], time + 1), solve(h * ext[time], w, time + 1));
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> h >> w >> n;
    for(int i = 0; i < n; i++)
        cin >> ext[i];
    sort(ext, ext + n, greater<int>());
    int ans = solve(h, w, 0);
    ans = min(ans, solve(w, h, 0));
    if(ans == INT_MAX)
        ans = -1;
    cout << ans << endl;
    return 0;
}

