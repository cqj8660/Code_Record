#include <bits/stdc++.h>
#define ll long long
const int maxn = 2e5 + 10;
using namespace std;
int a[maxn];
map<int, int> q;
vector<int> ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        q[a[i]]++;
    }
    int l = 1, r = n;
    for(int i = 0; i < 100; i++)
    {
        vector<int> temp;
        int mid = (l + r) >> 1;
        for(auto idx: q)
        {
            if(idx.second >= mid)
            {
                for(int j = 0; j < idx.second / mid; j++)
                    temp.push_back(idx.first);
                if(temp.size() >= k)
                    break;
            }
        }
        if(temp.size() >= k)
        {
            ans = temp;
            l = mid;
        }
        else
            r = mid;
    }
    for(int i = 0; i < k; i++)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}
