#include <stdio.h>
#define LMAX 105
#define MAX(a,b) a>b?a:b
using namespace std;

int n, m;
int a[LMAX][LMAX];
int dp[LMAX][LMAX];
int ans;

int main()
{
    int t;
    scanf("%d",&t);
    for (int q=1;q<=t;++q)
    {
        scanf("%d %d",&n,&m);
        for (int i=1;i<=n;++i)
        {
            for (int j=1;j<=m;++j)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for (int i=1;i<=m;++i)
        {
            dp[1][i] = a[1][i];
        }
        for (int i=2;i<=n;++i)
        {
            for (int j=1;j<=m;++j)
            {
                dp[i][j] = dp[i-1][j] + a[i][j];
                int v = dp[i-1][j-1] + a[i][j];
                dp[i][j] = MAX(dp[i][j], v);
                v = dp[i-1][j+1] + a[i][j];
                dp[i][j] = MAX(dp[i][j], v);
            }
        }
        ans = dp[n][1];
        for (int i=2;i<=m;++i)
        {
            ans = MAX(ans, dp[n][i]);
        }
        printf("%d\n", ans);
        for (int i=1;i<=n;++i)
        {
            for (int j=1;j<=m;++j)
            {
                dp[i][j] = a[i][j] = 0;
            }
        }
    }
    return 0;
}
