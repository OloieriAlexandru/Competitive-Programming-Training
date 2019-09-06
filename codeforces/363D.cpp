#include <bits/stdc++.h>
#define nmax 100005
#define lld long long
using namespace std;
int n, m;
lld mo[nmax], p[nmax], ans1, ans2, more, cmn;
bool ok(int cnt)
{
    more = 0;
    // cei mai bogati cnt cumpara cele mai ieftine cnt
    for (int i=1;i<=cnt;++i)
    {
        // p[i] grupez cu mo[cnt-i+1]
        if (mo[i] < p[cnt-i+1])
            more += p[cnt-i+1]-mo[i];
    }
    if (more > cmn) return false;
    lld rm = cmn - more;
    more = 0;
    for (int i=1;i<=cnt;++i)
    {
        more += p[i];
    }
    more -= cmn;
    if (more < 0) more = 0;
    return true;
}
int main()
{
    cin>>n>>m>>cmn;
    for (int i=1; i<=n; ++i)
        cin>>mo[i];
    for (int i=1; i<=m; ++i)
        cin>>p[i];
    sort(p+1,p+m+1);
    sort(mo+1,mo+n+1,[](int a, int b)
    {
        return a > b;
    });
    int st = 0, dr = min(n,m);
    while (st <= dr)
    {
        int m = (st + dr) / 2;
        if (ok(m))
        {
            ans1 = m;
            ans2 = more;
            st = m + 1;
        }
        else dr = m - 1;
    }
    cout<<ans1<<' '<<ans2<<'\n';
    return 0;
}
