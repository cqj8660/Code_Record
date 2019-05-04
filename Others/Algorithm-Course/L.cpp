#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
const int maxn = 1e4 + 10;
struct node{
    int start, end;
    bool operator < (const node& pa) const{
        return start < pa.start;//按start由大到小
    }
};
vector<node>a;
bool cmp(const node& pa, const node& pb)
{
    return pa.end < pb.end;
}
bool vis[maxn];
priority_queue<node> pq;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int s, t; cin >> s >> t;
        a.push_back(node{s, t});
    }
    sort(a.begin(), a.end(), cmp);
    int res = 1;
    pq.push(a[n - 1]);
    for(int i = n - 2; i >= 0; i--)
    {
        if(a[i].end <= pq.top().start){
            node t = pq.top();
            t.start = a[i].start;
            pq.push(t);
        }
        else{
            res++;
            pq.push(a[i]);
        }
    }
    cout << res << endl;
    return 0;
}

