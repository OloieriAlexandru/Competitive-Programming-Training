#include <bits/stdc++.h>
#define nmax1 100005
#define nmax2 10005
#define lld long long
using namespace std;
int t, n, m, k, a[nmax2];
lld dp[nmax1], dp2[nmax1];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(dp, 0, sizeof(dp));
        memset(dp2, 0, sizeof(dp2));
        scanf("%d %d %d",&n,&m,&k);
        for (int i=1; i<=n; ++i)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        dp[0] = 1;
        for (int i=1; i<=n; ++i)
        {
            for (int j=m; j>=0; --j)
            {
                if (!dp[j]) continue;
                if (j + a[i] > m) continue;
                dp2[j+a[i]] += dp2[j];
                if (dp[j+a[i]]+dp[j] >=k)
                {
                    ++dp2[j+a[i]];
                    dp[j+a[i]] += dp[j];
                    dp[j+a[i]] %= k;
                }
                else
                    dp[j+a[i]] += dp[j];
            }
        }
        --dp[0];
        if (dp[m] >= k || dp2[m])
            printf("ENOUGH\n");
        else
            printf("%lld\n", dp[m]);
    }
    return 0;
}
