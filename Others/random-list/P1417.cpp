#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;
const int maxn = 200;
int a[maxn], b[maxn], c[maxn];
int dp[maxn][maxn];//dp[i][j]表示金钱为i时间为t时的最多个数
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, T;
    cin >> T >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    for(int i = 0; i < n; i++)
        cin >> c[i];
    
    return 0;
}
