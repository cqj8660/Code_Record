#include <bits/stdc++.h>
#define vi vector<int>
#define eps 1e-6
using namespace std;
const int maxn = 2e3 + 10;
map<string, int> T;
pair<string, string> a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s, t;
        cin >> s >> t;
        a[i] = make_pair(s.substr(0, 3), s.substr(0, 2) + t[0]);
    }
    vector<string> ans;
    vector<int> seq;
    bool f = 1;
    for(int i = 0; i < n; i++)
    {
        if(T[a[i].second] != 1)
        {
            bool res = 1;
            for(int j = 0; j < i; j++)
            {
                if(seq[j] == 1 && ans[j] == a[i].first)
                {
                    res = 0;
                    break;
                }
            }
            if(res == 0)
            {
                f = 0;
                break;
            }
            ans.push_back(a[i].second);
            T[a[i].second] = 1;
            if(T[a[i].first] != 1)
                T[a[i].first] = 2;
            seq.push_back(2);
        }
        else
        {
            if(T[a[i].first])
            {
                f = 0;
                break;
            }
            ans.push_back(a[i].first);
            T[a[i].first] = 1;
            seq.push_back(1);
        }
        
    }
    if(f)
    {
        cout << "YES" << endl;
        for(auto idx: ans)
            cout << idx << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
