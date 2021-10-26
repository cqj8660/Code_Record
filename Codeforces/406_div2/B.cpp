#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    while(m--)
    {
        int k; cin >> k;
        map<int, int> q;
        bool f = 1;
        while(k--)
        {
            int t; cin >> t;
            q[t] = 1;
            if(q[-t]) f = 0;
        }
        if(f)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
