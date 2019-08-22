#include <bits/stdc++.h>
#define nmax 10000005
#define lld long long
using namespace std;
lld n, x, y;
lld dp[nmax];
int main()
{
    cin>>n>>x>>y;
    dp[1] = x;
    for (int i=2; i<=n; ++i)
    {
        dp[i] = dp[i-1] + x;
        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i/2] + y);
        else
        {
            dp[i] = min(dp[i], dp[i/2] + x + y);
            if (i/2+1!=i)
                dp[i] = min(dp[i], dp[i/2+1] + x + y);
        }
    }
    cout<<dp[n]<<'\n';
    return 0;
}
