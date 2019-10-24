#include <bits/stdc++.h>
#define nmax 100005
#define lld long long
using namespace std;
int n, m, a[nmax], b[nmax];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        lld ans = 0;
        int nrp = 0, nri = 0;
        cin>>n;
        for (int i=1; i<=n; ++i)
        {
            cin>>a[i];
            if (a[i]%2)++nri;
            else ++nrp;
        }
        cin>>m;
        for (int i=1; i<=m; ++i)
        {
            cin>>b[i];
            if (b[i] % 2)
                ans += nri;
            else
                ans += nrp;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
