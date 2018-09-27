#include <bits/stdc++.h>
#define eps 1e-6
using namespace std;
const int maxn = 1e5 + 10;
double x[maxn], v[maxn];
int n;
bool C(double mid)
{
    double lr = INT_MAX, rl = 0;
    for(int i = 0; i < n; i++)
    {
        double a = x[i] - v[i] * mid, b = x[i] + v[i] * mid;
        rl = max(rl, a);
        lr = min(lr, b);
    }
    if(rl < lr)
        return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> x[i];
    for(int i = 0; i < n; i++)
        cin >> v[i];
    double l = 0, r = 0;
    for(int i = 1; i < n; i++)
        r = max(r, fabs(x[i] - x[0]) / (1.0 * v[i]));
    //    cout << l << ' ' << r << endl;
    for(int i = 0; i < 100; i++)
    {
        double mid = (l + r) / 2;
        if(C(mid))
            r = mid;
        else
            l = mid;
    }
    cout << fixed << setprecision(7) << r << endl;
}
