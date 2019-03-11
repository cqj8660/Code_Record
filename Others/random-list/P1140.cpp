#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;
const int M = 3e2 + 10;
int dp[M][M];//dp[i][j]表示s1前i个字符和s2前j个字符的最大的相似度
int v[M][M] =
{
    {5, -1, -2, -1, -3},
    {-1, 5, -3, -2, -4},
    {-2, -3, 5, -2, -2},
    {-1, -2, -2, 5, -1},
    {-3, -4, -2, -1, 0}
};
int p[M];
int main()
{
    int len1, len2;
    string s1, s2;
    p['A'] = 0;
    p['C'] = 1;
    p['G'] = 2;
    p['T'] = 3;
    p['-'] = 4;
    cin >> len1 >> s1 >> len2 >> s2;
    dp[1][0] = v[4][p[s1[0]]];
    for(int i = 1; i < len1; i++)
        dp[i + 1][0] = dp[i][0] + v[4][p[s1[i]]];
    dp[0][1] = v[4][p[s2[0]]];
    for(int i = 1; i < len2; i++)
        dp[0][i + 1] = dp[0][i] + v[4][p[s2[i]]];
    for(int i = 0; i < len1; i++)
    {
        for(int j = 0; j < len2; j++)
        {
            int a = p[s1[i]], b = p[s2[j]];
            dp[i + 1][j + 1] = max(max(dp[i + 1][j] + v[4][b], dp[i][j + 1] + v[4][a]), dp[i][j] + v[a][b]);
        }
    }
    cout << dp[len1][len2] << endl;
    return 0;
}
