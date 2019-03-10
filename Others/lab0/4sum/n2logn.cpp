#include <bits/stdc++.h>
#include <sys/time.h>
#define ll long long
using namespace std;
const int maxn = 1e4 + 10;
int a[maxn];
struct node{
    ll sum;
    int l, r;
    bool operator < (node p) const
    {
        if(sum == p.sum)
        {
            if(l == p.l)
                return r < p.r;
            else
                return l < p.l;
        }
        return sum < p.sum;
    }
};
vector<node> p;
vector<int> q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    struct  timeval start;
    struct  timeval end;
    unsigned long diff;
    freopen("/Users/vector/Documents/Algorithm-design/lab0/4sum/10000.in", "r", stdin);
    int n, cnt = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    gettimeofday(&start,NULL);
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
        {
            p.push_back(node{a[i] + a[j], i, j});
            q.push_back(a[i] + a[j]);
        }
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    int len = (int)q.size();
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
        {
            int temp = -a[i] - a[j];
            int pos = (int)(lower_bound(q.begin(), q.end(), temp) - q.begin());
            if(pos == n) continue;
            for(; p[pos].sum == temp && pos < len; pos++)
            {
                if(i != p[pos].l && i != p[pos].r && j != p[pos].l && j != p[pos].r)
                    cnt++;
            }
        }
    gettimeofday(&end,NULL);
    diff = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
    cout << cnt / 6 << endl;
    cout << "Time Cost: " << diff * 1.0 / 1000000 << endl;
    return 0;
}
