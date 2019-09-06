#include <bits/stdc++.h>
#define nmax 3005
#define inf 999999999
using namespace std;
int n, a[nmax], c[nmax];
int dp[nmax][3];
int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
        dp[i][1] = dp[i][2] = dp[i][3] = inf;
    for (int i=1; i<=n; ++i)
    {
        cin>>c[i];
        dp[i][1] = c[i];
    }
    for (int i=2;i<=n;++i)
    {
        int minn = inf;
        for (int j=i-1;j>=1;--j)
        {
            if (a[i] > a[j])
                minn = min(minn, dp[j][1] + c[i]);
        }
        dp[i][2] = minn;
    }
    for (int i=3;i<=n;++i)
    {
        int minn = inf;
        for (int j=i-1;j>=1;--j)
        {
            if (a[i] > a[j])
                minn = min(minn, dp[j][2] + c[i]);
        }
        dp[i][3] = minn;
    }
    int ans = inf;
    for (int i=3;i<=n;++i)
        ans = min(ans, dp[i][3]);
    if (ans == inf)
        cout<<"-1\n";
    else
        cout<<ans<<'\n';
    return 0;
}
