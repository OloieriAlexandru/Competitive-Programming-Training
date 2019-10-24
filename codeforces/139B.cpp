#include <bits/stdc++.h>
#define lld long long
#define nmax 505
#define inf 999999999999LL
#define inf2 999999999
using namespace std;
int l[nmax], w[nmax], h[nmax], l2[nmax], w2[nmax], p[nmax];
int n, m;
lld ans;
bool ok(int m, int i1, int i2)
{
    int v1 = 2*(l[i1] + w[i1]);
    int v2 = v1 / w2[i2];
    if (v1 % w2[i2]) ++v2;
    int tot = l2[i2] / h[i1];
    return 1LL * tot * m >= v2;
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>l[i]>>w[i]>>h[i];
    cin>>m;
    for (int i=1;i<=m;++i)
        cin>>l2[i]>>w2[i]>>p[i];
    for (int i=1;i<=n;++i)
    {
        lld best = inf;
        for (int j=1;j<=m;++j)
        {
            if (l2[j] < h[i]) continue;
            int st = 1;
            int dr = inf2;
            int cnt;
            while (st <= dr)
            {
                int m = (st+dr)/2;
                if (ok(m, i, j))
                {
                    cnt = m;
                    dr = m - 1;
                } else st = m + 1;
            }
            lld curr = p[j] * cnt;
            best = min(best, curr);
        }
        ans += best;
    }
    cout<<ans<<'\n';
    return 0;
}
