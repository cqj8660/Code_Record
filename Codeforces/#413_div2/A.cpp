#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t, k, d;
    cin >> n >> t >> k >> d;
    int t1 = (n / k) * t;
    if(n % k) t1 += t;
    int t2, cnt = 0;
    for(t2 = 0; t2 <= 1000010; t2++)
    {
        cnt = (t2 / t) * k;
        if(t2 > d)
            cnt += ((t2 - d) / t) * k;
        if(cnt >= n)
            break;
    }
    if(t1 <= t2)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}
