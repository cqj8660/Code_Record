#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int bit[maxn], n;
inline int lowbit(int i)
{
    return i & (-i);
}
void add(int k, int a)
{
    while(k <= n)
    {
        bit[k] += a;
        k += lowbit(k);
    }
}
int sum(int k)
{
    int res = 0;
    while(k > 0)
    {
        res += bit[k];
        k -= lowbit(k);
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for(int cas = 1; cas <= T; cas++)
    {
        memset(bit, 0, sizeof(bit));
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            int t;
            cin >> t;
            add(i, t);
        }
        string q;
        int i, j;
        cout << "Case " << cas << ":\n";
        while(cin >> q)
        {
            if(q[0] == 'E')
                break;
            cin >> i >> j;
            if(q[0] == 'A')
                add(i, j);
            else if(q[0] == 'Q')
                cout << sum(j) - sum(i - 1) << endl;
            else
                add(i, -j);
        }
    }

}
