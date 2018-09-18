#include <bits/stdc++.h>
#define ll long long
const int maxn = 2e5 + 10;
int a[maxn];
using namespace std;
map<int, int> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(q[a[i]] == 1)
        {
            cout << 0 << endl;
            return 0;
        }
        q[a[i]] = 1;
    }
//    if(x == 1)
//    {
//        cout << -1 << endl;
//        return 0;
//    }
    for(int i = 0; i < n; i++)//一次
    {
        int temp = x & a[i];
        if(q[temp] == 1 && temp != a[i])
        {
            cout << 1 << endl;
            return 0;
        }
    }
    map<int, int> m;
    for(int i = 0; i < n; i++)
    {

        if(m[a[i] & x] == 1)
        {
            cout << 2 << endl;
            return 0;
        }
        m[a[i] & x] = 1;
    }
    cout << -1 << endl;
    return 0;
}
