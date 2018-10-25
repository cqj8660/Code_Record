#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
const int maxn = 1e5 + 10;
using namespace std;
pair<int, int> q[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int x, y;
    cin >> x >> y;
    q[0] = make_pair(0, 0);
    if(s[0] == 'R')
        q[0].se++;
    else if(s[0] == 'L')
        q[0].se--;
    else if(s[0] == 'U')
        q[0].fi++;
    else
        q[0].fi--;
    for(int i = 0; i < n; i++)
    {
        switch(s[i])
        {
        case 'R':
            q[i] = make_pair(q[i - 1].fi, q[i - 1].se + 1);
            break;
        case 'L':
            q[i] = make_pair(q[i - 1].fi, q[i - 1].se - 1);
            break;
        case 'U':
            q[i] = make_pair(q[i - 1].fi + 1, q[i - 1].se);
            break;
        case 'D':
            q[i] = make_pair(q[i - 1].fi - 1, q[i - 1].se);
            break;
        }
    }
    if(q[n - 1].fi == x && q[n - 1].se == y)
    {
        cout << 0 << endl;
        return 0;
    }
    int l = 0, r = 0, ans = -1;
    while(i <= j && j < n)
    {

    }
    cout << endl;
    return 0;

}
