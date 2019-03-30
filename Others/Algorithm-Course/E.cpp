#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e3;
int a[maxn][maxn];
ll dp[100][maxn][10];
int main()
{
    int cas;
    cin >> cas;
    while(cas--)
    {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
            for(int j = 0; j <= i; j++)
            {
                cin >> a[i][j];
                if(i == n - 1)
                    dp[i][j][a[i][j] % 10] = 1;
            }
        for(int i = n - 2; i >= 0; i--)
            for(int j = 0; j <= i; j++)
                for(int k = 0; k < 10; k++)
                    dp[i][j][(k + a[i][j]) % 10] = max(dp[i + 1][j][k], dp[i + 1][j + 1][k]);
        for(int i = 9; i >= 0; i--)
            if(dp[0][0][i])
            {
                cout << i << endl;
                break;
            }
    }
}
