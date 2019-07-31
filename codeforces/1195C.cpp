#include <bits/stdc++.h>
#define nmax 100005
#define lld long long
using namespace std;
lld dp[nmax][3];
int a[nmax], b[nmax], n;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for (int i=1;i<=n;++i)
        scanf("%d",&b[i]);
    dp[1][0] = a[1];
    dp[1][1] = b[1];
    dp[1][2] = 0;
    for (int i=2;i<=n;++i)
    {
        dp[i][0] = max(dp[i-1][1] + a[i], dp[i-1][2] + a[i]);
        dp[i][0] = max(dp[i][0], (lld)a[i]);
        dp[i][1] = max(dp[i-1][0] + b[i], dp[i-1][2] + b[i]);
        dp[i][1] = max(dp[i][1], (lld)b[i]);
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]);
    }
    cout<<max(dp[n][0], dp[n][1])<<'\n';
    return 0;
}
