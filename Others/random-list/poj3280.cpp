#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#define pii pair<int, int>
#define ll long long
using namespace std;
const int maxn = 2e3 + 10;
int val[50];
int dp[maxn][maxn];
char s[maxn];
//dp[i][j]表示从i到j要形成回文串的最小代价
int main()
{
    int n, m;
    scanf("%d%d%s", &n, &m, s);
    while(n--)
    {
        getchar();
        char c;
        int x, y;
        scanf("%c%d%d", &c, &x, &y);
        val[c - 'a'] = min(x, y);
    }
    for(int j = 1; j < m; j++)
        for(int i = 0; i < m && i + j < m; i++)
        {
            if(s[i] == s[i + j])
                dp[i][i + j] = dp[i + 1][i + j - 1];
            else
                dp[i][i + j] = min(dp[i][i + j - 1] + val[s[i + j] - 'a'], dp[i + 1][i + j] + val[s[i] - 'a']);
        }
    printf("%d\n", dp[0][m - 1]);
    return 0;
}
