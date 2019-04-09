#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
const int maxn = 1e4 + 10;
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
    for(int i = 0; i < n; i++)
        dp[n - 1][i] = dis(n - 1, i);
    for(int i = n - 2; i >= 0; i--)
        for(int j = 0; j <= i; j++)
            dp[i][j] = min(dp[i + 1][j] + dis(i, i + 1), dp[i + 1][i] + dis(j, i + 1));
    printf("%.6f\n", dp[0][0]);
    return 0;
}

