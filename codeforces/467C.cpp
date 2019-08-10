#include <bits/stdc++.h>
#define nmax 5005
#define lld long long
using namespace std;
int n, m, k, a[nmax];
lld ans, dp[nmax][nmax], sum[nmax];
int main()
{
    cin>>n>>m>>k;
    for (int i=1;i<=n;++i)
        cin>>a[i], sum[i] = sum[i-1] + a[i];
    for (int i=1;i<=k;++i)
    {
        for (int j=1;j<=n;++j)
        {
            if (i * m > j) continue;
            dp[i][j] = max(dp[i][j-1],dp[i-1][j-m] + sum[j] - sum[j-m]);
        }
    }
    cout<<dp[k][n]<<'\n';
    return 0;
}
