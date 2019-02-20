#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
const int maxn = 2e3 + 10;
int a[maxn];
int tim[maxn];
int cmp(int a, int b)
{
    return a < b;
}
int ans[30][30];
set<int> q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n * n; i++)
    {
        cin >> a[i];
        q.insert(a[i]);
        tim[a[i]]++;
    }
    bool f = 1;
    if(n % 2 == 0)
    {
        for(auto idx: q)
            if(tim[idx] % 4)
            {
                f = 0;
                break;
            }
        if(f == 0)
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
        {
            for(int j = 0; j < n / 2; j++)
            {
                ans[i][j] = ans[i][n - 1 - j] = ans[n - 1 - i][j] = ans[n - 1 - i][n - 1 - j] = p[idx++];
            }
        }
        cout << "YES" << endl;
        for(int i = 0; i < n; i++, cout << endl)
            for(int j = 0; j < n; j++)
                cout << ans[i][j] << ' ';
    }
    else
    {
        int odd = 0, tt = 0;
        vector<int> two;
        for(auto idx: q)
        {
            if(tim[idx] % 2)
                odd++;
            else if(tim[idx] % 4 == 2)
                tt++;
        }
        if(tt > n - 1 || odd > 1)
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
        if(two.size() > n - 1)
        {
            cout << "NO" << endl;
            return 0;
        }
        if((n - 1 - two.size()) % 2)
        {
            cout << "NO" << endl;
            return 0;
        }
        if(two.size() < n - 1)
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
        {
            for(int j = 0; j < n / 2; j++)
            {
                ans[i][j] = ans[i][n - 1 - j] = ans[n - 1 - i][j] = ans[n - 1 - i][n - 1 - j] = p[idx++];
            }
        }
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
