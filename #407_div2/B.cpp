#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<ll, int> g;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll b, q, l, m;
    cin >> b >> q >> l >> m;
    if(abs(b) > l)
    {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < m; i++)
    {
        int m; cin >> m;
        g[m] = 1;
    }
    if(q == 0 || b == 0)
    {
        if(g[0]){
            if(g[b])
                cout << 0 << endl;
            else
                cout << 1 << endl;
        }
        else
            cout << "inf" << endl;
        return 0;
    }
    if(q == 1)
    {
        if(g[b] == 0)
            cout << "inf" << endl;
        else
            cout << 0 << endl;
        return 0;
    }
    if(q == -1)
    {
        if((g[b] == 0 ||  g[-b] == 0))
            cout << "inf" << endl;
        else
            cout << 0 << endl;
        return 0;
    }
    int size = !g[b];//判断第一位是不是存在于序列中
    while(abs(b * q) <= l)
    {
        b *= q;
        if(g[b] == 0)
            size++;
    }
    cout << size << endl;
    return 0;
}
