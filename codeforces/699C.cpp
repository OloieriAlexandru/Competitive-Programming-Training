#include <bits/stdc++.h>
#define nmax 105
#define inf 999999999
using namespace std;
int dp[nmax][3];
int n, a[nmax];
int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
        cin>>a[i];
    for (int i=1; i<=n; ++i)
    {
        if (a[i] == 0)
        {
            dp[i][0] = dp[i][1] = inf;
        }
        else if (a[i] == 1)
        {
            // este un concurs
            dp[i][0] = inf; // nu pot sa ma antrenez
            dp[i][1] = dp[i-1][0];
            dp[i][1] = min(dp[i][1], dp[i-1][2]);
        }
        else if (a[i] == 2)
        {
            // e sala deschisa
            dp[i][1] = inf;
            dp[i][0] = dp[i-1][1];
            dp[i][0] = min(dp[i][0], dp[i-1][2]);
        }
        else
        {
            dp[i][0] = dp[i-1][1];
            dp[i][0] = min(dp[i][0], dp[i-1][2]);
            dp[i][1] = dp[i-1][0];
            dp[i][1] = min(dp[i][1], dp[i-1][2]);
        }
        dp[i][2] = min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2])) + 1;
    }
    int ans = dp[n][0];
    for (int i=0; i<3; ++i)
        ans = min(ans, dp[n][i]);
    cout<<ans<<'\n';
    return 0;
}
