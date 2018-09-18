#include <bits/stdc++.h>
using namespace std;
int a[2000], b[2000];
bool vis[2000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    for(int i = 0; i < n; i++)
    {
        a[i] = s1[i] - '0';
        b[i] = s2[i] - '0';
    }
    sort(b, b + n);
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        int j = 0;
        for(j = 0; j < n; j++)
            if(!vis[j] && b[j] >= a[i])
            {
                vis[j] = 1;
                break;
            }
        if(j == n)
        {
            for(int j = 0; j < n; j++)
                if(!vis[j])
                {
                    vis[j] = 1;
                    break;
                }
            cnt++;
        }
    }
    cout << cnt << endl;
    cnt = 0;
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; i++)
    {
        int j = 0;
        for(j = 0; j < n; j++)
            if(!vis[j] && b[j] > a[i])
            {
                cnt++;
                vis[j] = 1;
                break;
            }
        if(j == n)
        {
            for(int j = 0; j < n; j++)
                if(!vis[j])
                {
                    vis[j] = 1;
                    break;
                }
        }
    }
    cout << cnt << endl;
}