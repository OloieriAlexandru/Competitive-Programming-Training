#include <bits/stdc++.h>
#define nmax 1005
#define inf 1000000001
using namespace std;
int n, m, maxx, minn = inf, a[nmax][nmax];
bool ok(int val)
{
    vector<bitset<nmax>>b;
    b.resize(n);
    int f1, f2 , i, j;
    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
            if (a[i][j] >= val)
                b[i-1].set(j-1);
    for (i=0; i<n-1; ++i)
        for (j=i+1; j<n; ++j)
        {
            bitset<nmax>res = b[i]&b[j];
            f1 = res._Find_first();
            f2 = res._Find_next(f1);
            if (f1 < res.size() && f2 < res.size()) return true;
        }
    return false;
}
int main()
{
    int i, j;
    scanf("%d %d",&n,&m);
    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
        {
            scanf("%d",&a[i][j]);
            maxx = max(maxx, a[i][j]);
            minn = min(minn, a[i][j]);
        }
    int st = minn, dr = maxx, ans, mid;
    while (st <= dr)
    {
        mid = (st + dr) / 2;
        if (ok(mid))
            ans = mid, st = mid+1;
        else
            dr = mid-1;
    }
    printf("%d\n", ans);
    return 0;
}
