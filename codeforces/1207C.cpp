#include <bits/stdc++.h>
#define lld long long
#define inf 99994999999979999LL
#define nmax 200005
using namespace std;
int t, n, a, b;
lld ans, dp[nmax][2];
char ch[nmax];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b;
        ans = 0;
        for (int i=0; i<=n; ++i)
            dp[i][0] = dp[i][1] = inf;
        dp[0][0] = b;
        ch[0] = '0';
        for (int i=1; i<=n; ++i)
        {
            char ccc;
            cin>>ccc;
            ch[i] = ccc;
            if (ch[i] == '1')
                dp[i][1] = dp[i-1][1] + 2 * b + a;
            else
            {
                dp[i][1] = dp[i-1][1] + 2 * b + a;
                dp[i][1] = min(dp[i][1], dp[i-1][0]+2*b+2*a);
                dp[i][0] = dp[i-1][1] + 2 * a + b;
                dp[i][0] = min(dp[i][0], dp[i-1][0] + a + b);
            }
        }
        cout<<dp[n][0]<<'\n';
    }
    return 0;
}
