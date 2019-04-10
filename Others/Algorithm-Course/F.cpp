#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e3 + 10;
double p[maxn], q[maxn];
double e[maxn][maxn], w[maxn][maxn];
//e[i][j]表示从ki到kj的所有结点所形成的最优二叉树的最小代价
//w[i][j]表示从ki到kj的包括虚结点的期望和
int main()
{
    int n;
    scanf("%d", &n);
    p[0] = 0;
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    for(int i = 0; i <= n; i++)
        cin >> q[i];
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            e[i][j] = INT_MAX;
    for(int i = 1; i <= n + 1; i++)
        e[i][i - 1] = w[i][i - 1] = q[i - 1];
    for(int len = 0; len < n; len++)
    {
        for(int i = 1, j = i + len; i <= n - len; i++, j++)
        {
//            cout << i << ',' << j << endl; 观察dp轨迹
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            for(int r = i; r <= j; r++)
                e[i][j] = min(e[i][j], e[i][r - 1] + e[r + 1][j] + w[i][j]);
        }
    }
    printf("%f\n", e[1][n]);
    return 0;
}
