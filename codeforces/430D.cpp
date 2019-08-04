#include <bits/stdc++.h>
#define nmax 1005
#define lld long long
using namespace std;
int a[nmax][nmax];
lld dp1[nmax][nmax], dp2[nmax][nmax], dp3[nmax][nmax], dp4[nmax][nmax];
lld ans, act;
int n, m;
int main()
{
    cin>>n>>m;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            cin>>a[i][j];
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            dp1[i][j] = max(dp1[i-1][j],dp1[i][j-1]) + a[i][j];
    for (int i=1; i<=n; ++i)
        for (int j=m; j>=1; --j)
            dp4[i][j] = max(dp4[i-1][j],dp4[i][j+1]) + a[i][j];
    for (int i=n; i>=1; --i)
        for (int j=1; j<=m; ++j)
            dp3[i][j] = max(dp3[i+1][j],dp3[i][j-1]) + a[i][j];
    for (int i=n; i>=1; --i)
        for (int j=m; j>=1; --j)
            dp2[i][j] = max(dp2[i+1][j],dp2[i][j+1]) + a[i][j];
    for (int i=2; i<n; ++i)
        for (int j=2; j<m; ++j)
        {
            act = dp1[i][j-1] + dp2[i][j+1] + dp3[i+1][j] + dp4[i-1][j];
            ans = max(ans, act);
            act = dp1[i-1][j] + dp2[i+1][j] + dp3[i][j-1] + dp4[i][j+1];
            ans = max(ans, act);
        }
    cout<<ans<<'\n';
    return 0;
}
