#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int > P;
typedef long long ll;
const int nmax=105;

int a[100000];
int n,m,k,x,y;
map<int,vector<int>> mp;

string solve1(vector<int> &v)
{
    for(int i=0; i<v.size(); i++)
    {
        for(int j=0;j<mp[v[i]].size();j++)
            if(a[mp[v[i]][j]])
                return "No";
    }
    return "Yes";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        cin>>x>>y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    for(int i=0; i<m; i++)
    {
        memset(a,0,100000 * 4);
        cin>>k;
        vector<int> v(k);
        for(int j=0; j<k; j++)
        {
            cin>>v[j];
            a[v[j]]=1;
        }
        cout<<solve1(v)<<endl;
    }
    return 0;
}
