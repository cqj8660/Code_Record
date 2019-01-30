#include <bits/stdc++.h>
#define ll long long
const int maxn = 2e5 + 10;
using namespace std;
int a[maxn];
int n, m, k;
bool C(int mid)
{
    int j = mid;
    for(int i = 0; i < m && j < n; i++)
    {
        int siz = k;
        while(siz >= a[j] && j < n)
            siz -= a[j++];
    }
    return j == n;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int l = 0, r = n;
    for(int i = 0; i < 100; i++)
    {
        int mid = (l + r) / 2;
        if(C(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << n - r << endl;
    return 0;
}
