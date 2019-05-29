#include <bits/stdc++.h>
#define pii pair<int,int>
#define nmax 6005
#define pb push_back
#define mp make_pair
using namespace std;
int dg[nmax];
int n, p[nmax];
int x, y, root;
vector<int>g[nmax];
int dp[nmax][2];
pii dfs(int act)
{
    dp[act][1] = max(p[act],0);
    dp[act][0] = 0;
    int v1 = 0;
    int v2 = 0;
    if (!g[act].size()) return mp(dp[act][1], dp[act][0]);
    for (auto x:g[act])
    {
        auto rs = dfs(x);
        v2 += max(0,max(rs.first, rs.second));
        if (rs.second >= 0)
            v1 += rs.second;
    }
    dp[act][1] += v1;
    dp[act][0] = max(v1,v2);
    return mp(dp[act][1], dp[act][0]);
}
int main()
{
    scanf("%d",&n);
    for (int i=1; i<=n; ++i)
        scanf("%d",&p[i]);
    while(scanf("%d %d",&x,&y))
    {
        if (!x && !y) break;
        ++dg[x];
        g[y].pb(x);
    }
    for (int i=1; i<=n; ++i)
        if (!dg[i])
        {
            root = i;
            break;
        }
    dfs(root);
    cout<<max(0,max(dp[root][1],dp[root][0]))<<'\n';
    return 0;
}