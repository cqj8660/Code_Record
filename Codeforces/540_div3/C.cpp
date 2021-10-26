#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
const int maxn = 2e3 + 10;
int tim[maxn];
int ans[30][30];
set<int> q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n * n; i++)
    {
        int t;
        cin >> t;
        q.insert(t);
        tim[t]++;
    }
    if(n % 2 == 0)
    {
        for(auto idx: q)
            if(tim[idx] % 4)
            {
                cout << "NO" << endl;
                return 0;
            }
        vector<int> p;
        for(auto idx: q)
        {
            for(int i = 0; i < tim[idx] / 4; i++)
                p.push_back(idx);
        }
        int idx = 0;
        for(int i = 0; i < n / 2; i++)
            for(int j = 0; j < n / 2; j++)
                ans[i][j] = ans[i][n - 1 - j] = ans[n - 1 - i][j] = ans[n - 1 - i][n - 1 - j] = p[idx++];
        cout << "YES" << endl;
        for(int i = 0; i < n; i++, cout << endl)
            for(int j = 0; j < n; j++)
                cout << ans[i][j] << ' ';
    }
    else
    {
        int odd = 0;
        vector<int> two;
        for(auto idx: q)
            if(tim[idx] % 2)
                odd++;
        if(odd > 1)
        {
            cout << "NO" << endl;
            return 0;
        }
        for(auto idx: q)
        {
            if(tim[idx] % 2)
            {
                ans[n / 2][n / 2] = idx;
                tim[idx]--;
            }
            if(tim[idx] % 4)
            {
                two.push_back(idx);
                tim[idx] -= 2;
            }
        }
        if(two.size() > n - 1 || (n - 1 - two.size()) % 2)//如果是2的倍数超过n-1或者还差奇数个
        {
            cout << "NO" << endl;
            return 0;
        }
        if(two.size() < n - 1)//用4的整数倍的去补
            for(auto idx: q)
            {
                if(tim[idx] > 0 && tim[idx] % 4 == 0)
                {
                    int qt = tim[idx];
                    for(int i = 0; i < qt / 2 && two.size() < n - 1; i++)
                    {
                        two.push_back(idx);
                        tim[idx] -= 2;
                    }
                    if(two.size() == n - 1)
                        break;
                }
            }
        vector<int> p;
        for(auto idx: q)
        {
            if(tim[idx] % 4 == 0 && tim[idx] > 0)
                for(int i = 0; i < tim[idx] / 4; i++)
                    p.push_back(idx);
        }
        int idx = 0;
        for(int i = 0; i < n / 2; i++)
            for(int j = 0; j < n / 2; j++)
                ans[i][j] = ans[i][n - 1 - j] = ans[n - 1 - i][j] = ans[n - 1 - i][n - 1 - j] = p[idx++];
        idx = 0;
        for(int i = 0; i < n / 2; i++)
        {
            ans[n / 2][i] = ans[n / 2][n - 1 - i] = two[idx++];
            ans[i][n / 2] = ans[n - 1 - i][n / 2] = two[idx++];
        }
        cout << "YES" << endl;
        for(int i = 0; i < n; i++, cout << endl)
            for(int j = 0; j < n; j++)
                cout << ans[i][j] << ' ';
    }
    return 0;
}
