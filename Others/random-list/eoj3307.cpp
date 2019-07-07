#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 10;
int a[maxn];
int belong[maxn], l[maxn], r[maxn];
map<int, int> mp[2000];
map<int, int> uu[2000];
map<int, int> app;
int main()
{
    int n, q;
    //freopen("C:\\Users\\cqj86\\Desktop\\in.txt", "r", stdin);
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int block = sqrt(n);
    int num = n / block;
    if(n % block)
        num++;
    for(int i = 1; i <= n; i++)
        belong[i] = (i - 1) / block + 1;
    for(int i = 1; i <= num; i++)
    {
        l[i] = (i - 1) * block + 1;
        r[i] = i * block;
    }
    r[num] = n;
    for(int i = 1; i <= num; i++)
    {
        for(int j = l[i]; j <= r[i]; j++)
            {
                mp[i][a[j]]++;
                app[a[j]]++;
            }
        vector<int> p;
        for(auto idx: mp[i])
        if(idx.second > 2)
            {
                p.push_back(idx.first);
                uu[i][idx.first] = 1;
            }
        for(auto idx: p)
            mp[i].erase(idx);
        /*cout << i << ": \n";
        for(auto idx: mp[i])
            cout << idx.first << ' ' << idx.second << endl;
        cout << "-----------------" << endl;*/
    }
    for(int i = 1; i <= num; i++)
    {
        for(auto idx: app)
            if(idx.second == 1)
                mp[i].erase(idx.first);
    }
    while(q--)
    {
        int L, R, cnt = 0;
        scanf("%d%d", &L, &R);
        map<int, int> tm;
        map<int, int> uus;
        for(int i = L; i <= min(R, r[belong[L]]); i++)
            tm[a[i]]++;
        if(belong[L] != belong[R])
        {
            for(int i = belong[L] + 1; i < belong[R]; i++)
            {
                for(auto idx: uu[i])
                    uus[idx.first] = 1;
                for(auto idx: mp[i])
                    tm[idx.first] += idx.second;
            }
            for(int i = l[belong[R]]; i <= R; i++)
                tm[a[i]]++;
        }
        for(auto idx: tm)
            if(idx.second == 2 && !uus[idx.first])
                cnt++;
        cout << cnt << endl;
    }
    return 0;
}
