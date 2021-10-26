#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
struct node{
    int bea, cost;
};
vector<node> co, di;
bool cmp(node& pa, node& pb)
{
    if(pa.cost == pb.cost)
        return pa.bea > pb.bea;
    return pa.cost < pb.cost;
}
int solve(vector<node>& t, int val)
{
    sort(t.begin(), t.end(), cmp);
    vector<int> price;
    int len = (int)t.size(), rul = 0;
    for(int i = 0; i < len; i++)
    {
        rul = max(rul, t[i].bea);
        price.push_back(rul);
    }
    int ans = 0;
    for(int i = len - 1; i > 0; i--)
    {
        int l = 0, r = i;
        for(int j = 0; j < 100; j++)//二分找到cost满足条件的最大的
        {
            int mid = (l + r) / 2;
            if(t[mid].cost + t[i].cost <= val)
            {
                ans = max(ans, price[mid] + t[i].bea);
                l = mid;
            }
            else
                r = mid;
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, c, d;
    cin >> n >> c >> d;
    int mc = 0, md = 0;
    for(int i = 0; i < n; i++)
    {
        int b, m;
        char ch;
        cin >> b >> m >> ch;
        if(ch == 'C' && m <= c)
        {
            co.push_back(node{b, m});
            mc = max(mc, b);
        }
        if(ch == 'D' && m <= d)
        {
            di.push_back(node{b, m});
            md = max(md, b);
        }
    }
    if(mc == 0 || md == 0)
        mc = md = 0;
    int res = mc + md;
    res = max(res, solve(co, c));
    res = max(res, solve(di, d));
    cout << res << endl;
    return 0;
}
