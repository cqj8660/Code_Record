#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5;
vector<string> ans;
vector<string> name;
void getname()
{
    for(int i = 0; i < 26; i++)
        for(int j = 0; j < 26; j++)
        {
            string t = "A";
            t[0] += i;
            t += j + 'a';
            name.push_back(t);
        }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    getname();
    int idx = 0;
    for (int i = 1; i < m; i++)
        ans.push_back(name[idx++]);
    for (int i = m; i <= n; i++)
    {
        string t;
        cin >> t;
        if(t[0] == 'N')
            ans.push_back(ans[i - m]);
        else
            ans.push_back(name[idx++]);
    }
    for(auto idx: ans)
        cout << idx << ' ';
    cout << endl;
    return 0;
}
