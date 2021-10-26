#include <bits/stdc++.h>
#define fi first
#define pii pair<int, int>
#define se second
#define ll long long
const int maxn = 2e3 + 10;
using namespace std;
pair<int, int> a[maxn];
vector<int> g[maxn];
vector<int> toru;
int len, ii;
bool cmp(pii a, pii b)
{
    return a.se > b.se;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, sum = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].se;
        a[i].fi = i;
        sum += a[i].se;
    }
    if(sum / 2 < n - 1)
    {
        cout << "NO" << endl;
        return 0;
    }
    sort(a + 1, a + n + 1, cmp);
    int head = a[1].fi, tail = a[1].fi, i;
    for(i = 1; i < n - 1; i++)
    {
        if(a[i + 1].se < 2)//大于2的成链
            break;
        g[a[i].fi].push_back(a[i + 1].fi);
        len++;
        tail = a[i + 1].fi;
        a[i].se--; a[i + 1].se--;
    }
    for(int j = 1; j <= i; j++)
    {
        for(int k = 0; k < a[j].se; k++)
            toru.push_back(a[j].fi);
        if(j == 1)
            toru.pop_back();
    }
    for(int j = n; j > i; j--)
    {
        if(j == n)
        {
            g[head].push_back(a[j].fi);
            len++;
        }
        else if(j == n -1)
        {
            g[tail].push_back(a[j].fi);
            len++;
        }
        else
            g[toru[ii++]].push_back(a[j].fi);
    }
    cout << "YES" << ' ' << len << endl << n - 1 << endl;
    for(int i = 1; i <= n; i++)
        for(auto idx: g[i])
            cout << i << ' ' << idx << endl;
    return 0;
}
