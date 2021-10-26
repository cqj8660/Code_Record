#include <bits/stdc++.h>
#define ll long long
const int maxn = 1e2 + 10;
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    string t1 = s, t2 = t;
    sort(t1.begin(), t1.end());
    sort(t2.begin(), t2.end());
    if(t1 != t2)
    {
        cout << -1 << endl;
        return 0;
    }
    int flag = 1;
    vector<int> ans;
    for(int i = n - 1; i >= 0; i--)
    {
        if(s[i] == t[i])
            continue;
        int j;
        for(j = i ; j >= 0; j--)
        {
            if(s[j] == t[i])
            {
                for(int k = j; k < i; k++)
                {
                    ans.push_back(k + 1);
                    char c = s[k];
                    s[k] = s[k + 1];
                    s[k + 1] = c;
                }
                break;
            }
        }
        if(j == -1)
        {
            flag = 0;
            break;
        }
    }
    if(flag)
    {
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
    }
    else
        cout << -1 << endl;
    return 0;
}
