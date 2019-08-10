#include <bits/stdc++.h>
#define nmax 1005
#define nmax2 28
using namespace std;
int fv[nmax][nmax2], n, m, x;
long long ans;
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;++i)
    {
        // studentul i
        for (int j=1;j<=m;++j)
        {
            char ch;
            cin>>ch;
            ++fv[j][ch-'A'];
        }
    }
    for (int i=1;i<=m;++i)
    {
        cin>>x;
        int maxx = -1;
        for (int j=0;j<26;++j)
            maxx = max(maxx, fv[i][j]);
        ans += 1LL * x * maxx;
    }
    cout<<ans<<'\n';
    return 0;
}
