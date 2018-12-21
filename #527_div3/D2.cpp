#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
const int maxn = 3e5 + 10;
int a[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> sta;
    for(int i = 0; i < n; i++)
    {
        if(sta.size() && ((sta.back() - a[i]) % 2 == 0))
            sta.pop_back();
        else
            sta.push_back(a[i]);
    }
    if(sta.size() <= 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
