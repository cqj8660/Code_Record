#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;
const int maxn = 1e3 + 10;
int s[maxn], p[maxn];
int Next[maxn];
int n, m;
void get_next()
{
    int i = 1, j = 0;
    Next[0] = 0;
    while(i < m)
    {
        if(p[i] == p[j])
        {
            Next[i] = j + 1;
            i++;
            j++;
        }
        else
        {
            if(j == 0)
            {
                Next[i] = 0;
                i++;
            }
            else
                j = Next[j - 1];
        }
    }
}
int main()
{
    //    freopen("/Users/vector/Desktop/testdata.in", "r", stdin);
    int cas;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++)
            scanf("%d", s + i);
        for(int i = 0; i < m; i++)
            scanf("%d", p + i);
        get_next();
        int loc = -1;
        int i = 0, j = 0;
        while(i <= n)
        {
            if(j == m)
            {
                loc = i - m + 1;
                break;
            }
            if(s[i] == p[j])
            {
                i++;j++;
            }
            else
            {
                if(j == 0)
                    i++;
                else
                    j = Next[j - 1];
            }
        }
        printf("%d\n", loc);
    }
    
    return 0;
}
