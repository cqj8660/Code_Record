#include <cstdio>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
#define ll long long
using namespace std;
const int maxn = 3e6 + 10;
char s[maxn][10];
int par[maxn];
void init(int n)
{
    for(int i = 0; i <= n; i++)
        par[i] = i;
}
int cal(char s1[], char s2[])
{
    int cnt = 0;
    for(int i = 0; i < 7; i++)
        if(s1[i] != s2[i])
            cnt++;
    return cnt;
}
int F(int f)
{
    if(par[f] != f)
        return par[f] = F(par[f]);
    return f;
}
void unite(int a, int b)
{
    a = F(a);
    b = F(b);
    par[a] = b;
}
struct edge{
    int a, b, v;
};
bool operator < (const edge& a, const edge& b)
{
    return a.v > b.v;
}
bool same(int a, int b)
{
    return F(a) == F(b);
}
int main()
{
    int n;
    while(scanf("%d", &n) && n)
    {
        init(n);
        priority_queue<edge> Q;
        for(int i = 0; i < n; i++)
            scanf("%s", s[i]);
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                Q.push(edge{i, j, cal(s[i], s[j])});
        int ans = 0, cnt = 0;
        while(cnt < n - 1)
        {
            edge t = Q.top();
            Q.pop();
            if(same(t.a, t.b))
                continue;
            unite(t.a, t.b);
            cnt++; ans += t.v;
        }
        printf("The highest possible quality is 1/%d.\n", ans);
    }
    return 0;
}
