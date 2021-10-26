#include <bits/stdc++.h>
#define ll long long
#define pi acos(-1)
using namespace std;
const int maxn = 2e3 + 10;
struct circle{
    ll x, y;
    ll r;
};
circle a[maxn];
int deg[maxn];
bool isInclude(int i, int j)
{
    if(a[i].r > a[j].r)
        return false;
    ll dis = (a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y);
    return dis <= (a[i].r - a[j].r) * (a[i].r - a[j].r);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y >> a[i].r;
    double ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(isInclude(i, j))
                deg[i]++;
            if(isInclude(j, i))
                deg[j]++;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(deg[i] % 2 || !deg[i])
            ans += pi * a[i].r * a[i].r;
        else
            ans -= pi * a[i].r * a[i].r;
    }
    cout << setprecision(10) << ans << endl;
    return 0;
}
