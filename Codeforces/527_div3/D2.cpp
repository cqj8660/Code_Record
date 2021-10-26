#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, pre = -1, maxh = -1;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxh = max(maxh, a[i]);
    }
    vector<int> sta;
    for(int i = 0; i < n; i++)
    {
        if(sta.size() && sta.back() == a[i] && a[i] >= pre)
        {
            sta.pop_back();
            pre = a[i];
        }
        else
        {
            sta.push_back(a[i]);
            pre = -1;
        }
    }
    if(sta.empty() ||(sta.size() == 1 && sta.back() == maxh))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
