#include <bits/stdc++.h>
using namespace std;
struct node{
    string number;
    int score;
};
const int maxn = 1e4 + 10;
node a[maxn];
bool cmp(const node & pa, const node & pb)
{
    if(pa.score == pb.score)
        return pa.number < pb.number;
    return pa.score > pb.score;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].number >> a[i].score;
    }
    sort(a, a + n, cmp);
    for(int i = 1; i <= m; i++)
    {
        int type;
        string term;
        cin >> type >> term;
//        cout << "Case " << i << ": " << type << " " << term << endl;
        printf("Case %d: %d %s\n", i, type, term.c_str());
        if(type == 1)
        {
            bool flag = true;
            for(int j = 0; j < n; j++)
            {
                if(a[j].number[0] == term[0])
                {
//                    cout << a[j].number << ' ' << a[j].score << endl;
                    printf("%s %d\n", a[j].number.c_str(), a[j].score);
                    flag = false;
                }
            }
            if(flag)
                puts("NA");
//                cout << "NA" << endl;
            
        }
        else if(type == 2)
        {
            int cnt = 0, sum = 0;
            for(int j = 0; j < n; j++)
            {
                string site = a[j].number.substr(1, 3);
                if(site == term)
                {
                    cnt++;
                    sum += a[j].score;
                }
            }
            if(cnt)
            {
//                cout << cnt << " " << sum << endl;
                printf("%d %d\n", cnt, sum);
            }
            else
            {
                puts("NA");
//                cout << "NA" << endl;
            }
        }
        else
        {
            unordered_map<string, int> sites;
            for(int j = 0; j < n; j++)
            {
                string date = a[j].number.substr(4, 6);
                string site = a[j].number.substr(1, 3);
                if(date == term)
                {
                    sites[site]++;
                }
            }
            if(sites.empty())
            {
//                cout << "NA" << endl;
                puts("NA");
                continue;
            }
            vector<node> temp;
            for(auto idx: sites)
                    temp.push_back(node{idx.first, idx.second});
            sort(temp.begin(), temp.end(), cmp);
            for(auto idx: temp)
                printf("%s %d\n", idx.number.c_str(), idx.score);
//                cout << idx.number << ' ' << idx.score << endl;
        }
        
    }
    return 0;
}

