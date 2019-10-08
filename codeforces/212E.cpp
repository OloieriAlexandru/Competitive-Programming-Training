#include <bits/stdc++.h>
#define pb push_back
#define nmax 5005
using namespace std;
int n, x, y, dp[nmax], ans[nmax];
vector<int>g[nmax];
int dfs(int k, int lst)
{
    int subtreeSize = 1;
    vector<int>v;
    for (auto x:g[k])
    {
        if (x == lst) continue;
        int curr = dfs(x, k);
        v.pb(curr);
        subtreeSize += curr;
    }
    v.pb(n-subtreeSize);
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for (auto x:v)
    {
        for (int j=n; j>=1; --j)
        {
            if(j-x<0) continue;
            dp[j] |= dp[j-x];
        }
    }
    for (int i=1; i<=n; ++i)
        ans[i] |= dp[i];
    return subtreeSize;
}
int main()
{
    scanf("%d",&n);
    for (int i=1; i<n; ++i)
    {
        scanf("%d %d",&x,&y);
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1,-1);
    int anss = 0;
    for (int i=1; i<=n; ++i)
        if (i && (n-i-1))
            anss += ans[i];
    printf("%d\n", anss);
    for (int i=1; i<=n; ++i)
        if (ans[i] && i && (n-i-1))
            printf("%d %d\n", i, n-i-1);
    return 0;
}
