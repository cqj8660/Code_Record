#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;		
string s;
const int maxn = 2e5 + 10;
int diff[maxn];
char sample[maxn];
int n, k;
char getNext(char c)
{
	if (c == 'R')
		return 'G';
	else if (c == 'G')
		return 'B';
	return 'R';
}
int solve(char c)
{
	sample[0] = c;
	diff[0] = sample[0] != s[0];
	for (int i = 1; i < n; i++)
	{
		sample[i] = getNext(sample[i - 1]);
		diff[i] = sample[i] != s[i];
	}
	int cur = 0, res = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		cur += diff[i];
		if (i >= k)
			cur -= diff[i - k];
		if (i >= k - 1)
			res = min(res, cur);
	}
	return res;
 
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	while (q--)
	{
		cin >> n >> k >> s;
		int ans = INT_MAX, cnt = 0;
		cnt = solve('R');
		ans = min(cnt, ans);
		cnt = solve('G');
		ans = min(cnt, ans);
		cnt = solve('B');
		ans = min(cnt, ans);
		cout << ans << endl;
	}
	return 0;
}