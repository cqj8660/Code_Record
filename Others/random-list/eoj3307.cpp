#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 10;
int a[maxn];
int belong[maxn], l[maxn], r[maxn];
map<int, int> mp[2000];
int main()
{
    int n, q;
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

    }
    while(q--)
    {
        int L, R, cnt = 0;
        scanf("%d%d", &L, &R);
        map<int, int> mp;
        for(int i = L; i <= R; i++)
            mp[a[i]]++;
        for(auto idx: mp)
            if(idx.second == 2)
                cnt++;
        cout << cnt << endl;
    }
    return 0;
}
