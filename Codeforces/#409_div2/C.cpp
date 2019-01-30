#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 10;
ll a[maxn], b[maxn];
ll n, p;
bool C(double mid)
{
    double need = 0;
    for(int i = 0; i < n; i++)
    {
        if(mid * a[i] < b[i])
            continue;
        else
            need += mid * a[i] - b[i];
    }
    return need < mid * p;
}
int main()
{
    //    ios::sync_with_stdio(false);
    //    cin.tie(0);
    double l = 0, r = 1e12;
    scanf("%lld%lld", &n, &p);
    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%lld%lld", &a[i], &b[i]);
        sum += a[i];
    }
    if(sum <= p)
    {
        printf("-1\n");
        return 0;
    }
    for(int i = 0; i < 100; i++)
    {
        double mid = (l + r) / 2;
        if(C(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%.10f\n", l);
    return 0;
    
}
