#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
int n, a[nmax], ans = -2000000001, sums[nmax];
void calc(int x)
{
    for (int i=0;i<x;++i)
        sums[i] = 0;
    for (int i=1;i<=n;++i)
        sums[i%x] += a[i];
    for (int i=0;i<x;++i)
        ans = max(ans, sums[i]);
}
int main()
{
    scanf("%d",&n);
    for (int i=1; i<=n; ++i)
        scanf("%d",&a[i]);
    for (int i=1; i*i<=n; ++i)
    {
        if (n % i) continue;
        if (i >= 3)
            calc(n/i);
        if (n/i >= 3)
            calc(i);
    }
    cout<<ans<<'\n';
    return 0;
}
