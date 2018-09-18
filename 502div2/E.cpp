#include <bits/stdc++.h>
#define ll long long
const int maxn = 5e3 + 10;
ll a[maxn];
using namespace std;
int n;
int dp[maxn][maxn];//f[i][j][0/1/2]表示前i个中，选出j个建房子，并且 i 和 i-1 的房子建造状态=0/1/2
//0表示两个都不建
//1表示i建
//2表示i - 1建
void solve(int k)
{
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int k = 1; k < (int)ceil(n / 2); k++)
    {
        cout << dp[n][k];
    }
    return 0;
}
