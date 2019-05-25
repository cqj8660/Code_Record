#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int T[maxn][maxn];
bool vis[maxn][maxn];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        T[i][i] = 1;
    int cnt = n;
    while(m--){
        int u, v;
        scanf("%d%d", &u, &v);
        for(int i = 1; i <= n; i++)
            if(T[i][u] && T[i][v] == 0)
            {
                for(int j = 1; j <= n; j++)
                    if(T[v][j] == 1 && !T[i][j])
                    {
                        cnt++;
                        T[i][j] = 1;
                    }
            }
        printf("%d\n", cnt);
    }
    return 0;
}

