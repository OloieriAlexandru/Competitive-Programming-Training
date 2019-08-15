#include <bits/stdc++.h>
#define nmax 2005
using namespace std;
int n, k, anss[nmax][nmax];
int fr[nmax], lr[nmax], fc[nmax], lc[nmax], rows, cols, ans;
char ch;
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
        {
            cin>>ch;
            if (ch == 'B')
            {
                if (!fr[i]) fr[i] = j;
                lr[i] = j;
                if (!fc[j]) fc[j] = i;
                lc[j] = i;
            }
        }
    for (int i=1; i<=n; ++i)
        if (!fr[i]) ++rows;
    for (int j=1; j<=n; ++j)
        if (!fc[j]) ++cols;
    for (int j=1; j<=n-k+1; ++j)
    {
        int act = 0;
        for (int i=1; i<=k; ++i)
        {
            // calculez pentru click in [1][j], apoi fac sliding in jos
            if (!fr[i]) continue;
            if (j <= fr[i] && lr[i] <= j + k - 1) ++act;
        }
        for (int i=1;i<n-k+1;++i)
        {
            anss[i][j] = act;
            if (fr[i])
                if (j<=fr[i] && lr[i] <= j+k-1) --act;
            if (fr[i+k])
                if (j<=fr[i+k] && lr[i+k] <= j+k-1)++act;
        }
        anss[n-k+1][j] = act;
    }
    for (int i=1;i<=n-k+1;++i)
    {
        int act = 0;
        for (int j=1;j<=k;++j)
        {
            if (!fc[j]) continue;
            if (i <= fc[j] && lc[j] <= i+k-1)++act;
        }
        for (int j=1;j<n-k+1;++j)
        {
            anss[i][j] += act;
            if (fc[j])
                if (i <= fc[j] && lc[j] <= i+k-1)--act;
            if (fc[j+k])
                if (i <= fc[j+k] && lc[j+k] <= i+k-1)++act;
        }
        anss[i][n-k+1] += act;
    }
    for (int i=1;i<=n-k+1;++i)
        for (int j=1;j<=n-k+1;++j)
            ans = max(ans, anss[i][j]);
    cout<<ans+rows+cols<<'\n';
    return 0;
}
