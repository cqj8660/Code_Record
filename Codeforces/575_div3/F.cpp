#include <iostream>
#include <set>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#define ll long long
using namespace std;		
string s;
const int maxn = 2e3 + 10;
const int maxm = 2e5 + 10;
ll dis[maxn][maxn];
struct node {
	int x, y, w;
	bool operator < (const node& pa) const
	{
		return w < pa.w;
	}
}a[maxm];
set<int> st;
map<int, int> mp;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
 
	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		a[i] = node{ x, y, w };
	}
	sort(a, a + m);
	for (int i = 0; i < k; i++)
	{
		st.insert(a[i].x);
		st.insert(a[i].y);
	}
	int cnt = 0;
	for (auto idx : st)
		mp[idx] = ++cnt;
	memset(dis, 0x11, sizeof(dis));
	for (int i = 0; i < maxn; i++)
		dis[i][i] = 0;
	for (int i = 0; i < k; i++)
	{
		int px = mp[a[i].x], py = mp[a[i].y];
		dis[px][py] = dis[py][px] = a[i].w;
	}
	
	for (int o = 1; o <= cnt; o++)
	{
		for (int i = 1; i <= cnt; i++)
		{
			for (int j = 1; j <= cnt; j++)
			{
				dis[i][j] = min(dis[i][o] + dis[o][j], dis[i][j]);
			}
		}
	}
	vector<ll> ans;
	for(int i = 1; i <= cnt; i++)
		for (int j = i + 1; j <= cnt; j++)
		{
			if(dis[i][j] != -1)
				ans.push_back(dis[i][j]);
		}
	sort(ans.begin(), ans.end());
	cout << ans[k - 1] << endl;
	return 0;
}