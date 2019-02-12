#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4;
struct node{
    int a, b;
};
node t[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("/Users/vector/desktop/A-small-practice.in", "r", stdin);
    freopen("/Users/vector/desktop/o.out", "w", stdout);
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++)
    {
        int n; cin >> n;
        for(int i = 0; i < n; i++)
            cin >> t[i].a >> t[i].b;
        int p; cin >> p;
        cout << "Case #" << i << ": ";
        while(p--)
        {
            int c, cnt = 0; cin >> c;
            for(int i = 0; i < n; i++)
                if(t[i].a <= c && t[i].b >= c)
                    cnt++;
            cout << cnt;
            if(p == 0)
                cout << '\n';
            else
                cout << ' ';
        }
    }
    return 0;
}
