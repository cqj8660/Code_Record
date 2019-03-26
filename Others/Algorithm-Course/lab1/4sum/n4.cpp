#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
const int maxn = 1e4 + 10;
int a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    struct  timeval start;
    struct  timeval end;
    unsigned long diff;
    freopen("/Users/vector/Documents/Algorithm-design/lab0/4sum/300.in", "r", stdin);
    int n, cnt = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    gettimeofday(&start,NULL);
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            for(int k = j + 1; k < n; k++)
                for(int l = k + 1; l < n; l++)
                    if(a[i] + a[j] + a[k] + a[l] == 0)
                        cnt++;
    gettimeofday(&end,NULL);
    diff = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
    cout << cnt << endl;
    cout << "Time Cost: " << diff * 1.0 / 1000000 << endl;
    return 0;
}
