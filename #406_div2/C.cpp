#include <bits/stdc++.h>
#define ll long long
const int maxn = 1e5 + 10;
using namespace std;
int dp[maxn][2];
//dp[i][j]表示当前怪兽在x点 且轮到j号玩家操作
int deg[maxn][2];//存度数
vector<int> k[2];//存两个人的可走步数
struct node{
    int loc, turn, ans;
};
queue<node> Q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < 2; i++)
    {
        int t; cin >> t;
        k[i].resize(t);
        for(auto &idx: k[i])
            cin >> idx;
    }
    for(int i = 0; i < n; i++)
    {
        deg[i][0] = (int)k[0].size();
        deg[i][1] = (int)k[1].size();
    }
    memset(dp, -1, sizeof(dp));
    dp[0][1] = dp[0][0] = 0;
    Q.push({0, 0, 0});
    Q.push({0, 1, 0});
    while(Q.size())
    {
        node now = Q.front();
        Q.pop();
        int t = !now.turn;
        if(now.ans == 0)//如果当前状态是必输态
        {
            for(auto idx: k[t])
            {
                int state = (now.loc + n - idx) % n;
                if(dp[state][t] == -1)
                {
                    dp[state][t] = 1;//前一个状态是必赢态
                    Q.push(node{state, t, 1});
                }
            }
        }
        else //如果当前状态是必赢态
        {
            for(auto idx: k[t])
            {
                int state = (now.loc + n - idx) % n;
                deg[state][t]--;//度数减1 最优策略下不可能选取这一策略
                if(deg[state][t] == 0 && dp[state][t] == -1)
                {
                    dp[state][t] = 0;
                    Q.push(node{state, t, 0});
                }
            }
        }
    }
    for(int i = 0; i < 2; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(dp[j][i] == - 1)
                cout << "Loop ";
            else if(dp[j][i] == 0)
                cout << "Lose ";
            else
                cout << "Win ";
        }
        cout << endl;
    }
    return 0;
}
