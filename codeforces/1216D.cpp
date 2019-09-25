#include <bits/stdc++.h>
#define nmax 200005
#define lld long long
using namespace std;
int n, a[nmax], gc, dif, maxx;
lld ans1, ans2;
int main()
{
    scanf("%d",&n);
    for (int i=1; i<=n; ++i)
    {
        scanf("%d",&a[i]);
        maxx = max(maxx, a[i]);
    }
    gc = maxx - a[1];
    for (int i=2;i<=n;++i)
        gc = __gcd(gc, maxx - a[i]);
    for (int i=1;i<=n;++i)
    {
        dif = maxx - a[i];
        ans1 += dif / gc;
    }
    ans2 = gc;
    cout<<ans1<<' '<<ans2<<'\n';
    return 0;
}
