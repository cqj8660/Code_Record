#include <bits/stdc++.h>
#define vi vector<int>
#define ll long long
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];
ll ans;
int n, q;
int loc[maxn];
int L[maxn], R[maxn];//第i块的左边界和右边界
vector<int> blo[maxn];//每一块的各个元素
void init()
{
    int len = sqrt(n);
    int num = n / len;
    if(n % len) num++;
    for(int i = 1; i <= n; i++)
        loc[i] = (i - 1) / len + 1;
    for(int i = 1; i <= num; i++)
    {
        L[i] = (i - 1) * len + 1;
        R[i] = i * len;
    }
    for(int i = 1; i <= num; i++)
        for(int j = L[i]; j <= R[i]; j++)
            blo[i].push_back(j);
}
int query(int l, int r, int key)//查询[l, r]内小于key的元素个数
{
    if(l > r) return 0;
    int res = 0;
    if(loc[l] == loc[r])//如果在同一块内
    {
        for(int i = l; i <= r; i++)
            if(a[i] < key)
                res++;
        return res;
    }
    for(int i = l; i <= R[loc[l]]; i++)//左侧部分块内小于key的元素
        if(a[i] < key)
            res++;
    for(int i = L[loc[r]]; i <= r; i++)//右侧部分块内小于key的元素
        if(a[i] < key)
            res++;
    for(int i = loc[l] + 1; i < loc[r]; i++)//整块处理部分
        res += upper_bound(blo[i].begin(), blo[i].end(), key) - blo[i].begin();
    return res;
}
void update(int l, int r)
{
    int u = a[l], v = a[r];
    int id = loc[l];
    swap(a[l], a[r]);
    blo[id].erase(lower_bound(blo[id].begin(), blo[id].end(), u));
    blo[id].insert(upper_bound(blo[id].begin(), blo[id].end(), v), v);
    id = loc[r];
    blo[id].erase(lower_bound(blo[id].begin(), blo[id].end(), v));
    blo[id].insert(upper_bound(blo[id].begin(), blo[id].end(), u), u);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    init();
    for(int i = 1; i <= n; i++)
        a[i] = i;
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        if(l == r)
        {
            cout << ans << endl;
            continue;
        }
        if(l > r)
            swap(l, r);
        int t1 = query(l + 1, r - 1, a[l]);//区间内比a[l]小的数
        int t2 = r - 1 - l - t1;
        ans = ans - t1 + t2;
        t1 = query(l + 1, r - 1, a[r]);//区间内比a[r]小的数
        t2 = r - 1 - l - t1;
        ans = ans - t2 + t1;
        if(a[l] < a[r]) ans++;
        else ans--;
        cout << ans << endl;
        update(l, r);
    }
    return 0;
}
