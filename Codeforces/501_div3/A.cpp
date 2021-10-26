#include <bits/stdc++.h>
#define ll long long
const int maxn = 1e2 + 10;
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    map<int,int> q;
    while(n--)
    {
        int l,r;
        cin >> l >> r;
        for(int i = l; i <= r; i++)
            q[i] = 1;
    }
    vector<int>ans;
    for(int i = 1; i <= m; i++)
        if(q[i] == 0)
            ans.push_back(i);
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}
