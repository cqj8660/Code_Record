#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
const int maxn = 2e5 + 10;
ll a[maxn];
ll pre[maxn], suf[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
    {
        if(i == 0 || i == 1)
            pre[i] = a[i];
        else
            pre[i] = a[i] + pre[i - 2];
    }
    for(int i = n - 1; i >= 0; i--)
    {
        if(i == n - 1 || i == n - 2)
            suf[i] = a[i];
        else
            suf[i] = suf[i + 2] + a[i];
    }
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        ll aa = pre[i] - a[i] + suf[i + 1], bb;
        if(i == 0)
          bb = suf[i] - a[i];
        else
        bb = pre[i - 1] + suf[i] - a[i];
        if(aa == bb)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}
