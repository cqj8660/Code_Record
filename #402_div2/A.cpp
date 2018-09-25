#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e4;
int a[maxn], b[maxn];
int num[10];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int t; cin >> t;
        a[t]++;
        num[t]++;
    }
    for(int i = 0; i < n; i++)
    {
        int t; cin >> t;
        b[t]++;
        num[t]++;
    }
    for(int i = 1; i <= 5; i++)
    {
        if(num[i] % 2)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    int cnt = 0;
    for(int i = 1; i <= 5; i++)
    {
        if(2 * a[i] > num[i])
            cnt += a[i] - num[i] / 2;
    }
    cout << cnt << endl;
    return 0;
}
