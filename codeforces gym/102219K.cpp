#include <bits/stdc++.h>
#define lld long long
#define nmax 100005
using namespace std;
int t, n, ans;
int a[nmax];
lld act;
int main()
{
    scanf("%d",&t);
    for (int tt=1;tt<=t;++tt)
    {
        ans = 0;
        scanf("%d",&n);
        for (int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        act = 0;
        for (int i=1;i<=n;++i)
        {
            if (a[i] <= act && act+a[i] <= 2*a[i])
            {
                ++ans;
                act += a[i];
            }
            else
            if (act < a[i])
            {
                act += a[i];
                ++ans;
            }
        }
        printf("Case #%d: %d\n", tt, ans);
    }
    return 0;
}
