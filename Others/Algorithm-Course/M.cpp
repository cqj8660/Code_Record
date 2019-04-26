#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
using namespace std;
const int maxn = 1e6 + 10;
vector<int> a;
map<int, vector<int> > appear;
map<int, int> cache;
priority_queue<pii> pq;

int main()
{
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        a.push_back(t);
        appear[t].push_back(i);
    }
    for(auto& idx: appear){
        reverse(idx.second.begin(), idx.second.end());
    }
    int ans = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        int tim = INT_MAX;
        appear[a[i]].pop_back();
        if(appear[a[i]].size())
            tim = appear[a[i]].back();
        if(cache[a[i]] == 1){
            pq.push(make_pair(tim, a[i]));
//            cout << "Cache hit" << endl;
        }
        else if(cnt < k){
            cache[a[i]] = 1;
            pq.push(make_pair(tim, a[i]));
            cnt++;ans++;
//            cout << "Cache miss add" << endl;
        }
        else if(appear[a[i]].size() && pq.top().first > tim){//进行替换
            cache[pq.top().second] = 0;
            cache[a[i]] = 1;
            pq.pop();
            pq.push(make_pair(tim, a[i]));
//            cout << "Cache miss replace" << endl;
            ans++;
        }
        else{
            ans++;
//            cout << "Cache miss remain still" << endl;
        }
    }
    cout << ans << endl;
    return 0;
}

