#include <bits/stdc++.h>
#define lld long long
#define nmax 25005
#define nmax2 31
#define inf 1000000000000000LL;
using namespace std;
int t, n, m;
int a[nmax][nmax2], b[nmax][nmax2];
lld dp1[nmax][nmax2], dp2[nmax][nmax2];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=m; ++j)
                scanf("%d",&a[i][j]);
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=m-1; ++j)
                scanf("%d",&b[i][j]);
        for (int i=2; i<=m; ++i)
            dp2[1][i] = b[1][i-1] + dp2[1][i-1];
        for (int i=2; i<=n; ++i)
        {
            for (int j=1; j<=m; ++j)
                dp1[i][j] = dp1[i-1][j] + a[i-1][j], dp2[i][j] = dp2[i-1][j];
            for (int j=2; j<=m; ++j)
                if (dp1[i][j] > dp1[i][j-1])
                    dp1[i][j] = dp1[i][j-1], dp2[i][j] = dp2[i][j-1] + b[i][j-1];
                else if (dp1[i][j] == dp1[i][j-1] && dp2[i][j-1] + b[i][j-1] < dp2[i][j])
                    dp2[i][j] = dp2[i][j-1] + b[i][j-1];
            for (int j=m-1; j>=1; --j)
                if (dp1[i][j] > dp1[i][j+1])
                    dp1[i][j] = dp1[i][j+1], dp2[i][j] = dp2[i][j+1] + b[i][j];
                else if (dp1[i][j] == dp1[i][j+1] && dp2[i][j+1] + b[i][j] < dp2[i][j])
                    dp2[i][j] = dp2[i][j+1] + b[i][j];
        }
        for (int i=1; i<=m; ++i)
            dp1[n+1][i] = dp1[n][i] + a[n][i], dp2[n+1][i] = dp2[n][i];
        lld ans1 = inf;
        lld ans2 = inf;
        for (int i=1; i<=m; ++i)
            if (dp1[n+1][i] < ans1)
                ans1 = dp1[n+1][i], ans2 = dp2[n+1][i];
            else if (dp1[n+1][i] == ans1 && dp2[n+1][i] < ans2)
                ans2 = dp2[n+1][i];
        cout<<ans1<<' '<<ans2<<'\n';
    }
    return 0;
}
