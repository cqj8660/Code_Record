#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > p;
bool cmp(vector<int>& pa, vector<int> & pb){
    int len = pa.size();
    int ind = 0;
    while(ind < len && pa[ind] == pb[ind])
        ind++;
    return pa[ind] < pb[ind];
}
int comp(vector<int>& pa, vector<int>& pb)
{
    int len = pa.size();
    for(int i = 0; i < len; i++)
        if(pa[i] <= pb[i])
        return -1;
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, d;
    cin >> n >> d;
    int dp[n + 10] ={};
    p.resize(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < d; j++){
            int t; cin >> t;
            p[i].push_back(t);
        }
    }
    for(auto& idx: p)
        sort(idx.begin(), idx.end());
    sort(p.begin(), p.end(), cmp);
    for(int i = 0; i < n; i++)
        dp[i] = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = i - 1; j >= 0; j--)
        {
            int res = comp(p[i], p[j]);
            if(res > 0)
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    cout << *max_element(dp, dp + n) << endl;
    return 0;
}

