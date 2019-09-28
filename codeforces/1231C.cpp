#include <bits/stdc++.h>
#define nmax 505
using namespace std;
int n, m, a[nmax][nmax], ans;
int main()
{
    cin>>n>>m;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            cin>>a[i][j];
    for (int i=n; i>=1; --i)
        for (int j=m; j>=1; --j)
        {
            if (!a[i][j])

                a[i][j] = min(a[i+1][j],a[i][j+1])-1;
            if (i > 1 && a[i][j] <= a[i-1][j])
            {
                cout<<"-1\n";
                return 0;
            }
            if (j > 1 && a[i][j] <= a[i][j-1])
            {
                cout<<"-1\n";
                return 0;
            }
        }
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            ans += a[i][j];
    cout<<ans<<'\n';
    return 0;
}
