#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> sta;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int exp = 1, cnt = 0;
    for(int i = 0; i < 2 * n; i++)
    {
        string s;
        int x;
        cin >> s;
        if(s[0] == 'a')
        {
            cin >> x;
            sta.push_back(x);
        }
        else
        {
            if(sta.empty())
            {
                exp++;
                continue;
            }
            if(sta.back() == exp++)
                sta.pop_back();
            else
            {
                cnt++;
                sta.clear();
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
