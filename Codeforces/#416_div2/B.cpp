#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e4 + 10;
int p[maxn], q[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    while(m--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        int loc = 0;
        for(int i = l; i <= r; i++)
            if(p[i] < p[x])
                loc++;
//        cout << loc << endl;
        if(loc + l == x)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
