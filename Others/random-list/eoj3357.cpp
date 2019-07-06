#include <bits/stdc++.h>
const int maxn = 2e3 + 10;
typedef long long ll;
using namespace std;
int d, k;
double dfs(int t)
{
    if(t >= 100 || t >= k)
        return (t - 1) * d + 1;
    return (t - 1) * d + 1 + 1.0 / dfs(t + 1);
}
int main()
{
    scanf("%d%d", &d, &k);
    printf("%.12f\n", 1 / dfs(1));
    return 0;
}

