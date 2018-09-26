#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 10;
map<string, int> q;
struct node{
    string op;
    string a, b;
    int pa, pb;
    bool iscal;
}a[maxn];
int n, m;
int save[maxn];
int cal(int idx, int bit)
{
    int cnt = 0;
    memset(save, 0, sizeof(save));
    for(int i = 0; i < n; i++)
    {
        if(a[i].iscal) {
            save[i] = a[i].a[idx] - '0';
            continue;
        }
        int x, y;
        if(a[i].a == "?")
            x = bit;
        else
            x = save[a[i].pa];
        if(a[i].b == "?")
            y = bit;
        else
            y = save[a[i].pb];
        int res = 0;
        if(a[i].op == "XOR")
            res = x xor y;
        else if(a[i].op == "OR")
            res = x or y;
        else
            res = x and y;
        save[i] = res;
        if(res)
            cnt++;
    }
    return cnt;
}
char mini[1200], maxi[1200];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
//    freopen("/Users/vector/Desktop/in", "r", stdin);
    cin >> n >> m;
    cin.get();
    for (int i = 0; i < n; i++)
    {
        string var;
        getline(cin, var);
        stringstream sin = stringstream(var);
        string t;
        vector<string> s;
        while(sin >> t)
            s.push_back(t);
        q[s[0]] = i;
        a[i].a = s[2];
        a[i].iscal = 1;
        if(s.size() > 3)
        {
            a[i].op = s[3];
            a[i].pa = q[a[i].a];
            a[i].b = s[4];
            a[i].pb = q[a[i].b];
            a[i].iscal = 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int a = cal(i, 0);
        int b = cal(i, 1);
        if(a > b)
        {
            mini[i] = '1';
            maxi[i] = '0';
        }
        else if(a < b)
        {
            mini[i] = '0';
            maxi[i] = '1';
        }
        else
        {
            mini[i] = '0';
            maxi[i] = '0';
        }
    }
    cout << mini << endl;
    cout << maxi << endl;
    return 0;
}
