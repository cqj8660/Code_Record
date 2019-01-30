#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int a[maxn], b[maxn];
int n, block, num;
int belong[maxn], l[maxn], r[maxn];
int sum(int L, int R)
{
    int res = 0;
    for(int i = L; i <= min(R, r[belong[L]]); i++)
        res += a[i];
    if(R <= r[belong[L]])
        return res;
    for(int i = belong[L] + 1; i < belong[R]; i++)
        res += b[i];
    for(int i = l[belong[R]]; i <= R; i++)
        res += a[i];
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
        cin >> n;
        memset(b, 0, sizeof(b));
        block = sqrt(n);
        num = n / block;
        if(n % block)num++;
        for(int i = 1; i <= n; i++)
            belong[i] = (i - 1) / block + 1;
        for(int i = 1; i <= num; i++)
        {
            l[i] = 1 + (i - 1) * block;
            r[i] = block * i;
        }
        r[num] = n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            b[belong[i]] += a[i];
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
            {
                b[belong[i]] += j;
                a[i] += j;
            }
            else if(q[0] == 'Q')
                cout << sum(i, j) << endl;
            else
            {
                b[belong[i]] -= j;
                a[i] -= j;
            }
        }
    }

}
