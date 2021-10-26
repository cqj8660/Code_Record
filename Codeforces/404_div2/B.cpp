#include <bits/stdc++.h>
#define pii pair<int, int>
#define eps 1e-6
using namespace std;
int n, m;
int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    scanf("%d", &n);
    int a = 0, b = INT_MAX, c = 0, d = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a = max(a, x);
        b = min(b, y);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        c = max(c, x);
        d = min(d, y);
    }
    int ans = 0;
    ans = max(max(a - d, c - b), ans);
    printf("%d\n", ans);
    
}
