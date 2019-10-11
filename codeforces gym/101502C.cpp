#include <bits/stdc++.h>
#define lld long long
#define nmax 100005
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define INF 4000000000000000000LL
using namespace std;
int t, n, m, k, s, x;
struct el
{
    int a, b;
};
el  v[nmax];
int c[nmax], d[nmax];
int minn[nmax];
bool cmp(const el&x, const el&y)
{
    return x.b < y.b;
}
bool ok (lld maxS)
{
    lld rmn, rms;
    for (int i=0; i<=k; ++i)
    {
        if (d[i] > s) continue;
        rms = s - d[i];
        if (c[i] >= n) return true;
        rmn = n - c[i];
        int st = 1, dr = m, best = -1;
        while (st <= dr)
        {
            int mid = (st + dr) / 2;
            if (v[mid].b <= rms)
                st = mid + 1, best = mid;
            else dr = mid - 1;
        }
        lld curr = rmn * x;
        if (curr <= maxS) return true;
        if (best != -1)
        {
            curr = rmn * minn[best];
            if (curr <= maxS) return true;
        }
    }
    return false;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&n,&m,&k);
        scanf("%d %d",&x,&s);
        for (int i=1; i<=m; ++i)
            scanf("%d",&v[i].a);
        for (int i=1; i<=m; ++i)
            scanf("%d",&v[i].b);
        for (int i=1; i<=k; ++i)
            scanf("%d",&c[i]);
        for (int i=1; i<=k; ++i)
            scanf("%d",&d[i]);
        sort(v+1,v+m+1,cmp);
        minn[1] = v[1].a;
        for (int i=2; i<=m; ++i)
        {
            minn[i] = minn[i-1];
            if (v[i].a < minn[i])
                minn[i] = v[i].a;
        }
        lld st = 0, dr = (long long)1*n*x, ans = dr;
        while (st <= dr)
        {
            lld mid = (st + dr) / 2;
            if (ok (mid))
            {
                dr = mid-1;
                ans = mid;
            }
            else st = mid + 1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
