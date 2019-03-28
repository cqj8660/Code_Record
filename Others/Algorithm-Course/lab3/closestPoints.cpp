#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 10;
struct node{
    double x, y;
};
node a[maxn];
double cal(node i, node j)
{
    return sqrt((i.x - j.x) * (i.x - j.x) + (i.y - j.y) * (i.y - j.y));
}
bool cmpx(node& a, node& b)
{
    return a.x < b.x;
}
bool cmpy(node& a, node& b)
{
    return a.y < b.y;
}
double bruteForce(node a[], int n)
{
    double res = 1e20;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
            res = min(res, cal(a[i], a[j]));
    }
    return res;
}
double stripClosest(vector<node> strip, int size, double d)
{
    double min = d;  // Initialize the minimum distance as d
    sort(strip.begin(), strip.end(), cmpy);
    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (cal(strip[i],strip[j]) < min)
                min = cal(strip[i], strip[j]);
    return min;
}
double closest(node P[], int n)
{
    if(n <= 3)
        return bruteForce(P, n);
    int mid = n >> 1;
    node midnode = P[mid];
    double dl = closest(P, mid);
    double dr = closest(P + mid, n - mid);
    double d = min(dl, dr);
    vector<node> strip;
    for(int i = 0; i < n; i++)
    {
        if(fabs(P[i].x - midnode.x) < d)
            strip.push_back(P[i]);
    }
    return min(d, stripClosest(strip, (int)strip.size(), d));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;
    sort(a, a + n, cmpx);
    double ans;
    ans = closest(a, n);
    printf("%.2f\n", ans);
    return 0;
}
