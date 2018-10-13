#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int cnt = 0;
        int L, v, l, r;
        cin >> L >> v >> l >> r;
//        for(int i = 1; i < l; i++)
//            if(i % v == 0)cnt++;
        cnt += L / v;
        cnt -= (r / v - (l - 1) / v);
//        for(int i = r + 1; i <= L; i++)
//            if(i % v == 0)cnt++;
        cout << cnt << endl;
    }
    return 0;
}
