#include <bits/stdc++.h>
#define ll long long
const int maxn = 2e5 + 10;
ll a[maxn];
using namespace std;
map<ll, int> q;
ll ans;
vector<ll> p;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        q[a[i]]++;
    }
    for(auto idx: q)
        p.push_back(idx.second);
    sort(p.begin(), p.end());
    int len = (int)p.size();
    for(int i = 0; i < len; i++)
    {
        ll temp = 0;
        for(int j = 1; j <= p[i]; j++)
        {
            int k = i + 1, power = j;
            temp = j;
            while(k < len && p[k] >= 2 * power)
            {
                temp += 2 * power;
                power *= 2;
                k++;
            }
            ans = max(ans, temp);
        }
    }
    cout << ans << endl;
    return 0;
}
