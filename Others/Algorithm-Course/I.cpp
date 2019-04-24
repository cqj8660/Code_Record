#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
#define maxn 10005
pair<int, int> p[maxn];
inline float dis(int i, int j)
{
    return sqrt(pow(p[i].fi - p[j].fi, 2) + pow(p[i].se - p[j].se, 2));;
}
float dp[maxn][maxn];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        p[i] = make_pair(x, y);
    }
    sort(p, p + n);
//    for(int i = 0; i < n; i++)
//        for(int j = 0; j < n; j++)
//            dp[i][j] = INT_MAX;
    dp[1][0] = dis(1, 0);
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(dp[i + 1][j])
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + dis(i, i + 1));
            else
                dp[i + 1][j] = dp[i][j] + dis(i, i + 1);
            if(dp[i + 1][i])
                dp[i + 1][i] = min(dp[i + 1][i], dp[i][j] + dis(j, i + 1));
            else
                dp[i + 1][i] = dp[i][j] + dis(j, i + 1);
        }
    }
    printf("%.5f\n", dp[n - 1][n - 2] + dis(n - 1, n - 2));
    return 0;
}

