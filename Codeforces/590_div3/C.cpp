#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 10;
string graph[2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--)
    {
        int n;
        cin >> n;
        cin >> graph[0];
        cin >> graph[1];
        int x = 0, y = 0;
        string dir = "";
        if(graph[0][0] <= '2')
        {
            y = 1;
            dir = "right";
        }
        else
        {
            x = 1;
            dir = "down";
        }
        while(x >= 0 && x < 2 && y >= 0 && y < n)
        {
            if(dir[0] == 'r')
            {
                if(graph[x][y] <= '2')
                {
                    y++;
                }
                else
                {
                    if(x == 0)
                    {
                        x++;
                        dir = "down";
                    }
                    else
                    {
                        x--;
                        dir = "up";
                    }
                }
            }
            else if(dir[0] == 'd')
            {
                if(graph[x][y] <= '2')
                {
                    x++;
                }
                else
                {
                    y++;
                    dir = "right";
                }
            }
            else
            {
                if(graph[x][y] <= '2')
                {
                    x--;
                }
                else
                {
                    y++;
                    dir = "right";
                }
            }
        }
        if(x == 1 && y == n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
