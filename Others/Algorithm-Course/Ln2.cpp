#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
const int maxn = 1e4 + 10;
vector<pair<int, int> >a;
bool vis[maxn];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int s, t; cin >> s >> t;
        a.push_back(make_pair(t, s));
    }
    sort(a.begin(), a.end());
    int res = 0;
    vis[0] = 1;
    while (a.size()) {
        int len = (int)a.size();
        int now = a[0].first;
        vector<pair<int, int> > temp;
        for(int i = 1; i < len; i++){
            if(now <= a[i].second){
                now = a[i].first;
            }
            else
                temp.push_back(a[i]);
        }
        res++;
        a.clear();
        a.swap(temp);
    }
    cout << res << endl;
    return 0;
}

