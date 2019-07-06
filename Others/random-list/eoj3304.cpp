#include <bits/stdc++.h>
const int maxn = 2e5 + 10;
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 1;
#define se second
#define fi first
using namespace std;
vector<pair<int, int> > a;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        cin >> s;
        int c;
        cin >> c;
        if(s.length() == 1)
            if(s[0] == '<')
                a.push_back({c, 1});
            else if(s[0] == '=')
                a.push_back({c, 3});
            else
                a.push_back({c, 4});
        else if(s[0] == '<')
            a.push_back({c, 2});
        else
            a.push_back({c, 5});
    }
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        int temp = 1, val;
        if(a[i].se == 2 || a[i].se == 3 || a[i].se == 5)
            val = a[i].fi;
        else if(a[i].se == 1)
            val = a[i].fi - 1;
        else
            val = a[i].fi + 1;
        for(int j = 0; j < n; j++)
        {
            if(j == i) continue;
            if(a[j].second == 1 && a[j].first > a[i].first)
                temp++;
            if(a[j].second == 2 && a[j].first >= a[i].first)
                temp++;
            if(a[j].second == 4 && a[j].first < a[i].first)
                temp++;
            if(a[j].second == 5 && a[j].first <= a[i].first)
                temp++;
        }
        cnt = max(temp, cnt);
    }
    cout << cnt << endl;
    return 0;
}

