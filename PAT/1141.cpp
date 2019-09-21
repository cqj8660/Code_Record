#include <iostream>
#include <set>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <cctype>
#include <unordered_map>
#define ll long long
using namespace std;
const int maxn = 1e5 + 10;
unordered_map<string, int> cnt;
unordered_map<string, double> scoreX;
struct sch
{
    string name;
    int scoreX;
    bool operator < (const sch& p)
    {
        if(scoreX == p.scoreX)
        {
            if(cnt[name] == cnt[p.name])
                return name < p.name;
            return cnt[name] < cnt[p.name];
        }
        return scoreX > p.scoreX;
    }
};
vector<sch> schs;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string id, s;
        double point;
        cin >> id >> point >> s;
        for(auto& e: s)
            e = tolower(e);
        cnt[s]++;
        if(id[0] == 'B')
            point /= 1.5;
        if(id[0] == 'T')
            point *= 1.5;
        scoreX[s] += point;
    }
    for(auto idx: scoreX)
    {
        schs.push_back(sch{idx.first, (int)idx.second});
    }
    sort(schs.begin(), schs.end());
    int index = 1;
    cout << schs.size() << endl;
    for(int i = 0; i < schs.size(); i++)
    {
        sch node = schs[i];
        if(i != 0 && node.scoreX != schs[i - 1].scoreX)
        {
            index = i + 1;
        }
        cout << index << " ";
        cout << node.name << " " << node.scoreX << " " << cnt[node.name] << endl;
    }
    return 0;
}
