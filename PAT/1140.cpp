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
#define ll long long
using namespace std;
const int maxn = 1e3 + 10;
const int maxm = 2e4 + 10;
vector<int> g[maxn];
int deg[maxn];
vector<int> seq[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int d, n;
    cin >> d >> n;
    string s = to_string(d);
    string now = "";
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < s.length(); j++)
        {
            int cnt = 1;
            now += s[j];
            while(j + 1 < s.length() && s[j + 1] == s[j])
            {
                j++;
                cnt++;
            }
            now += to_string(cnt);
        }
        s = now;
        now = "";
    }
    cout << s << endl;
	return 0;
}
