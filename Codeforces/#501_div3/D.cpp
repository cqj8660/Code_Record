#include <bits/stdc++.h>
#define ll long long
const int maxn = 1e5 + 10;
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k, s;
    cin >> n >> k >> s;
    vector<ll> ans;
    if(s >= k && s <= (n - 1) * k)
    {
        cout << "YES" << endl;
        ll t = s;
        int flag = 1;
        while(t > (n - 1) && t >= k + n - 1)
        {
            if(flag)
                ans.push_back(n);
            else
                ans.push_back(1);
            flag = !flag;
            t -= (n - 1);
            k--;
        }
        if(t != 0)
        {
            if(flag)
            {
                int tt = 1;
                for(int i = 1; i <= k - 1; i++)
                {
                    ans.push_back(tt + 1);
                    tt = !tt;
                    t--;
                }
                if(tt)
                {
                    ans.push_back(t + 1);
                  //  cout << t + 1 << endl;
                }

                else
                {
                    if(t + 2 <= n)
                        ans.push_back(t + 2);
                    else
                    {
                        ans.back() = n;
                        ans.push_back(n - (t - n + 2));
                    }
                }

            }
            else
            {
                int tt = 1;
                for(int i = 1; i <= k - 1; i++)
                {
                    ans.push_back(n - tt);
                    tt = !tt;
                    t--;
                }
                if(tt){
                    ans.push_back(n - t);
//                    cout << n - t << endl;
                }
                else{
//                    cout << n - 1 - t << endl;
                    ans.push_back(n - 1 - t);
                }
            }
        }
        for(auto idx : ans)
            cout << idx << ' ' ;
        
        
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}
