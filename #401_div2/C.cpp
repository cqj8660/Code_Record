#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn][2];
int non_desc[maxn];
int dp[maxn];
int main()
{
    //    ios::sync_with_stdio(false);
    //    cin.tie(0);
    int n, m;
    scanf("%d%d", &n, &m);
    for(int j = 0; j < m; j++)
        scanf("%d", &a[j][0]);
    int f = 1;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            scanf("%d", &a[j][f]);
        int maxlen = 0;
        for(int j = 0; j < m; j++)
        {
            if(a[j][f] >= a[j][!f])
                non_desc[j] = non_desc[j] + 1;
            else
                non_desc[j] = 0;
            maxlen = max(maxlen, non_desc[j]);
        }
        dp[i] = maxlen;
        f = !f;
    }
    //    for(int i = 0; i < n; i++)
    //        cout << dp[i] << endl;
    int k;
    scanf("%d", &k);
    while(k--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        l--;r--;
        int maxlen = dp[r];
        if(maxlen >= r - l)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
