#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> v;
map<int, int> mp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q, n;
    cin >> q;
    while(q--)
    {
        cin >> n;
        mp.clear();
        v.clear();
        for(int i = 0; i < n; i++)
        {
            int t;cin >> t;
            mp[t]++;
        }
        for(auto idx: mp)
            v.push_back(idx.second);
        sort(v.begin(), v.end());
        int ans = 0, temp = INT_MAX;
        for(int i = (int)v.size() - 1; i >= 0 && temp > 0; i--)
        {
            if(v[i] < temp)
            {
                temp = v[i];
                ans += v[i];
            }
            else
            {
                temp--;
                ans += temp;
            }
            
        }
        cout << ans << endl;
    }
    return 0;
}
