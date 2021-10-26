#include <bits/stdc++.h>
#define ll long long
const int maxn = 1e6 + 10;
using namespace std;
bool hole[maxn];
int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++)
    {
        int t; scanf("%d", &t);
        hole[t] = 1;
    }
    int loc = 1;
    while(k--)
    {
        if(hole[loc]){
            printf("%d\n", loc);
            return 0;
        }
        int u, v;
        scanf("%d%d", &u, &v);
        if(u == loc)
        {
            loc = v;
            continue;
        }
        if(v == loc)
        {
            loc = u;
            continue;
        }
    }
    printf("%d\n", loc);
    return 0;
}
