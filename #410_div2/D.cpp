#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define mp make_pair
#define eps 1e-6
#define mo %= MOD
using namespace std;
const int maxn = 2e5 + 10;
struct node{
    ll a, b;
    int idx;
}p[maxn];
bool cmp(const node& a, const node& b)
{
    return a.a > b.a;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> p[i].a;
    for(int i = 1; i <= n; i++)
    {
        cin >> p[i].b;
        p[i].idx = i;
    }
    sort(p + 1, p + 1 + n, cmp);
    vector<int> ans;
    ans.push_back(p[1].idx);
    for(int i = 2; i <= n - 1; i += 2)
    {
        if(p[i].b > p[i + 1].b)
            ans.push_back(p[i].idx);
        else
            ans.push_back(p[i + 1].idx);
    }
    if(n % 2 == 0)
        ans.push_back(p[n].idx);
    cout << ans.size() << endl;
    for(auto idx: ans)
        cout << idx << ' ';
    cout << endl;
    return 0;
}
