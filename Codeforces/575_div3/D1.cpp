#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;		
string s;
const int maxn = 1e5 + 10;
char getNext(char c)
{
	if (c == 'R')
		return 'G';
	else if (c == 'G')
		return 'B';
	return 'R';
}
int solve(int i, int k)
{
	int cnt = 0;
	char c = s[i];
	for (int j = 1; j < k; j++)
	{
		if (s[i + j] != getNext(c))
			cnt++;
		c = getNext(c);
	}
	return cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	while (q--)
	{
 
		int n, k;
		cin >> n >> k >> s;
		int ans = INT_MAX;
		for (int i = 0; i <= n - k; i++)
		{
			char ori = s[i];
			int cnt = 1;
			s[i] = 'R';
			cnt += solve(i, k);
			if (s[i] == ori)
				cnt--;
			ans = min(ans, cnt);
 
			cnt = 1;
			s[i] = 'G';
			cnt += solve(i, k);
			if (s[i] == ori)
				cnt--;
			ans = min(ans, cnt);
 
			cnt = 1;
			s[i] = 'B';
			cnt += solve(i, k);
			if (s[i] == ori)
				cnt--;
			ans = min(ans, cnt);
 
			s[i] = ori;
 
		}
		cout << ans << endl;
 
	}
	return 0;
}