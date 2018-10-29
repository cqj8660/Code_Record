#include <bits/stdc++.h>
#define ll long long
const int maxn = 2e3 + 10;
using namespace std;
int n, m;
char g[maxn][maxn];
struct node{
    int x, y;
    int ri, le;
};
int vis[maxn][maxn];
int px[] = {0, 1, 0, -1};
int py[] = {1, 0, -1, 0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int r, c, x, y, cnt = 0;
    cin >> r >> c >> x >> y;
    for(int i = 1; i <= n; i++)
        cin >> (g[i] + 1);
    deque<node> q;
    q.push_front(node{r, c, y, x});
    vis[r][c] = 1;
    while(q.size())
    {
        node now = q.front();
        q.pop_front();
        for(int i = 0; i < 4; i++)
        {
            int dx = px[i] + now.x, dy = py[i] + now.y;
            if(i == 0 && now.ri < 1) continue;//向右走
            if(i == 2 && now.le < 1) continue;//向左走
            if(dx > 0 && dx <= n && dy > 0 && dy <= m)
                if(!vis[dx][dy] && g[dx][dy] == '.')
                {
                    vis[dx][dy] = 1;
                    if(i == 0)
                        q.push_back(node{dx, dy, now.ri - 1, now.le});
                    else if(i == 2)
                        q.push_back(node{dx, dy, now.ri, now.le - 1});
                    else
                        q.push_front(node{dx, dy, now.ri, now.le});
                }
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(vis[i][j])cnt++;
    cout << cnt << endl;
    return 0;

}
