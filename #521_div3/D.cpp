#include <bits/stdc++.h>
#define ll long long
const int maxn = 2e5 + 10;
using namespace std;
int a[maxn];
map<int, int> q;
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
    vector<int> temp;
    vector<int> ans;
    for(int i = 0; i < 100; i++)
    {
        ans.clear();
        int mid = (l + r) >> 1;
        for(auto idx: q)
        {
            if(idx.second >= mid)
            {
                for(int j = 0; j < idx.second / mid; j++)
                    ans.push_back(idx.first);
                if(ans.size() >= k)
                    break;
            }
        }
        if(ans.size() >= k)
        {
            temp = ans;
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    for(int i = 0; i < k; i++)
        cout << temp[i] << ' ';
    cout << endl;
    return 0;
}
