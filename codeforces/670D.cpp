#include <bits/stdc++.h>
#define nmax 100005
#define inf 2000000000
#define lld long long
using namespace std;
int n, a[nmax], c[nmax], ans;
lld p;
bool ok(lld m)
{
    lld need = 0;
    lld curr, r, more;
    for (int i=1;i<=n;++i)
    {
        curr = a[i] / c[i];
        if (curr >= m) continue;
        more = m - curr;
        r = a[i] % c[i];
        need += (c[i] - r);
        --more;
        need += more * c[i];
        if (need > p) return false;
    }
    return need <= p;
}
int main()
{
    cin>>n>>p;
    for (int i=1;i<=n;++i)
        cin>>c[i];
    for (int i=1;i<=n;++i)
        cin>>a[i];
    lld st = 1, dr = inf;
    while (st <= dr)
    {
        lld m = (st + dr) / 2;
        if (ok(m))
        {
            ans = m;
            st = m + 1;
        } else dr = m - 1;
    }
    cout<<ans<<'\n';
    return 0;
}
