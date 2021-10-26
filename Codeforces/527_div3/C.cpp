#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
const int maxn = 1e3 + 10;
char ans[maxn];
struct node{
    string s;
    int idx;
};
node a[maxn];
int n;
bool cmp(node a, node b)
{
    return a.s.length() < b.s.length();
}
void test(string s)
{
    sort(a, a + 2 * n - 2, cmp);
    for(int i = 0; i < 2 * n - 3; i += 2)
    {
        if(a[i].s == s.substr(0, i / 2 + 1) && a[i + 1].s == s.substr(n - (i / 2 + 1)))
        {
            ans[a[i].idx] = 'P';
            ans[a[i + 1].idx] = 'S';
        }
        else if(a[i].s == s.substr(n - (i / 2 + 1)) && a[i + 1].s == s.substr(0, i / 2 + 1))
        {
            ans[a[i].idx] = 'S';
            ans[a[i + 1].idx] = 'P';
        }
        else
            return;
    }
    for(int i = 0; i < 2 * n - 2; i++)
        cout << ans[i];
    cout << endl;
    exit(0);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<string> p;
    for(int i = 0; i < 2 * n - 2; i++)
    {
        cin >> a[i].s;
        a[i].idx = i;
        if(a[i].s.length() == n - 1)
            p.push_back(a[i].s);
    }
    
    string pl = p[1][0] + p[0];
    string pr = p[0][0] + p[1];
    test(pl);
    test(pr);
//    cout << pl << endl;
//    cout << pr << endl;
    return 0;
}
