#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 10;
ll a[maxn];
deque<int> dq;
map<int, int> mp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    dq.clear();
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int siz = 0;
    for(int i = 0; i < n; i++)
    {
        if(mp[a[i]] == 0)
        {
            if(siz < k)
            {
                dq.push_front(a[i]);
                mp[a[i]] = 1;
                siz++;
            }
            else
            {
                int temp = dq.back();
                dq.pop_back();
                dq.push_front(a[i]);
                mp[temp] = 0;
                mp[a[i]] = 1;
            }
        }
    }
    cout << siz << endl;
    while(siz--)
    {
//        cout << dq.size() << endl;
        cout << dq.front() << ' ';
        dq.pop_front();
    }
    return 0;
}
