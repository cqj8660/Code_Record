#include <bits/stdc++.h>
#define ll long long
const int maxn = 1e5 + 10;
using namespace std;
struct node
{
    ll a, b, c;
}q[maxn];
//int cmp(const void * a, const void * b)
//{
//    node pa = *(node*)a, pb = *(node*)b;
//    return pb.c > pa.c ? 1 : -1;
//}
bool operator < (const node & a,const node & b)
{
    return a.c > b.c;
}
int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    ll n, m;
    scanf("%lld%lld", &n, &m);
    ll A = 0, B = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%lld%lld",&q[i].a, &q[i].b);
        q[i].c = q[i].a - q[i].b;
        A += q[i].a;
        B += q[i].b;
    }
    sort(q, q + n);
    if(A <= m)
    {
        puts("0");
        return 0;
    }
    if(B > m)
    {
        puts("-1");
        return 0;
    }
    if(B == m)
    {
        printf("%lld\n", n);
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        A -= q[i].c;
        if(A <= m)
        {
            printf("%d\n", i + 1);
            break;
        }
    }
    return 0;
}
