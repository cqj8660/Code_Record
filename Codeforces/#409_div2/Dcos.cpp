#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct point{
    double x, y;
}a[maxn];
point operator-(point a, point b)
{
    return point{a.x - b.x, a. y - b.y};
}
double dis(point a, point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
double operator*(point a, point b)
{
    return a.x * b.x + a.y * b.y;
}
double pointoline(point a, point b, point c)
{
    double cosine = (b - a) * (c - a) / (dis(a, b) * dis(a, c));
    double sinn = sqrt(1 - pow(cosine, 2));
    return dis(a, b) * sinn;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
//    cout << pointoline(point{0, 0}, point{1, 1}, point{1, 0});
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;
    double ans = 1e12;
    for(int i = 0; i < n; i++)
        ans = min(pointoline(a[(i - 1 + n) % n], a[i], a[(i + 1) % n]) / 2, ans);
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
