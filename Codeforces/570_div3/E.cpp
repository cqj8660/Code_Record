#include <bits/stdc++.h>
#define ll long long
using namespace std;
set<string> st;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if(k == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    int cnt = 1, cost = 0;
    int len = s.length();
    st.insert(s);
    for(int i = len - 1; i >= 0; i--)
    {
        set<string> nst;
        for(int j = 0; j <= i && cnt < k; j++)
            for(auto idx: st)
            {
                string t = idx.erase(j , 1);
                nst.insert(t);
            }
        st = nst;
        if(cnt + nst.size() >= k)
        {
            cost += (k - cnt) * (len - i);
            break;
        }
        else
        {
            cnt += nst.size();
            cost += nst.size() * (len - i);
        }
        if(i == 0)
        {
            cout << -1 << endl;
            return 0;

        }
    }
    cout << cost << endl;
    return 0;
}
