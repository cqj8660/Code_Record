#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];
int put[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 0, cnt = 0;
    for(int i = 0; i < 2 * n; i++)
    {
        int t;
        cin >> t;
        if(put[t] == 0)
        {
            ans++;
            put[t] = 1;
        }
        else if(put[t] == 1)
        {
            ans--;
            put[t] = 2;
        }
        cnt = max(ans, cnt);
    }
    cout << cnt << endl;
    
}
