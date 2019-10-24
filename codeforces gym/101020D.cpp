#include <bits/stdc++.h>
#define nmax 20005
using namespace std;
int t, maxx, x, a[nmax], ans, n;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        maxx = -1;
        ans = -1;
        for (int i=1; i<=n; ++i)
        {
            scanf("%d",&x);
            maxx = max(maxx, x);
            a[x] = a[x-1] + 1;
            ans = max(a[x], ans);
        }
        for (int i=0; i<=maxx; ++i)
            a[i] = 0;
        printf("%d\n", ans);
    }
    return 0;
}
