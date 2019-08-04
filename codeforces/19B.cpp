#include <bits/stdc++.h>
#define nmax 4005
#define inf 999999999999999LL
#define lld long long
using namespace std;
int n, t[nmax], c[nmax];
lld dp[nmax], ans = inf;
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>t[i]>>c[i];
        ++t[i];
    }
    for (int i=1;i<nmax;++i)
        dp[i] = inf;
    for (int i=1;i<=n;++i)
    {
        for (int j=nmax-1;j>=0;--j)
        {
            if (j-t[i] < 0) break;
            dp[j] = min(dp[j-t[i]] + c[i], dp[j]);
        }
    }
    for (int i=n;i<nmax;++i)
        ans = min(ans, dp[i]);
    cout<<ans<<'\n';
    return 0;
}
