#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e3 + 10;
int a[maxn], b[maxn];
set<int> p;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    for(int i = 1; i <= n; i++)
        p.insert(i);
    vector<int> pos;
    for(int i = 0; i < n; i++)
    {
        if(a[i] != b[i])
            pos.push_back(i);
        else
        {
            p.erase(a[i]);
        }
    }
    if(pos.size() == 1)
    {
        for(int i = 0; i < n; i++)
        {
            if(i == pos[0])
                cout << *p.begin() << ' ';
            else
                cout << a[i] << ' ';
        }
    }
    else
    {
        int pa = *p.begin(), pb = *(--p.end());
        int x = pos[0], y = pos[1];
        if((a[x] == pa && b[x] != pa) || (b[x] == pa && a[x] != pa))
            if((a[y] == pb && b[y] != pb) || (a[y] != pb && b[y] == pb))
            {
                for(int i = 0; i < n; i++)
                {
                    if(i != x && i != y)
                        cout << a[i] << ' ';
                    else
                    {
                        if(pa)
                        {
                            cout << pa << ' ';
                            pa = 0;
                        }
                        else
                            cout << pb << ' ';
                    }
                }
                return 0;
            }
        for(int i = 0; i < n; i++)
        {
            if(i != x && i != y)
                cout << a[i] << ' ';
            else
            {
                if(pb)
                {
                    cout << pb << ' ';
                    pb = 0;
                }
                else
                    cout << pa << ' ';
            }
        }
    }
    cout << endl;
    return 0;
}
