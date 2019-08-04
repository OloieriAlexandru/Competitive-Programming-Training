#include <bits/stdc++.h>
#define nmax 200005
#define lld long long
using namespace std;
int n, d[nmax];
lld h, tot;
lld ok(lld x)
{
    lld sc = x-1;
    lld rm = n;
    lld hp = h + 1LL * sc * tot;
    if (hp<=0)return sc * n;
    for (int i=1; i<=rm; ++i)
    {
        hp += d[i];
        if (hp<=0) return sc * n + i;
    }
    return 0;
}
int main()
{
    scanf("%lld %d",&h,&n);
    for (int i=1; i<=n; ++i)
    {
        scanf("%d",&d[i]);
        tot += d[i];
        if (h + tot <= 0)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    if (tot>=0)
    {
        printf("-1\n");
        return 0;
    }
    lld st = 1, dr = h/(-tot) + 1, m, ans = 2000000000000000005;
    while (st <= dr)
    {
        m = (st + dr) / 2;
        lld minute = ok(m);
        if (minute)
        {
            ans = min(ans, minute);
            dr = m-1;
        }
        else st = m + 1;
    }
    cout<<ans<<'\n';
    return 0;
}
