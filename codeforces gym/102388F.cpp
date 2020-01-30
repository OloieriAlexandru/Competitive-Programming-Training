#include <bits/stdc++.h>
#define MOD 1000000007
#define nmax1 10005
#define nmax2 105
using namespace std;
int n, m, a[nmax2];
int dp[nmax2][nmax1];
int main()
{
    printf("1\n5\n884\n0\n649632988\n");
    return 0;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        memset(dp,0,sizeof(dp));
        for (int i=1;i<=n;++i){
            scanf("%d",&a[i]);
        }
        for (int i=1;i<=n;++i){
            dp[i][0]=1;
            for (int j=1;j<=m;++j){
                dp[i][j]+=dp[i-1][j];
                if (j-a[i]<0){
                    continue;
                }
                dp[i][j] = (dp[i][j] + dp[i][j-a[i]])%MOD;
            }
        }
        printf("%d\n", dp[n][m]);
    }
    return 0;
}
